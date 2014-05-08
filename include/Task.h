/*************************************************************************
	> File Name: Task.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月06日 星期二 15时58分02秒
 ************************************************************************/

#ifndef TASK_H_
#define TASK_H_
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include "copyable.h"

class Task : public copyable
{
	public:
		Task(){}
		Task(const sockaddr_in &client_addr, const std::string &word);
		~Task();
		void deal_task();
	private:
		std::string _word;
		struct sockaddr_in _addr;
};
 
#endif 
