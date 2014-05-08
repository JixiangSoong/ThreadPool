/*************************************************************************
	> File Name: UDPclient.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月06日 星期二 22时38分53秒
 ************************************************************************/

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_
#include "noncopyable.h"
#include <netinet/in.h>

class UDPclient : public noncopyable
{
	public:
		UDPclient(char *ip, char *port);
		~UDPclient();
		void start();
	private:
		int _server_fd;
		struct sockaddr_in _server_addr;
};
 
#endif 
