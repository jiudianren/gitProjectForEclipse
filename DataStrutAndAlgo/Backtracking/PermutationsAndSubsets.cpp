

#include "PermutationsAndSubsets.h"
#include <iostream>




int mainStlPermatation () {
	int myints[] = {1,2,3,1};


	/*如果要获取所有组合，则需要先sort */
	sort (myints,myints+4);

	do {
		cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '<< myints[3]<<'\n';
	} while ( next_permutation(myints,myints+4) );    ///获取下一个较大字典序排列

	cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '<< myints[3] <<'\n';
	return 0;
}
