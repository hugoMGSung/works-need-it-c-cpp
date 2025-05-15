#include <iostream>
#include <vector>
#include <string>
#include <tuple>

int main() 
{
    std::vector<std::tuple<std::string, int, double>> vStudents;
    
    for (auto iter = vStudents.begin(); iter != vStudents.end(); ++iter) 
    {
        // ...
    }

    return 0;
}