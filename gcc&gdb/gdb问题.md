��root����gdb attach������

Could not attach to process.  If your uid matches the uid of the target
process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try
again as the root user.  For more details, see /etc/sysctl.d/10-ptrace.conf


��ubuntu10.10��ʼ�����ǽ���B�ǽ���A���ӽ��̣����߽���AΪroot���У��������A���ܵ��Խ���B������һ�������˽��̵İ�ȫ�������ȫ������Ĭ�ϵģ����ǿ���ͨ���޸������ļ����ﵽ�������A���Ե��Խ���B��Ŀ�ġ�

�޸�ǰ��/etc/sysctl.d/10-ptrace.conf����
kernel.yama.ptrace_scope = 1
�޸ĺ�
kernel.yama.ptrace_scope = 0