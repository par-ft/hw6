#ifndef Q3_H
#define Q3_H

#include <queue>

namespace q3
{
    struct Flight
    {
        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times{};
        size_t price;
    };

    struct Comparator
    {
        double operator()(const Flight &a, const Flight &b)
        {
            return (a.duration + a.connection_times + 3 * a.price) > (b.duration + b.connection_times + 3 * b.price);
        }
    };

    inline std::priority_queue<Flight, std::vector<Flight>, Comparator> gather_flights(std::string filename)
    {
        std::priority_queue<Flight, std::vector<Flight>, Comparator> flights;
        std::vector<std::string> row;
        std::string line, word;

        std::ifstream file(filename);

        while (getline(file, line))
        {
            row.clear();

            std::stringstream str(line);
            while (getline(str, word, ':'))
            {
                getline(std::stringstream(word), word, '-');
                word.erase(remove_if(word.begin(), word.end(), isspace), word.end());
                row.push_back(word);
            }

            Flight flight;
            flight.flight_number = row[1];

            size_t hours, minutes{};
            char h{};

            std::stringstream duration(row[2]);
            duration >> hours >> h >> minutes;

            flight.duration = hours * 60 + minutes;

            std::stringstream(row[3]) >> flight.connections;

            std::stringstream connection_times(row[4]);
            while (getline(connection_times, word, ','))
            {
                std::stringstream duration(word);
                duration >> hours >> h >> minutes;

                flight.connection_times += hours * 60 + minutes;
            }

            std::stringstream(row[5]) >> flight.price;

            flights.push(flight);
        }

        return flights;
    }

}

#endif // Q3_H
