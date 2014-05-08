/*************************************************************************
  > File Name: UDPserver.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月06日 星期二 15时55分19秒
 ************************************************************************/

#include "UDPserver.h"
#include "Task.h"
#include <sys/socket.h>
#include <cstddef>
#include <cstring>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

UDPserver::UDPserver(char *ip, char *port, ThreadPool *p_thread_pool) : 
	_server_fd(), _server_addr(), _p_thread_pool(p_thread_pool)
{
	_server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	_server_addr.sin_family = AF_INET;
	_server_addr.sin_port = htons(atoi(port));
	_server_addr.sin_addr.s_addr = inet_addr(ip);
	bind(_server_fd, (struct sockaddr*)&_server_addr, sizeof(struct sockaddr));
}
UDPserver::~UDPserver()
{
	close(_server_fd);
}
void UDPserver::start()
{
	struct sockaddr_in client_addr;
	socklen_t client_len;
	char buf[128] = "";
	while(bzero(buf, 128), bzero(&client_addr, sizeof(client_addr)), client_len = sizeof(client_addr),
			recvfrom(_server_fd, buf, 128, 0, (struct sockaddr*)&client_addr, &client_len))
	{
		Task task(client_addr, std::string(buf));
		if(!_p_thread_pool->add_task(task))
		{
			std::cout << "can't add task" << std::endl;
			return ;
		}
	}
}
