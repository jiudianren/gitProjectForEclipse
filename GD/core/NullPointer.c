#include <string.h>



static void _null_pointer_test(void)
{

	//jdr:，因为它尝试操作地址为0的内存区域，而这个内存区域通常是不可访问的禁区，当然就会出错了
	char *ps_str = 0;
	*ps_str = 'o';
	return;
}

int main(int argc, char *argv[])
{
	_null_pointer_test();
	int i=0;
	while(i<10000)
	{
		i++;
	}
	return 0;
}
