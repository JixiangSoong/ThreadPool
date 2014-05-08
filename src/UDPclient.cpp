/*************************************************************************
  > File Name: UDPclient.cpp
  > Author: Soong
  > Mail:sos1991@qq.com 
  > Created Time: 2014年05月06日 星期二 22时38分53秒
 ************************************************************************/

#include "UDPclient.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

UDPclient::UDPclient(char *ip, char *port)
{
	_server_addr.sin_family = AF_INET;
	_server_addr.sin_port = htons(atoi(port));
	_server_addr.sin_addr.s_addr = inet_addr(ip);
	_server_fd = socket(AF_INET, SOCK_DGRAM, 0);
}
UDPclient::~UDPclient(){
}

void UDPclient::start()
{
	char send_buf[128] = "" , recv_buf[128] = "";
	struct sockaddr_in from_addr;
	socklen_t addr_len;
	while(std::cin >> send_buf)
	{ 
		addr_len = sizeof(struct sockaddr);
		bzero(&from_addr, sizeof(from_addr));
		sendto(_server_fd, send_buf, strlen(send_buf), 0, (struct sockaddr*)&_server_addr, sizeof(struct sockaddr));
		bzero(recv_buf, 128);
		recvfrom(_server_fd, recv_buf, 128, 0, (struct sockaddr*)&from_addr, &addr_len);
		std::cout << recv_buf << std::endl;
		bzero(recv_buf, 128);
	}
}
