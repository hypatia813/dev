#ifndef _MIGRATE_LOG_H
#define _MIGRATE_LOG_H


#include <mutex>
#include "common.h"

enum {
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARN,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_TRACE,
};

#define LOG_OUT(level, format, ...) \
do { \
  Logger * logger = Logger->get_instance(); \
  logger->put_entry(level, __FILE__, __LINE__, format, ...); \
}while (0)


#if 0
#define LOG_ERROR(...) LOG_OUT(LOG_LEVEL_ERROR, ...)
#define LOG_WARN(...) LOG_OUT(LOG_LEVEL_WARN, ...)
#define LOG_DEBUG(...) LOG_OUT(LOG_LEVEL_DEBUG, ...)
#define LOG_TRACE(...) LOG_OUT(LOG_LEVEL_TRACE, ...)
#else
#define LOG_ERROR printf
#define LOG_WARN printf
#define LOG_DEBUG printf
#define LOG_TRACE printf
#endif


class Logger : public Singleton<Logger> {
public:
  int init();
  void exit();
  void set_log_level(int log_level);
  void set_log_size(int size);
  void put_entry(int level, char *file_name, int line_number,
        const char* format, ...);

private:
  int _log_level;
  int _log_size;
  FILE * _fp = nullptr;
  std::mutex _mutex;

private:
  int open_file();
  int close_file();
  int write();
};

#endif
