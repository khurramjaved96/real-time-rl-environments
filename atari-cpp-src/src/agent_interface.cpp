//
// Created by Khurram Javed on 2023-05-26.
//

#include "../include/agent_interface.h"
#include <chrono>
#include <thread>
#include <vector>

Environment::Environment() {
  features = std::vector<float>();
  action_to_take = 0;
  reward = 0;
  steps = 0;
};

RealTimeAtari::RealTimeAtari() {
  std::cout << "Calling constructor\n";
  my_env = new ale::ALEInterface();
  my_env->setInt("random_seed", 123);
  my_env->setFloat("repeat_action_probability", 0.0);

  std::cout << "Loading rom from /data/breakout.bin" << std::endl;
  my_env->loadROM("../src/data/breakout.bin");

  std::cout << "Rom loaded\n";
  t1 = new std::thread(RealTimeAtari::loop, *this);
}

void RealTimeAtari::sense() {
  steps++;
  ale::ActionVect legal_actions = my_env->getLegalActionSet();
  if (steps % 100 == 0) {
    std::cout << "Steps = " << steps << std::endl;
  }
  if (my_env->game_over()) {
    my_env->reset_game();
  }
  ale::Action a = legal_actions[rand() % legal_actions.size()];
  float reward = my_env->act(a);
}

void RealTimeAtari::loop(RealTimeAtari env) {
  std::cout << "In the loop\n";
  auto start_b = chrono::steady_clock::now();
  while (true) {

    auto start = chrono::steady_clock::now();
    env.sense();

    int t = 0;
    auto end = chrono::steady_clock::now();
    while (t < 33) {
      end = chrono::steady_clock::now();
      t = int(chrono::duration_cast<chrono::milliseconds>(end - start).count());
//      std::cout << t << std::endl;
    }
    //    std::cout << t << std::endl;

    //    std::this_thread::sleep_for(std::chrono::milliseconds(t));
    if (env.steps % 100 == 0) {
      auto cur = chrono::steady_clock::now();
      std::cout << "FPS "
                << (1000.0 * env.steps) /
                       float(chrono::duration_cast<chrono::milliseconds>(
                                 cur - start_b)
                                 .count())
                << std::endl;
    }
  }
}

void RealTimeAtari::act(int a) {}

float Environment::get_reward() { return reward; }

std::vector<float> Environment::get_features() { return features; }
