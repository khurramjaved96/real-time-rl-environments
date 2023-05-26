#include <pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include "../include/agent_interface.h"

namespace py = pybind11;

PYBIND11_MODULE(RealtimeAtari, m) {
    py::class_<RealTimeAtari>(m, "RealTimeAtari")
        .def(py::init<>())
        .def("sense", &RealTimeAtari::sense)
        .def("get_features", &RealTimeAtari::get_features)
        .def("get_reward", &RealTimeAtari::get_reward)
        .def("act", &RealTimeAtari::act);
}
