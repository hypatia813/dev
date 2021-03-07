#ifndef _MIGRATE_INFO_H
#define _MIGRATE_INFO_H


#include <string>

using namespace std;


class VirturalMathineInfo {
public:
  string uuid;
};

enum {
  DISK_STATTUE_IDE,
  DISK_STATTUE_USED,
};

class DiskInfo {
public:
  int status;
  string uuid;
  string disk_name;
  string tmp_disk_name;
  string pool_name;
};

class RemoteInfo {
public:
  string ip;
};

typedef struct job {
  // 虚拟机的信息
  VirturalMathineInfo *vm;
  // 磁盘的信息
  DiskInfo *disk;
  // 远端的信息
  string remote_ip;
  // 磁盘使用状态
  int status;
}job_t;



#endif
