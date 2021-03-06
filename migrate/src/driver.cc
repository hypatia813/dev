#include "driver.h"

#if 0
void execute(char *cmd, ) {
  FILE *fp;
  char line[1024] = {};

  if ((fp = popen(cmd, "r")) == NULL) {
    cout << "error" << endl;
    return;
  }
  while (fgets(line, sizeof(line)-1, fp) != NULL){
    cout << line ;
  }

  return;
}

int
RBDDriver::create_volume() {
  int rc = 0;

  return rc;
}

int
RBDDriver::handle() {
  int rc = 0;
  return rc;
}
#endif

