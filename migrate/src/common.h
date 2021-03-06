#ifndef _MIGRATE_COMMON_H
#define _MIGRATE_COMMON_H


#include <vector>
#include <list>
#include <memory>
#include <mutex>

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

class Thread {
};

class ThreadPool {
public:
  ThreadPool() {}
  ~ThreadPool() {}
  void init(int num_threads, void * (*func)(void* arg), void* arg=nullptr);
  void exit();
  int enqueue(const Task * task);
  const Task * dequeue();

private:
  list<const Task *> tasks;
  vector<pthread_t>pool_threads;
  int threads_num;
  bool _signaled = false;
  pthread_mutex_t _lock;
  pthread_cond_t _cond;
};


#endif
