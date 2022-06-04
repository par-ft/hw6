#ifndef Q4_H
#define Q4_H

#include <vector>
#include <numeric>
#include <initializer_list>

namespace q4
{
    struct Vector2D
    {
        Vector2D() = default;
        Vector2D(double a, double b) : x{a}, y{b} {}
        double x{};
        double y{};

        Vector2D operator/(double n) { return Vector2D(x / n, y / n); }
    };

    struct Sensor
    {
        Sensor() = default;
        Sensor(double x, double y, double accuracy) : pos{Vector2D(x, y)}, accuracy{accuracy} {}
        Sensor(std::initializer_list<double> a, double accuracy) : pos{Vector2D(*a.begin(), *a.end())}, accuracy{accuracy} {}
        Vector2D pos;
        double accuracy{};
    };

    inline Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        Sensor point;

        point = std::accumulate(sensors.begin(), sensors.end(), Sensor{}, [](const Sensor &a, const Sensor &b) -> Sensor
                                { return Sensor(a.pos.x * a.accuracy + b.pos.x * b.accuracy, a.pos.y * a.accuracy + b.pos.y * b.accuracy, a.accuracy + b.accuracy); });

        return point.pos / point.accuracy;
    }
}

#endif // Q4_H
