

#include "PermutationsAndSubsets.h"
#include <iostream>




int mainStlPermatation () {
	int myints[] = {1,2,3,1};


	/*���Ҫ��ȡ������ϣ�����Ҫ��sort */
	sort (myints,myints+4);

	do {
		cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '<< myints[3]<<'\n';
	} while ( next_permutation(myints,myints+4) );    ///��ȡ��һ���ϴ��ֵ�������

	cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '<< myints[3] <<'\n';
	return 0;
}
