#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include "admin_socket.h"
#include "manager.h"

#define LOCAL_MIGRATE_SOCK_PATH "/tmp/migrate.sock"

int AdminSocket::server_sockfd = -1;

void AdminSocket::init() {
  int rc = 0;
  struct sockaddr_un servaddr;
  // 清理sock文件
  unlink(LOCAL_MIGRATE_SOCK_PATH);
  server_sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
  if (server_sockfd == -1) {
    //
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sun_family = AF_LOCAL;
  strcpy(servaddr.sun_path, LOCAL_MIGRATE_SOCK_PATH);
  rc = bind(server_sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (rc == -1) {
    //
  }

  listen(server_sockfd, 8);
  _thread.init(entry, nullptr);

  return;
}

void * AdminSocket::entry(void *) {
  int rc = 0;
  int connectfd = -1;
  struct sockaddr_un cliaddr;
  socklen_t cliaddr_length = sizeof(cliaddr);
  char recv_buff[200] = {0};
  char send_bbuf[200] = {0};
  message_t message;

  while (1) {
    connectfd = accept(server_sockfd, (struct sockaddr *)&cliaddr, &cliaddr_length);
    if (connectfd == -1) {
      //
    }

    memset(recv_buff, 0, sizeof(recv_buff));
    rc= read(connectfd, recv_buff, 200);
    if (rc > 100) {
      //
    }

    MigrateManager manager;

    rc = manager.message_paster(send_bbuf, &message);

    send(connectfd, send_bbuf, strlen(send_bbuf), 0);
    rc = manager.dispather(message.op);
    close(connectfd);
    sleep(1);
  }

  return NULL;
}

void AdminSocket::exit() {

  return;
}

