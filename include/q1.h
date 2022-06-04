#ifndef Q1_H
#define Q1_H

#include <functional>
#include <cmath>

namespace q1
{
    template <typename T, typename Func = std::function<T(T)>>
    inline T gradient_descent(T initial_value, T step, std::function<double(double)> func = Func{})
    {
        T h{static_cast<T>(pow(10, -7))};
        T optimum{initial_value};

        for (size_t i{}; i < 2000; i++)
            optimum -= step * (func(optimum + h) - func(optimum - h)) / (2 * h);

        return optimum;
    }
}

#endif // Q1_H
