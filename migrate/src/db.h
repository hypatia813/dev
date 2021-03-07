#ifndef _MIGRATE_DB_H
#define _MIGRATE_DB_H


#include <string>

using namespace std;

class DB {
public:
  virtual int init() {return 0;}
  virtual int exit() {return 0;}
  virtual int connect() {return 0;}
  virtual int disconnect() {return 0;}
  virtual int excute(string & cmd) {return 0;}
};

class MySQL : public DB {
public:
  int init();
  int exit();
  int connect();
  int disconnect();
  int excute(string & cmd);
};


#endif
