// Compute a^b % m 
// Time Conplexity -> O(log b) where b-> No.of bits in the number N 
//                   In any number max. number of bits are log N
// Uses -> Bitmask
//		-> Recursion
// For Fast Exponentiation remove -> % m :)
#include<iostream>
using namespace std;

int fastExp(int a, int b, int m)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
		{
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int main()
{
	int a,b;
	cout<<fastExp(2,5,3)<<endl;
	return 0;
}