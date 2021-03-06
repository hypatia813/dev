#ifndef _MIGRATE_CONTROLLER_H
#define _MIGRATE_CONTROLLER_H


#include <string>
#include <vector>
#include "info.h"
#include "log.h"
#include "db.h"
#include "common.h"

using namespace std;


class JobController {
public:
  int init() {return 0;}
  int exit() {return 0;}

private:
  //vector<JobInfo *> running_jobs;
};

class StateController {
public:
  int init() {return 0;}
  int exit() {return 0;}
};

class HeartBeatController {
public:
  int init() {return 0;}
  int exit() {return 0;}
};

#endif
