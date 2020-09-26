#include<iostream>
using namespace std;

template<typename T>
T binarySearch(T arr[], int l, int r, int key)
{
	if(l<=r)
	{
		int mid =  l + (r - l)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid] > key)
			return binarySearch(arr,l,mid - 1,key);
		return binarySearch(arr,mid+1, r,key);
	}
	return -1;

}

int main()
{
	int arr[5] = {1,2,3,4,5};
	int key = 8;
	int i = binarySearch(arr,0,5,key);
	if(i!=-1)
		cout<<i<<endl;
	else
		cout<<"Not Exists"<<endl;
	return 0;
}