#ifndef _MIGRATE_COMMON_H
#define _MIGRATE_COMMON_H


#include <vector>
#include <list>
#include <memory>
#include <mutex>
#include "info.h"

using namespace std;

class WaitEvent {
public:
  WaitEvent();
  ~WaitEvent();
  void wait();
  void signal();
private:
  bool _signaled = false;
  pthread_mutex_t _lock;
  pthread_cond_t _cond;
};

template<typename T>
class Singleton {
public:
  static T* get_instance() {
    static std::once_flag s_flag;
    std::call_once(s_flag, [&]() {
      _sington.reset(new T());
    });
      return _sington.get();
  }
protected:
  Singleton(){};
  ~Singleton(){};
static std::shared_ptr<T> _sington;
private:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

template<typename T> std::shared_ptr<T> Singleton<T>::_sington;


class Task {
public:
  
};

typedef struct op {
  int op;
  long long vm_uuid;
  string remote_ip;
}op_t;

typedef struct message {
  int magic;
  op_t op;
}message_t;

class Thread {
public:
  void init(void * (*func)(void* arg), void* arg=nullptr);
  void exit();
};

class ThreadPool {
public:
  ThreadPool() {}
  ~ThreadPool() {}
  void init(int num_threads, void * (*func)(void* arg), void* arg=nullptr);
  void exit();
  int enqueue(job_t * task);
  job_t * dequeue();

private:
  list<job_t *> tasks;
  int threads_num;
  bool _signaled = false;
  pthread_mutex_t _lock;
  pthread_cond_t _cond;
};


#endif
