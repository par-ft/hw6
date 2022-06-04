#ifndef Q2_H
#define Q2_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
namespace q2
{
    struct Patient
    {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };

    inline std::vector<Patient> read_file(std::string filename)
    {
        std::vector<Patient> patients;
        std::vector<std::string> row;
        std::string line, word;

        std::fstream file(filename, std::ios::in);
        if (file.is_open())
        {
            size_t row_num{};
            while (getline(file, line))
            {
                row.clear();

                std::stringstream str(line);
                while (getline(str, word, ','))
                    row.push_back(word);

                if (row_num == 0 || row_num == 1)
                {
                    row_num++;
                    continue;
                }

                row[0].erase(remove_if(row[0].begin(), row[0].end(), isspace), row[0].end());
                row[1].erase(remove_if(row[1].begin(), row[1].end(), isspace), row[1].end());

                Patient patient{};
                patient.name = row[0] + " " + row[1];
                std::stringstream(row[2]) >> patient.age;
                std::stringstream(row[3]) >> patient.smokes;
                std::stringstream(row[4]) >> patient.area_q;
                std::stringstream(row[5]) >> patient.alkhol;

                patients.push_back(patient);
            }
        }

        return patients;
    }

    inline std::vector<Patient> sort(std::vector<Patient> patients)
    {
    }
}

#endif // Q2_H
