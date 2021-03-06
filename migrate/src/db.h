#ifndef _MIGRATE_DB_H
#define _MIGRATE_DB_H


class DB : public Singleton<DB> {
public:
  virtual int init() {return 0;}
  virtual int exit() {return 0;}
  virtual int connect() {return 0;}
  virtual int disconnect() {return 0;}
};

class MySQL : public DB {
public:
  int init() {return 0;}
  int exit() {return 0;}
  int connect() {return 0;}
  int disconnect() {return 0;}
};


#endif
