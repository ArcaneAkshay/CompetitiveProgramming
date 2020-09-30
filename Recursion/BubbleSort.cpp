#include<iostream>
using namespace std;

void bubbleSort(int *arr, int start, int end)
{
	for(int i=start;i<end-1;i++)
	{
		for(int j=start;j<end - i - 1;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

int main()
{
	int arr[] = {5,3,4,1,2};
	bubbleSort(arr,0,5);
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	return 0;
}