#include<stdio.h>
#include<iostream>
#include<cstdlib> //rand
#include<ctime>
using namespace std;

float* generateRandom();
void swap(float*, float*);
void shellSort(float*, int);
void printArray(float* ,int);  //> (1)so here is a pointer float*
  
int length = 100000;
int main(int argc, char** argv)
{
	clock_t start,start2;
	double duration, duration2;
	
	cout<<"GENERATING...\n";
	start = clock();
	float* ptr = generateRandom(); 
	duration = (clock() - start)/(double) CLOCKS_PER_SEC;
	cout<<duration<<endl;

	cout<<"SHELL SORT: \n";
	start2 = clock();
	shellSort(ptr, length);
	duration2 = (clock() - start2)/(double) CLOCKS_PER_SEC;
	cout<<duration2<<endl;
	//printArray(ptr, length);

}

void shellSort(float arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            float temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
	}
}


float* generateRandom()
{
	float* ptr = new float[length];
	for(int i=0;i<length;i++){
		// (2) random int
		//floatNumber[i] = 1 + (rand() % static_cast<int>(100 - 1 + 1));
		// (2) random float form 0~10:
		*(ptr+i) = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10));
		//cout<<ptr[i]<<" ";
	}
	return ptr;

	delete ptr;
	ptr=NULL;
}

void swap(float* px, float*py)
{
	float tmp = *px;
	*px = *py;
	*py = tmp;
}
void printArray(float arr[], int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
