#ifndef _MIGRATE_MANAGER_H
#define _MIGRATE_MANAGER_H


#include <string>
#include <vector>
#include <memory>
#include <mutex>

#include "info.h"
#include "config.h"
#include "controller.h"
#include "log.h"
#include "db.h"
#include "common.h"
#include "network.h"

using namespace std;

class MigrateManager {
public:
  int init();
  void wait();
  void exit();

public:
  WaitEvent _event;

private:
  Logger *logger;
  Configuer *conf;
  NetWorkStack *network;
  DB *db;
  StateController *state_controller;
  JobController *job_controller;
  HeartBeatController *heartbeat_controller;
  int status;

#if 0
  bool check(const string &vm_uuid);
  int start_work(const string &vm_uuid);
  int split_jobs(const string &vm_uuid);
  void dispather_jobs(const string &vm_uuid);
  int end_work(const string &vm_uuid);
  int show_jobs(const string &vm_uuid);

private:
  string status;

  vector<JobInfo *> append_jobs;

private:
  VirturalMathineInfo * create_vm(const string &vm_uuid);
  int get_disks(const string & vm_uuid, vector<DiskInfo *> disks);
  vector<JobInfo *> append_jobs;
#endif
};


#endif
