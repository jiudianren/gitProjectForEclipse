#include <string.h>



static void _null_pointer_test(void)
{

	//jdr:����Ϊ�����Բ�����ַΪ0���ڴ����򣬶�����ڴ�����ͨ���ǲ��ɷ��ʵĽ�������Ȼ�ͻ������
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
