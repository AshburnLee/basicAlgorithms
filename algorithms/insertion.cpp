#include<stdio.h>
#include<iostream>
#include<cstdlib> //rand
#include<ctime>
using namespace std;

float* generateRandom(float*);
void swap(float*, float*);
void insertion(float*, int);
void printArray(float* ,int);  //> (1)so here is a pointer float*
  
int length = 100000;
int main(int argc, char** argv)
{
	clock_t start,start2;
	double duration, duration2;
	// float floatNumber[length];
	// float* ptr = floatNumber;
	float* ptr = new float[length];

	cout<<"generating...\n";
	start = clock();
	generateRandom(ptr); 
	duration = (clock() - start)/(double) CLOCKS_PER_SEC;
	cout<<duration<<endl;
	

	cout<<"INSERTION: \n";
	start2 = clock();
	insertion(ptr, length);
	duration2 = (clock() - start2)/(double) CLOCKS_PER_SEC;
	cout<<duration2<<endl;
	//printArray(ptr, length);

	delete ptr;
	ptr=NULL;
	return 0;
}

void insertion(float arr[], int n)
{
	for (int i=1;i<n;i++){
		for (int j = i; j > 0 &&arr[j]<arr[j-1];j--){
			swap(arr[j], arr[j-1]);
		}
	}
}

float* generateRandom(float* ptr)
{

	for(int i=0;i<length;i++){
		// (2) random int
		//floatNumber[i] = 1 + (rand() % static_cast<int>(100 - 1 + 1));
		// (2) random float form 0~10:
		*(ptr+i) = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10));
		//cout<<ptr[i]<<" ";
	}
	return ptr;
}

void swap(float* px, float*py)
{
	float tmp = *px;
	*px = *py;
	*py = tmp;
}
//pass a array to func, type changed to pointer!!>
void printArray(float arr[], int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}



/* pass array to a function:
void myFunction(int *param)
void myFunction(int param[10])
void myFunction(int param[])
*/