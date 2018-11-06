https://www.oschina.net/code/snippet_1395752_32459
一.    
线程池管理类 自身有一个线程池管理线程，该线程不断从 taskpool中取得task，传给threadpool 去执行。


threadpool 维护若干线程， 和维护一个 空闲线程列表。

threadpool 在创建一个线程后，会将该线程一直运行，当线程运行且无任务时，将线程，加入 空闲线程列表。线程空闲且等待任务执行命令，当空闲线程等待一定时间后，将该线程结束。

theadpool 接收到任务以后， 从空闲列表中，获取一个线程  （长时间，无限城），将任务装在进去并置位任务执行命令。


编译：

g++ -o test threadpoolmanager.cpp threadpool.cpp taskpool.cpp main.cpp -lpthread