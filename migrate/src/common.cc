#include <list>
#include <vector>
#include "pthread.h"

#include "common.h"


WaitEvent::WaitEvent() {
  pthread_mutex_init(&_lock, NULL);
  pthread_cond_init(&_cond, NULL);
}

WaitEvent::~WaitEvent() {
  pthread_mutex_destroy(&_lock);
  pthread_cond_destroy(&_cond);
}

void WaitEvent::wait() {
  pthread_mutex_lock(&_lock);
  pthread_cond_wait(&_cond, &_lock);
  pthread_mutex_unlock(&_lock);
}

void WaitEvent::signal() {
  pthread_mutex_lock(&_lock);
  pthread_cond_signal(&_cond);
  pthread_mutex_unlock(&_lock);
}

void Thread::init(void * (*func)(void* args),
        void* args) {
    pthread_t ntid;
    pthread_create(&ntid, NULL, func, args);
}


void Thread::exit() {
  return;
}


void ThreadPool::init(int threads_num, void * (*func)(void* args),
        void* args) {

  //this->threads_num = threads_num;
  for (int i = 0; i < threads_num; i++) {
    pthread_t ntid;
    pthread_create(&ntid, NULL, func, args);
  }
}

void ThreadPool::exit() {
  return;
}

int ThreadPool::enqueue(job_t *task) {
  int size = 0;
  pthread_mutex_lock(&_lock);
  tasks.push_back(task);
  size = tasks.size();
  pthread_cond_signal(&_cond);
  pthread_mutex_unlock(&_lock);
  return size;
}

job_t* ThreadPool::dequeue() {
  job_t* task;
  pthread_mutex_lock(&_lock);
  while(tasks.empty()) {
    pthread_cond_wait(&_cond, &_lock);
  }
  task = tasks.front();
  tasks.pop_front();
  pthread_mutex_unlock(&_lock);
  return task;
}

