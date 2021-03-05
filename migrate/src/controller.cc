#include <vector>
#include "controller.h"


bool
VMController::check(const string & vm_uuid) {
  bool rc = true;
  return rc;
}

int
VMController::start_work(const string & vm_uuid) {
  int rc = 0;
  return rc;
}

int
VMController::split_jobs(const string & vm_uuid) {
  int rc = 0;

  // 从后台获取虚拟机对应的磁盘列表

  return rc;
}

void
VMController::dispather_jobs(const string & vm_uuid) {
  int rc = 0;
  return;
}

int
VMController::end_work(const string & vm_uuid) {
  int rc = 0;
  return rc;
}

int
VMController::get_disks(const string & vm_uuid, vector<DiskInfo *> disks) {
  int rc = 0;

  return rc;
}

int JobController::handle() {
  int rc = 0;

  // 从 running 队列中获取 job

  // 通过查找磁盘对应的状态

  // 自动生成目标的卷

  // 根据状态获取 后台dirver

  // 根据 dirver 执行备份命令

  // 完成回调函数
  
  return 0;
}

