#include<iostream>
using namespace std;

// Method 1 --> Same as finding the last occurence of an element
int linearSearch_1(int arr[], int n, int key)
{
	if(n == 0)
		return -1;
	int i = linearSearch_1(arr +1, n - 1,key);
	if(i == -1)
	{
		if(arr[0] == key)
			return 0;
		return -1;
	}
	// if i returned by the subproblem is not -1 that means it is present at 0th
	// index in the subproblem meaning it is present at 1st index of the given problem scope
	// hence we are adding 1 every time if we find the element in the subproblem
	return i + 1;
}

// Method 2 --> Same as finding the last occurence of an element
int linearSearch_2(int arr[], int n, int key)
{
	if(n==-1)
		return -1;
	if(arr[n] == key)
		return n;
	return linearSearch_2(arr, --n, key);
}

// Method 3 --> Same as finding the first occurence of an element
int linearSearch_3(int arr[], int i, int n, int key)
{
	if(i == n)
		return -1;
	if(arr[i] == key)
		return i;
	return linearSearch_3(arr, i + 1, n, key);
}

// Method 4 --> Same as finding the first occurence of an element
int linearSearch_4(int arr[], int n, int key)
{
	if(n == 0)
		return -1;
	if(arr[0] == key)
		return 0;
	int i = linearSearch_4(arr + 1, n - 1, key);
	if(i==-1)
		return -1;
	return i+1;
}

int main()
{
	int arr[6] = {1,4,2,4,4,3};
	cout<<linearSearch_1(arr, 6, 4);
	return 0;
}
