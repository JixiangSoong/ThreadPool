/*************************************************************************
	> File Name: ThreadPool.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月04日 星期日 15时47分24秒
 ************************************************************************/

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "Mutex.h"
#include "Condition.h"
#include "WorkThread.h"
#include "netinet/in.h"
#include "noncopyable.h"
#include <string>
#include <vector>
#include <queue>

class Task;

class ThreadPool : public noncopyable
{
	public:
		ThreadPool(std::vector<WorkThread>::size_type thread_num);
		~ThreadPool();
		
		void start_thread_pool();
		void stop_thread_pool();
		
		bool add_task(Task &task);
		bool get_task(Task &task);

	private:
		bool _is_started;
		Mutex _mutex;
		Condition _cond;
		std::vector<WorkThread>::size_type _thread_num;
		std::vector<WorkThread> _thread_pool;
		std::queue<Task> _task_queue;
};
 
#endif 
