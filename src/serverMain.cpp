/*************************************************************************
	> File Name: serverMain.cpp
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月06日 星期二 21时51分01秒
 ************************************************************************/

#include "./../include/ThreadPool.h"
#include "./../include/UDPserver.h"
#include <iostream>

int main(int argc, char * argv[])
{
	ThreadPool pool(10);	 //初始化线程池
	pool.start_thread_pool();		//启动线程池
	UDPserver server(argv[1], argv[2], &pool);		//初始化UDP服务器
	server.start();		//启动UDP服务器
}
