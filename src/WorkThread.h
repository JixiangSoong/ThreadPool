/*************************************************************************
	> File Name: WorkThread.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月05日 星期一 09时52分13秒
 ************************************************************************/

#ifndef WORKTHREAD_H_
#define WORKTHREAD_H_
#include "Thread.h"

class ThreadPool;

class WorkThread : public Thread
{
	public:
		WorkThread(ThreadPool * p_thread_pool);
		void run();
	private:
		ThreadPool *_p_thread_pool;
};
 
#endif 
