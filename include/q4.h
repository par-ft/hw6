#ifndef Q4_H
#define Q4_H

#include <vector>
#include <numeric>

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
        Vector2D pos;
        double accuracy;
    };

    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        Vector2D point;

        point = std::accumulate(sensors.begin(), sensors.end(), 0, [](const Sensor &a, const Sensor &b) -> Vector2D
                                { return Vector2D(a.pos.x * a.accuracy + b.pos.x * b.accuracy, a.pos.y * a.accuracy + b.pos.y * b.accuracy); }) /
                std::accumulate(sensors.begin(), sensors.end(), 0, [](const Sensor &a, const Sensor &b) -> double
                                { return a.accuracy + b.accuracy; });
    }
}

#endif // Q4_H
