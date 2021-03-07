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
  int init();
  int exit();
  void submit();
private:
  static ThreadPool _pool;
  //vector<JobInfo *> running_jobs;
private:
  static void *entry(void *arg);
};

class StateController {
public:
  int init();
  int exit();
private:
  Thread _thread;
private:
  static void *entry(void *arg);
};

class HeartBeatController {
public:
  int init() {return 0;}
  int exit() {return 0;}
};

#endif
