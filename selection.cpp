#include<stdio.h>
#include<iostream>
#include<cstdlib> //rand
#include<ctime>
using namespace std;

template <typename T>
T* generateRandom(T*);
template <typename T>
void swap(T*, T*);
template <typename T>
void selection(T*, int);
template <typename T>
void printArray(T* ,int); 

int length = 100000;
int main(int argc,char** argv)
{
	clock_t start,start2;
	double duration, duration2;

	float * ptr = new float[length];

	cout<<"generating...\n";
	start = clock();
	generateRandom<float>(ptr);
	duration = (clock() - start)/(double) CLOCKS_PER_SEC;
	cout<<duration<<endl;

	cout<<"SELECTION: \n";
	start2 = clock();
	selection<float>(ptr, length);
	duration2 = (clock() - start2)/(double) CLOCKS_PER_SEC;
	cout<<duration2<<endl;
	printArray<float>(ptr, length);
	
	delete ptr;
	ptr=NULL;
	return 0;
}

template <typename T>
void swap(T* px, T* py)
{
	T tmp = *px;
	*px = *py;
	*py = tmp;
}
template <typename T>
void printArray(T arr[], int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

template <typename T>
T* generateRandom(T* ptr)
{

	for(int i=0;i<length;i++){
	
		// (2) random T form 0~10:
		*(ptr+i) = static_cast <T> (rand()) / (static_cast <T> (RAND_MAX/100));
		//cout<<ptr[i]<<" ";
	}
	return ptr;
}

template <typename T>
void selection(T* arr, int n)
{
	for(int i=0;i<n;i++){

		T min = arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[j] < min)

			swap(&arr[j], &min);
		}
		arr[i] = min;
	}
}