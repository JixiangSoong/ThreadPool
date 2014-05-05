/*************************************************************************
  > File Name: Thread.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月04日 星期日 15时53分48秒
 ************************************************************************/

#include "Thread.h"

Thread::Thread()
{
	pthread_create(&_tid, NULL, thread_func, this);
}
Thread::~Thread(){
}
void Thread::join()
{
	pthread_join(_tid, NULL);
}
static void* thread_func(void *arg)
{
	Thread *p_thread = static_cast<Thread*>(arg);
	p_thread->run();
	return NULL;
}
