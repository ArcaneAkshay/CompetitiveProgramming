// ================== Divide & Conquer ===============

#include<iostream>
using namespace std;

#define N 100

int merge(int *arr, int s, int e)
{
	int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int k = s;

	int temp[N];

	int cnt = 0; // To count number of Cross Inversions

	// Sorting will not effect the number of inversions
	// because the relative order of the elements of one array w.r.t. second doesn't change
	while(i<=mid && j<=e)
	{
		if(arr[i]<arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			cnt += mid- i + 1;
		}
	}

	while(i<=mid)
		temp[k++] = arr[i++];
	
	while(j<=e)
		temp[k++] = arr[j++];

	// Copy all the elements back to array arr

	for(int i=s;i<=e;i++)
		arr[i] = temp[i];

	return cnt;
}

int inversionCount(int *arr, int s, int e)
{
	// 1. Divide
	// Base Case
	if(s>=e)
		return 0;

	// Merge Sort
	int mid = (s+e)/2;
	int x = inversionCount(arr,s,mid);
	int y = inversionCount(arr,mid+1,e);
	
	// 2. Merge
	int z = merge(arr,s,e); // To count number of Cross Inversions
	return x+y+z;
}

int main()
{
	int arr[] = {1,5,2,6,3,0};

	cout<<inversionCount(arr,0,6)<<endl;

	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
	return 0;
}