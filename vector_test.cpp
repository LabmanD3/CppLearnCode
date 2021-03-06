#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const int size = 7; 
	vector <int> ia = { 0, 1, 1, 2, 3, 5, 8 }; 
	vector <int> ivec( 7 );
	vector <int>::iterator Iter;

	ia.insert(ia.begin() + 2, 6);	// vector在尾部之外的任何位置添加元素都需要移动元素
	cout << "1. ia中的元素为: ";
	for ( Iter = ia.begin(); Iter != ia.end(); ++Iter)
		cout << *Iter << " ";
	cout << endl;

	cout << "------------------" << endl;
	for ( int ix = 0; ix < size; ix++ ) 
      		ivec.push_back( ix );

	cout << "ivec中的元素为: ";
	for ( Iter = ivec.begin(); Iter != ivec.end(); ++Iter)
		cout << *Iter << " ";
	cout << endl;

	vector <int> v1;
   	vector <int>::iterator Iter1;

   	int i;
  	 for ( i = 1 ; i < 21 ; i++ )
  	 {
      		v1.push_back( i );
   	}

   	cout << "最初向量v1中个元素的值为:\n ( " ;
   	for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      		cout << *Iter1 << " ";
   	cout << ")." << endl;

	return 0;
}
