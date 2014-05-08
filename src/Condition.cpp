/*************************************************************************
  > File Name: Condition.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月04日 星期日 15时25分30秒
 ************************************************************************/

#include "Condition.h"
#include "Mutex.h"

Condition::Condition(Mutex *p_mutex) : _p_mutex(p_mutex)
{
	pthread_cond_init(&_cond, NULL);
}
Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}
void Condition::wait()
{
	pthread_cond_wait(&_cond, &(_p_mutex->_mutex));
}
void Condition::notify()
{
	pthread_cond_signal(&_cond);
}
void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}
