main:./src/*cpp
	g++ -o ./bin/server ./src/serverMain.cpp ./src/Mutex.cpp ./src/Condition.cpp ./src/Task.cpp ./src/Thread.cpp ./src/ThreadPool.cpp ./src/UDPserver.cpp ./src/WorkThread.cpp ./include/copyable.h ./include/noncopyable.h -lpthread
	g++ -o ./bin/client ./src/clientMain.cpp ./src/UDPclient.cpp ./include/noncopyable.h
