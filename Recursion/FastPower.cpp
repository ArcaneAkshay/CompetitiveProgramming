#include<iostream>
using namespace std;

// Compute a^n
// a^n = a * a^(n-1)
// Time Complexity - O(N)
// Space Complexity - O(N)

int power(int a, int n)
{
	if(n==0)
		return 1;
	return a * power(a, n-1);
}

// Compute a^n
// a^n = (a^(n/2))^2       -> if n is even
//       (a^(n/2))^2 * a   -> if n is odd
// Time Complexity - O(logN)
// Space Complexity - O(N)

int fastPower(int a, int n)
{
	if(n==0)
		return 1;

	int s_ans = fastPower(a,n/2);
	s_ans *= s_ans;

	// If n is odd multiply the answer calculated above with 'a'
	if(n&1)
		return s_ans * a;
	// If the the number is odd return the answer itself
	return s_ans;
}



int main()
{
	cout<<power(2,10)<<endl;
	cout<<fastPower(2,10)<<endl;	
	return 0;
}