#ifndef _MIGRATE_DIRVER_H
#define _MIGRATE_DIRVER_H


#include <string>
#include "info.h"

using namespace std;

class Driver {
public:
  virtual void copy(DiskInfo *disk) = 0;
};

class QuemDriver : public Driver {
public:
  void copy(DiskInfo *disk);
};

class RBDDriver : public Driver {
public:
  void copy(DiskInfo *disk);
  void create(string remote_ip, string pool_name, string rbd_name);
};

extern Driver * get_copy_driver(int disk_status);


#endif
