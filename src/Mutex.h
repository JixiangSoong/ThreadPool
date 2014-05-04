/*************************************************************************
	> File Name: Mutex.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月04日 星期日 15时16分11秒
 ************************************************************************/

#ifndef MUTEX_H_
#define MUTEX_H_
#include <pthread.h>

class Mutex
{
	friend class Condition;
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();

	private:
		pthread_mutex_t _mutex;
};
 
#endif 
