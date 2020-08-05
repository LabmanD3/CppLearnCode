#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const int size = 7; 
	//int ia[ size ] = { 0, 1, 1, 2, 3, 5, 8 }; 
	vector< int > ivec( 7 );
	vector< int >::iterator Iter;
	
  
	for ( int ix = 0; ix < size; ix++ ) 
      		ivec.push_back( ix );

	cout << "ivec中的元素为:";
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

}
