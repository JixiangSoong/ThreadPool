/*************************************************************************
  > File Name: Mutex.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月04日 星期日 15时16分11秒
 ************************************************************************/

#include "Mutex.h"

Mutex::Mutex()
{
	pthread_mutex_init(&_mutex, NULL);
}
Mutex::~Mutex()
{
	pthread_mutex_destroy(&_mutex);
}
void Mutex::lock()
{
	pthread_mutex_lock(&_mutex);
}
void Mutex::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
