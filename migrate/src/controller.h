#ifndef _MIGRATE_CONTROLLER_H
#define _MIGRATE_CONTROLLER_H


#include <string>
#include <vector>
#include "info.h"

using namespace std;

class VMController {
public:
  bool check(const string &vm_uuid);
  int start_work(const string &vm_uuid);
  int split_jobs(const string &vm_uuid);
  void dispather_jobs(const string &vm_uuid);
  int end_work(const string &vm_uuid);
  int show_jobs(const string &vm_uuid);

private:
  VirturalMathineInfo * create_vm(const string &vm_uuid);
  int get_disks(const string & vm_uuid, vector<DiskInfo *> disks);
  vector<JobInfo *> append_jobs;
};


class JobController {
public:
  int handle();

private:
  vector<JobInfo *> running_jobs;
};

#endif
