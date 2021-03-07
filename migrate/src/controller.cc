#include <vector>
#include <unistd.h>
#include "controller.h"
#include "driver.h"
#include "admin_socket.h"

ThreadPool JobController::_pool;

int JobController::init() {
  int rc = 0;

  _pool.init(4, entry, nullptr);
  
  return rc;
}

int JobController::exit() {
  int rc = 0;
  
  return rc;
}

void JobController::submit() {
  return;
}

void *JobController::entry(void *arg) {

  int rc = 0;
  RBDDriver *dest_driver;
  Driver *copy_driver;
  job_t * job = nullptr;
  while(1) {
    //从队列中获取一个job
    job = _pool.dequeue();
    // 调用命令从远端执行创建目标磁盘
    dest_driver->create(job->remote_ip, job->disk->pool_name,
            job->disk->tmp_disk_name);

    copy_driver = get_copy_driver(job->disk->status);
    copy_driver->copy(job->disk);
  }

  return nullptr;
}


int StateController::init () {
  int rc = 0;
  _thread.init(entry, nullptr);
  return rc;
}

int StateController::exit() {
  int rc = 0;
  return rc;
}

void *StateController::entry(void *arg) {

  int rc = 0;
  RBDDriver *dest_driver;
  Driver *copy_driver;
  job_t * job = nullptr;
  while(1) {
    sleep(1);
  }

  return nullptr;
}


#if 0
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

int
JobController::handle() {
  int rc = 0;
  RBDDriver * dest_driver = nullptr;
  Driver *driver = nullptr;

  // 从 running 队列中获取 job

  // 通过查找磁盘对应的状态

  // 自动生成目标的卷
  //volume = dest_driver->create_volume();

  // 根据状态获取 后台dirver
  driver = driver_factory();
  driver->handle();

  // 根据 dirver 执行备份命令

  // 完成回调函数
  
  return 0;
}
#endif
