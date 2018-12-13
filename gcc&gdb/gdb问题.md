非root不能gdb attach的限制

Could not attach to process.  If your uid matches the uid of the target
process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try
again as the root user.  For more details, see /etc/sysctl.d/10-ptrace.conf


从ubuntu10.10开始，除非进程B是进程A的子进程，或者进程A为root运行，否则进程A不能调试进程B。这样一来增加了进程的安全。这个安全限制是默认的，但是可以通过修改配置文件来达到任意进程A可以调试进程B的目的。

修改前（/etc/sysctl.d/10-ptrace.conf）：
kernel.yama.ptrace_scope = 1
修改后：
kernel.yama.ptrace_scope = 0