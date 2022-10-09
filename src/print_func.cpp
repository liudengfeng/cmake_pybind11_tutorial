#include "print_func.hpp"

void print_debug(const std::string &msg)
{
    fmt::print(fg(fmt::color::dark_salmon), "{}\n", msg);
}
