// Space optimised Sieve using Bitset
// Checking if a Large No. is prime or not ~ 10^14
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve()
{
	//set all bits
	b.set(); //1,1,1,1,1,.....
	b[0] = b[1] = 0;

	for(long long i = 2; i<=n;i++)
	{
		if(b[i])
		{
			primes.push_back(i);
			for(long long j = i*i ; j<=n ; j+=i)
			{
				b[j] = 0;
			}
		}
	}
}

bool isPrime(long long no)
{
	if(no<=n)
		return b[no] == 1? true : false;
	for(long long i = 0; primes[i] * (long long)primes[i] <= no; i++)
	{
		if(no % primes[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	sieve();

	if(isPrime(2147483647))
	{
		cout<<"Yes!\n";
	}
	else
	{
		cout<<"No\n";
	}

	// for(int i=0;i<=100;i++)
	// {
	// 	cout<<primes[i]<<" ";
	// }

	return 0;
}