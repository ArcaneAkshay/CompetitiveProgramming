#include<iostream>
using namespace std;

// Finding the element in the array given that it is unique
template<typename T>
T binarySearch_1(T arr[], int l, int r, int key)
{
	if(l<=r)
	{
		int mid =  l + (r - l)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid] > key)
			return binarySearch_1(arr,l,mid - 1,key);
		return binarySearch_1(arr,mid+1, r,key);
	}
	return -1;

}

// Given the element is not unique (duplpicates are present in the array)

// 1) Finding the first occurence of the element
template<typename T>
T binarySearch_2(T arr[], int l, int r, int key)
{
	if(l<=r)
	{
		int mid =  l + (r - l)/2;
		if(arr[mid] == key)
		{
			if(mid == 0) // or if(l == r) return l;
				return 0;
			if(arr[mid-1] < arr[mid])
				return mid;
			if(arr[mid-1] == key)
				return binarySearch_2(arr,l,mid - 1,key);
		}
		if(arr[mid] > key)
			return binarySearch_2(arr,l,mid - 1,key);
		return binarySearch_2(arr,mid+1, r,key);
	}
	return -1;
}


// 2) Finding the last occurence of the element
template<typename T>
T binarySearch_3(T arr[], int l, int r, int key)
{
	if(l<=r)
	{
		int mid =  l + (r - l)/2;
		if(arr[mid] == key)
		{
			if(l == r)
				return mid;
			if(arr[mid] < arr[mid + 1])
				return mid;
			if(arr[mid + 1] == key)
				return binarySearch_3(arr, mid + 1, r, key);
		}
		if(arr[mid] > key)
			return binarySearch_3(arr,l,mid - 1,key);
		return binarySearch_3(arr,mid+1, r,key);
	}
	return -1;
}

int main()
{
	int arr[5] = {1,1,3,5,5};
	int key = 5;
	int i = binarySearch_1(arr,0,5,key);
	if(i!=-1)
		cout<<i<<endl;
	else
		cout<<"Not Exists"<<endl;
	return 0;
}