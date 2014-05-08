/*************************************************************************
  > File Name: UDPserver.h
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月06日 星期二 15时55分19秒
 ************************************************************************/

#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "noncopyable.h"
#include <netinet/in.h>
#include "ThreadPool.h"

class ThreadPool;

class UDPserver : public noncopyable
{
	public:
		UDPserver(char *ip, char *port, ThreadPool *p_thread_pool);
		~UDPserver();
		void start();
	private:
		int _server_fd;
		struct sockaddr_in _server_addr;
		ThreadPool *_p_thread_pool;
};

#endif 
