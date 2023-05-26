from RealtimeAtari import RealTimeAtari
import time

env = RealTimeAtari()
env.get_features()
env.get_reward()
env.sense()
for i in range(2000000000):
    i ** 2
env.act(1)
