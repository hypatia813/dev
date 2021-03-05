#ifndef _MIGRATE_INFO_H
#define _MIGRATE_INFO_H


#include <string>

using namespace std;


class VirturalMathineInfo {
public:
  string uuid;
};

class DiskInfo {
public:
  string uuid;
  string disk_name;
};

class JobInfo {
public:
  VirturalMathineInfo *vm;
  DiskInfo *disk;
  string id;
};


#endif
