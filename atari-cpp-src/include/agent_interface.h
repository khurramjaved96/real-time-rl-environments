//
// Created by Khurram Javed on 2023-05-26.
//

#ifndef ATARI_CPP_SRC_INCLUDE_AGENT_INTERFACE_H_
#define ATARI_CPP_SRC_INCLUDE_AGENT_INTERFACE_H_

#include "ale_interface.hpp"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Environment {
protected:
  int action_to_take;
  std::vector<float> features;
  float reward;
  long long int steps;

public:
  Environment();
  void virtual sense() = 0;
  std::vector<float> get_features();
  float get_reward();
  void virtual act(int a) = 0;
};

class RealTimeAtari : public Environment {
  ale::ALEInterface* my_env;

public:
  std::thread * t1;
  RealTimeAtari();
  static void loop(RealTimeAtari env);
  void sense();
  void act(int a);
};

#endif // ATARI_CPP_SRC_INCLUDE_AGENT_INTERFACE_H_
