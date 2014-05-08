/*************************************************************************
	> File Name: clientMain.cpp
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月07日 星期三 15时29分05秒
 ************************************************************************/

#include "./../include/UDPclient.h"

int main(int argc, char **argv)
{
	UDPclient client(argv[1], argv[2]);
	client.start();
	return 0;
}
