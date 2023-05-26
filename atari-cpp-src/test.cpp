//
// Created by Khurram Javed on 2023-05-26.
//

#include "include/agent_interface.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {
  RealTimeAtari env;
  std::thread t1(RealTimeAtari::loop, env);
  t1.join();
  for(int i = 0; i < 1000; i++){
    env.act(0);
    std::cout << i << std::endl;
  }
}