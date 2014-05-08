/*************************************************************************
  > File Name: ThreadPool.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月04日 星期日 15时47分24秒
 ************************************************************************/

#include "./../include/ThreadPool.h"
#include "./../include/Task.h"

ThreadPool::ThreadPool(std::vector<WorkThread>::size_type thread_num) :
	_is_started(false), _mutex(), _cond(&_mutex), _thread_num(thread_num), _thread_pool(_thread_num, WorkThread(this)), _task_queue(){
}
ThreadPool::~ThreadPool(){
}

void ThreadPool::start_thread_pool()
{
	_is_started = true;
	for(std::vector<WorkThread>::iterator iter = _thread_pool.begin(); iter != _thread_pool.end(); ++iter)
		iter->start();
}
void ThreadPool::stop_thread_pool()
{
	_is_started = false;
	_cond.notifyAll();
	for(std::vector<WorkThread>::iterator iter = _thread_pool.begin(); iter != _thread_pool.end(); ++iter)
		iter->join();
}

bool ThreadPool::add_task(Task &task)
{
	_mutex.lock();
	if(!_is_started)
	{
		_mutex.unlock();
		return false;
	}
	_task_queue.push(task);
	_cond.notify();
	_mutex.unlock();
	return true;
}
bool ThreadPool::get_task(Task &task)
{
	_mutex.lock();
	while(_is_started && _task_queue.empty())
		_cond.wait();
	if(!_is_started)
	{
		_mutex.unlock();
		return false;
	}
	task = _task_queue.front();
	_task_queue.pop();
	_mutex.unlock();
	return true;
}

