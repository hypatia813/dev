#ifndef _MIGRATE_CONFIG_H
#define _MIGRATE_CONFIG_H


#include <string>
#include "common.h"

using namespace std;

class Configuer : public Singleton<Configuer> {
public:
  int load(const string &file_name) {return 0;}

private:
  string file_name;
  string host;
  string pass;
  string pool_name;
};


#endif
