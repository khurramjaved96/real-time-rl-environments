//
// Created by Khurram Javed on 2023-05-26.
//

#include "../include/agent_interface.h"
#include <vector>

Environment::Environment() {
  features = std::vector<float>();
  action_to_take = 0;
  reward = 0;
};

RealTimeAtari::RealTimeAtari() {
  std::cout << "Calling constructor\n";
  my_env = new ale::ALEInterface();
  my_env->setInt("random_seed", 123);
  my_env->setFloat("repeat_action_probability", 0.0);

  std::cout << "Loading rom from /data/breakout.bin" << std::endl;
  my_env->loadROM("/data/breakout.bin");

  std::cout << "Rom loaded\n";
}

void RealTimeAtari::sense() {}

void RealTimeAtari::act(int a) {}

float Environment::get_reward() { return reward; }

std::vector<float> Environment::get_features() { return features; }
