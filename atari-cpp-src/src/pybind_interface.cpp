#include <pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include "../include/agent_interface.h"
//#include "../include/ale_interface.hpp"

namespace py = pybind11;

PYBIND11_MODULE(RealtimeAtari, m) {
    py::class_<Environment>(m, "Environment")
        //.def(py::init<>())
        .def("sense", &Environment::sense)
        .def("get_features", &Environment::get_features)
        .def("get_reward", &Environment::get_reward)
        .def("act", &Environment::act);

    py::class_<RealTimeAtari, Environment>(m, "RealTimeAtari")
        .def(py::init<>())
        .def("sense", &RealTimeAtari::sense)
        .def("loop", &RealTimeAtari::loop)
        .def("get_features", &RealTimeAtari::get_features)
        .def("get_reward", &RealTimeAtari::get_reward)
        .def("act", &RealTimeAtari::act);
}
