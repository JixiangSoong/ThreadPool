/*************************************************************************
	> File Name: Thread.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月04日 星期日 15时53分48秒
 ************************************************************************/

#ifndef THREAD_H_
#define THREAD_H_
#include <pthread.h>

class Thread
{
	public:
		Thread();
		virtual ~Thread();
		static void* thread_func(void *arg);
		virtual void run() = 0;
		void join();
	private:
		pthread_t _tid;
};
 
#endif 
