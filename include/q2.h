#ifndef Q2_H
#define Q2_H

#include <string>
#include <vector>

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

    std::vector<Patient> read_file(std::string filename)
    {
    }

    std::vector<Patient> sort(std::vector<Patient> patients)
    {
    }
}

#endif // Q2_H
