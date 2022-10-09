#include <vector>
#include "print_func.hpp"

int main()
{
    std::vector<std::string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension劳动法!"};

    for (const std::string &word : msg)
    {
        print_debug(word);
    }
    return 0;
}