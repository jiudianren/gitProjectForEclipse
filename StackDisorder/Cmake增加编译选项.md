https://blog.csdn.net/10km/article/details/51731959

��cmake�ű��У����ñ���ѡ�����ͨ��add_compile_options���Ҳ����ͨ��set�����޸�CMAKE_CXX_FLAGS��CMAKE_C_FLAGS�� 
ʹ�������ַ�ʽ���е������Ч����һ���ģ�����ע�����ǻ���������ģ� 
add_compile_options������ӵı���ѡ����������б�������(����c��c++������)����set��������CMAKE_C_FLAGS��CMAKE_CXX_FLAGS�������Ƿֱ�ֻ���c��c++�������ġ�

��������Ĵ���

	#�жϱ���������,�����gcc������,���ڱ���ѡ���м���c++11֧��
	if(CMAKE_COMPILER_IS_GNUCXX)
	    add_compile_options(-std=c++11)
	    message(STATUS "optional:-std=c++11")   
	endif(CMAKE_COMPILER_IS_GNUCXX)

ʹ��add_compile_options���-std=c++11ѡ������ڱ���c++����ʱ����c++11֧��ѡ�������Ϊadd_compile_options������������ͱ������ģ������ڱ���c����ʱ���ͻ��������warning

