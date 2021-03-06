#ifndef _MIGRATE_NETWORK_H
#define _MIGRATE_NETWORK_H


class NetWorkStack : public Singleton<NetWorkStack> {
public:

  void init() {return;}
  void exit() {return;}

private:
  ThreadPool _pool;
};


#endif
