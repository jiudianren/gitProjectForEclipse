https://blog.csdn.net/sduliulun/article/details/7732906


����	����
ʹ��δ��ʼ�����ڴ�	Use of uninitialised memory
ʹ���Ѿ��ͷ��˵��ڴ�	Reading/writing memory after it has been free��d
ʹ�ó��� malloc������ڴ�ռ�	Reading/writing off the end of malloc��d blocks
�Զ�ջ�ķǷ�����	Reading/writing inappropriate areas on the stack
����Ŀռ��Ƿ����ͷ�	Memory leaks �C where pointers to malloc��d blocks are lost forever
malloc/free/new/delete������ͷ��ڴ��ƥ��	Mismatched use of malloc/new/new [] vs free/delete/delete []
src��dst���ص�	Overlapping src and dst pointers in memcpy() and related functions
