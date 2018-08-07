spdlog ��ʲô�� �������� �� ����ã� 

spdlog��һ����Դ�ġ����ٵġ�����ͷ�ļ���C++11 ��־�⣬code��ַ�� https://github.com/gabime/spdlog ��Ŀǰ���µķ����汾Ϊ0.14.0�����ṩ����������׼������ļ���ϵͳ��־����������Ŀ�������־����������֧�ֵ�ƽ̨����Windows��Linux��Mac��Android��

	spdlog���ԣ�

	(1)���ǳ��죬������������ҪĿ�ꣻ

	(2)��������ͷ�ļ���

	(3)����־�ĸ�ʽ������ʹ�ÿ�Դ��fmt��(  https://github.com/fmtlib/fmt )��

	(4)����ѡ��printf�﷨֧�֣�

	(5)���ǳ�����첽ģʽ(��ѡ)��֧���첽д��־��

	(6)���Զ����ʽ��

	(7)��������־��

	(8)�����߳�/���߳���־��

	(9)��������־Ŀ�꣺�ɶ���־�ļ�����ѭ���������ÿ��������־�ļ���֧�ֿ���̨��־���(֧����ɫ)��ϵͳ��־��Windows debugger����������չ�Զ�����־Ŀ�ꣻ

	(10)��֧����־���������ֵ����ȿ���������ʱҲ�����ڱ���ʱ�޸ġ�
	
	
	
	
## Benchmarks

Below are some [benchmarks](bench) comparing popular log libraries under Ubuntu 64 bit, Intel i7-4770 CPU @ 3.40GHz

#### Synchronous mode
Time needed to log 1,000,000 lines in synchronous mode (in seconds, the best of 3 runs):

|threads|boost log 1.54|glog   |easylogging |spdlog|
|-------|:-------:|:-----:|----------:|------:|
|1|       4.169s  |1.066s |0.975s     |0.392s|
|10|     6.180s   |3.032s |2.857s     |0.773s|
|100|     5.981s  |1.139s |4.512s     |0.587s|


#### Asynchronous mode
Time needed to log 1,000,000 lines in asynchronous mode, i.e. the time it takes to put them in the async queue (in seconds, the best of 3 runs):

|threads|g2log <sup>async logger</sup>   |spdlog <sup>async mode</sup>|
|:-------|:-----:|-------------------------:|
|1|       1.850s |0.39s |
|10|      0.943s  |0.416s|
|100|      0.959s |0.413s|
	