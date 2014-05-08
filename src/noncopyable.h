/*************************************************************************
	> File Name: noncopyable.h
	> Author: Soong
	> Mail:sos1991@qq.com 
	> Created Time: 2014年05月05日 星期一 09时56分16秒
 ************************************************************************/

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

class noncopyable
{
	public:
		noncopyable(){}
		~noncopyable(){}
	private:
		noncopyable(const noncopyable &);
		noncopyable &operator=(const noncopyable &);
};
 
#endif 
