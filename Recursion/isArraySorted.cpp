#include<bits/stdc++.h>
using namespace std;
// Method 1 
bool isArraySorted(int arr[], int n)
{
	if(n==1)
		return true;
	if(arr[0]<=arr[1] and isArraySorted(arr + 1,--n))
		return true;
	return false;
}

//Method 2
// bool isArraySorted(int arr[], int n)
// {
// 	if(n==1)
// 		return true;
// 	if(arr[n-1]>=arr[n-2] and isArraySorted(arr,--n))
// 		return true;
// 	return false;
// }
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<isArraySorted(arr,n);

	return 0;
}
