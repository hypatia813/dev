#ifndef _MIGRATE_ADMIN_SOCKET_H
#define _MIGRATE_ADMIN_SOCKET_H


#include "common.h"


class AdminSocket {
public:
  void init();
  void exit();
private:
  int status;
  static int server_sockfd;
  Thread _thread;
private:
  static void *entry(void *arg);
};


#endif
