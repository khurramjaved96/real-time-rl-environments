from RealtimeAtari import RealTimeAtari

env = RealTimeAtari()
env.get_features()
env.get_reward()
env.sense()
env.act(1)
