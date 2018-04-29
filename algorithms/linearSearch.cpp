/*
linear search 
binary search
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int* generation(int,int);
void printArray(int* , int);
int linearSearch(int*, int ,int);
void shellSort(int*, int);
int binarySearch(int*, int, int, int);

int main(int argc, char const *argv[])
{
	int length;
	int target;
	int range = 100;
	while(true){
		cout<<"input the lenght of array: ";
		cin>>length;
	
		cout<<"input the target: ";
		cin>>target;
	
		//check error:
		if(target > range){
			cout<<"target out of range!\n";
			continue;
		}

		//generat an array:
		int* ptr = generation(length, range);
		printArray(ptr, length);

		//sort the array:
		shellSort(ptr, length);
		printArray(ptr,length);

		//int index = linearSearch(ptr, length, target);
		int index = binarySearch(ptr, 0, length, target);
		cout<<"Result: "<<index<<endl;
	}

	return 0;
}

int* generation(int length, int range)
{
	int* ptr = new int[length];
	for (int i = 0; i < length; ++i){
		ptr[i] = static_cast<int>(rand())/(static_cast<int>(RAND_MAX/range));
	}
	return ptr;
	delete ptr;
	ptr=NULL;
}

int linearSearch(int arr[], int length, int target)
{	
	for (int i = 0; i < length; ++i){
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int l, int r, int target)
{
	int mid = l + (r-l)/2;
	if(arr[mid] == target)
		return mid;
	if(arr[mid] > target)
		return binarySearch(arr, l, mid-1, target);
	return binarySearch(arr, mid+1, r, target);
}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
 
            arr[j] = temp;
        }
	}
}