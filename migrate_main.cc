#include <string>
#include "manager.h"

using namespace std;

int main(int argc, char **argv)
{
  int rc = 0;
  string vm_uuid;
  bool is_ok = false;
  Logger *logger = nullptr;

  logger = Logger::get_instance();
  logger->init();

  LOG_WARN("...");
  printf("123");
  MigrateManager vm_manager;
  vm_manager.init();

  vm_manager.wait();

  vm_manager.exit();
  logger->exit();

  //wait

exit:
  return 0;
}
