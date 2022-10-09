#include <pybind11/pybind11.h>

#include "print_func.hpp"

PYBIND11_MODULE(xqlib, m)
{
  m.def("print_debug", print_debug);
}