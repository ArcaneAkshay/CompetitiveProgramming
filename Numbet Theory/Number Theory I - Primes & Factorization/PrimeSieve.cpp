#include<bits/stdc++.h>
using namespace std;

//Sieve Approach - Generate an array containing Prime Numbers
void primeSieve(int *p)
{
	//First mark all the odd numbers as prime
	for (int i = 3; i <= n; i+=2)
	{
		p[i] = 1;
	}

	//Sieve
	for (long long i = 3; i <= n; i+=2)
	{
		//if the current number is not marked (means it is prime)
		if(p[i] == 1)
		{
			//mark all the multiples of i as not prime
			for(long long j=i*i;j<=n;j+=i)
			{
				p[j] = 0;
			}
		}
	}
	//Special case
	p[2] = 1;
}

int main()
{
	int n;
	cin>>n;

	int p[n] = {0};
	primeSieve(p);

	for(int i=0;i<=n;i++)
	{
		if(p[i]==1)
		{
			cout<<i<<" ";
		}
	}

	return 0;
}
