


#include <vector>
#include <vector>
#include <memory>
using namespace std;

template < typename T>
class Bole
{

public:
	T  id;
	std::shared_ptr<vector<T>> date;

	void check( std::string msg);
	Bole & operator++(Bole & rsh)
		{
			return *this;
		}

	Bole & operator--(Bole & rsh);

	template<class it> Bole(it begin,it end);

public:
	static int count;


};

/*
 *
 * Bole<int > f1, f2,f3
 * f1，f2 f3，共享 count 该 count 为Bole<int>所有  Bole<int>::count
 *
 * Bole<string > f4
 * f4独享 cout   Bole<string>::count
 *
 *
 * */

/*类外定义*/

template< typename T>  void Bole<T>::check(string msg)
{
	return ;
}


/*类外定义和类内定义的区别*/
template< typename T>  Bole<T>&  Bole<T>::operator--(Bole<T> & rsh)
{
	return  *this;
}


template<typename T> template <class it> Bole<T>::Bole(it begin,it end)
		{

		}

template <class T > using twins=pair<T,T>;
twins<int>  win_lss; //win_lss is a pair<int,int >
