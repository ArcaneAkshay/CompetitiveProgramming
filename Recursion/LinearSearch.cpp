#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
	if(n==-1)
		return -1;
	if(arr[n] == key)
		return n;
	return linearSearch(arr, --n, key);
}

int main()
{
	int arr[5] = {1,2,5,4,3};
	cout<<linearSearch(arr, 5, 5);
	return 0;
}
