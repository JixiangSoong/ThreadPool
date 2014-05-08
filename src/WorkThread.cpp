/*************************************************************************
  > File Name: WorkThread.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月05日 星期一 09时52分13秒
 ************************************************************************/

#include "WorkThread.h"
#include "ThreadPool.h"
#include "Task.h"

WorkThread::WorkThread(ThreadPool * p_thread_pool) : _p_thread_pool(p_thread_pool){

}
void WorkThread::run()
{
	while(true)
	{
		Task task;
		if(_p_thread_pool->get_task(task) == false)
			return ;
		task.deal_task();
	}
}
