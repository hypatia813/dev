#ifndef _MIGRATE_LOG_H
#define _MIGRATE_LOG_H


#include <mutex>
#include "common.h"

#if 0
#define LOG_OUT(level, ...) 
do { \
  Logger * logger = Logger->get_instance(); \
  logger->put_entry(__FILE__, __FUNC__, __LINE__, level, ...); \
}while (0)


#define LOG_ERROR(...) LOG_OUT(0, ...)
#define LOG_WARN(...) LOG_OUT(1, ...)
#define LOG_DEBUG(...) LOG_OUT(2, ...)
#define LOG_TRACE(...) LOG_OUT(3, ...)
#endif


class Logger : public Singleton<Logger> {

public:
  int init() {
    _fp = fopen("/var/log/migrate.log", "w+");
    if (_fp == NULL)
    {
      return -1;
    }
    return 0;
  }

  void exit() {
    if (_fp) {
      fflush(_fp);
      fclose(_fp);
      _fp = 0;
    }
    return;
  }

  void set_log_level(int log_level) {
    _log_level = log_level;

    return;
  }

  void set_log_size(int size) {
    _log_size = size;

    return;
  }

  void put_entry(char *file_name, int line, string buff) {
    if (_fp) {
      int len = ftell(_fp);
      if (len > _log_size) {
        //return 0;
      }

      _mutex.lock();
      fprintf(_fp, "%s, %d, %s", file_name, line, buff);
      fflush(_fp);
      _mutex.unlock();
    }

    return;
  }

private:
  int _log_level;
  int _log_size;
  FILE * _fp = nullptr;
  std::mutex _mutex;
};


#endif
