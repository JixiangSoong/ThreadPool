/*************************************************************************
	> File Name: Condition.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月04日 星期日 15时25分30秒
 ************************************************************************/

#ifndef CONDITION_H_
#define CONDITION_H_
#include <pthread.h>

class Mutex;

class Condition
{
	public:
		Condition();
		~Condition();
		void wait();
		void notify();
		void notifyAll();
	private:
		pthread_cond_t _cond;
		Mutex* _p_mutex;
};
 
#endif 
