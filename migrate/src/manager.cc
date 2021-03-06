#include <vector>

#include "manager.h"
#include "info.h"
#include "config.h"
#include "controller.h"
#include "log.h"
#include "db.h"
#include "common.h"
#include "network.h"


enum {
  MIGRATE_STATUS_STARTING,
  MIGRATE_STATUS_READY,
  MIGRATE_STATUS_STOPPING,
};

int
MigrateManager::init() {
  int rc = 0;

  status = MIGRATE_STATUS_STARTING;

  // 初始化条件变量
  logger = Logger::get_instance();
  logger->init();

  // 加载配置文件
  conf = Configuer::get_instance();
  conf->load("/etc/migrate.ini");

  // 初始化数据库
  db = MySQL::get_instance();
  db->init();
  db->connect();
  network->init();
  heartbeat_controller->init();
  job_controller->init();
  state_controller->init();

  // 注册型号处理函数

  status = MIGRATE_STATUS_READY;

  return rc;
}

void
MigrateManager::exit() {
  state_controller->exit();
  job_controller->exit();
  network->exit();
  db->disconnect();
  db->exit();
  status = MIGRATE_STATUS_STOPPING;
  logger->exit();

  // 删除资源

  return;
}

void MigrateManager::wait() {
  if (status < MIGRATE_STATUS_STOPPING) {
      _event.wait();
    }

  return;
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
