#include <stdarg.h>
#include "log.h"

#define LOGGING_DEAFULT_FILESIZE 0
#define LOGGING_DEAULT_LEVLE 0

int Logger::init() {
  int rc = 0;
  set_log_level(LOGGING_DEAULT_LEVLE);
  set_log_size(LOGGING_DEAFULT_FILESIZE);
  rc = open_file();
  return rc;
}

void Logger::exit() {
  close_file();
  return;
}

void Logger::set_log_level(int log_level) {
  _log_level = log_level;
  return;
}

void Logger::set_log_size(int size) {
  _log_size = size;
  return;
}


int Logger::open_file() {
  int rc = 0;
#if 0
  _fp = fopen("/var/log/migrate.log", "w+");
  if (_fp == NULL)
  {

  }
#endif
  return rc;
}

int Logger::close_file() {
  int rc = 0;
#if 0
  if (_fp) {
    fflush(_fp);
    fclose(_fp);
    _fp = 0;
  }
#endif
  return rc;
}

int Logger::write() {
  int rc = 0;
#if 0
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
#endif
  return rc;
}

void Logger::put_entry(int level, char *file_name,
        int line_number, const char* format,
        ...) {
  int rc = 0;
  char log_info[256] = {0};
  string log_buff;

  // 获取时间

  // 打印时间搓

  // 打印 log头信息

  va_list ap;
  va_start(ap, format);
  rc = vsnprintf(log_info, 256, format, ap);
  va_end(ap);
  log_buff += string(log_info);
  log_buff += string("\n");
  //write(log_buff);

  return;
}