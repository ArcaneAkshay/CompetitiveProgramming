#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	return a % b == 0 ? a : gcd(b, a % b);
}

int main()
{
	cout<<gcd(9,24)<<endl;
	return 0;
}