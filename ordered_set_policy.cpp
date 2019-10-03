#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

using namespace std;

int main()
{
    ordered_set p;
    p.insert(5);
    p.insert(2);
    p.insert(2); // set contain no dublicate entries.
    p.insert(6);
    p.insert(4);
	
    // value at 3rd index in sorted array.
    cout << "The value at 3rd index ::" << *p.find_by_order(3) << endl;
	
    // index of number 6
    cout << "The index of number 6  ::" << p.order_of_key(6) << endl;
	
    // number 7 not in the set but it will show the index number if it was there in sorted array.
    cout << "The index of number seven ::"<< p.order_of_key(7) << endl;
	
	cout<<p.size() <<endl;
	if(*p.find(6)==6)
		cout<< 6 <<" exists."<<endl;
	if(*p.find(6)!=3)
		cout<< 3 <<" does not exists."<<endl;
	p.erase(p.find_by_order(2));
	
}


