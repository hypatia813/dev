#include <string>
#include "controller.h"
#include "info.h"

using namespace std;

int main()
{
  int rc = 0;
  string vm_uuid;
  bool is_ok = false;

  VMController vm_controller;
  is_ok = vm_controller.check(vm_uuid);
  rc = vm_controller.start_work(vm_uuid);
  rc = vm_controller.split_jobs(vm_uuid);
  vm_controller.dispather_jobs(vm_uuid);
  rc = vm_controller.end_work(vm_uuid);

  //wait

exit:
  return 0;
}
