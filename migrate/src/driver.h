#ifndef _MIGRATE_DIRVER_H
#define _MIGRATE_DIRVER_H


#include <string>

using namespace std;

class Driver : {
public:
  virtual void handle() = 0;
};

class QuemDriver : Driver {
public:
  void handle();
};

class RBDDriver : Driver {
public:
  string pool_name;
  string rbd_name;

public:
  void handle();
  void create_volume();
};

#endif
