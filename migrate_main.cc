#include <string>
#include "manager.h"

using namespace std;

int main(int argc, char **argv)
{
  int rc = 0;
  string vm_uuid;
  bool is_ok = false;

  MigrateManager vm_manager;
  vm_manager.init();


#if 0
  is_ok = vm_controller.check(vm_uuid);
  rc = vm_controller.start_work(vm_uuid);
  rc = vm_controller.split_jobs(vm_uuid);
  vm_controller.dispather_jobs(vm_uuid);
  rc = vm_controller.end_work(vm_uuid);
#endif

  vm_manager.wait();

  vm_manager.exit();

  //wait

exit:
  return 0;
}
