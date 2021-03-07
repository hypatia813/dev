#include "driver.h"

void QuemDriver::copy(DiskInfo *disk) {
}

void RBDDriver::copy(DiskInfo *disk) {
}

void RBDDriver::create(string remote_ip, string pool_name, string rbd_name) {
}

Driver * get_copy_driver(int disk_status) {
  Driver * driver = nullptr;

  if (disk_status == DISK_STATTUE_IDE) {
    driver = new RBDDriver();
  } else {
    driver = new QuemDriver();
  }
  return driver;
}

