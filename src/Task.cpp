/*************************************************************************
  > File Name: Task.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月06日 星期二 15时58分02秒
 ************************************************************************/

#include "Task.h"
#include <iostream>

Task::Task(const sockaddr_in &client_addr, const std::string &word) : _word(word), _addr(client_addr){
}
Task::~Task(){
}

void Task::deal_task()
{
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	sendto(fd, _word.c_str(), _word.size(), 0, (struct sockaddr*)&_addr, sizeof(struct sockaddr));
}
