#include<algorithm>
#include<iostream>
#include<cstdlib> //rand
#include<ctime>
#include<string>
using namespace std;

float* generateRandom();
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

	cout<<"BUBBLE: \n";
	start2 = clock();
	sort(ptr, ptr+length);
	duration2 = (clock() - start2)/(double) CLOCKS_PER_SEC;
	cout<<duration2<<endl;
	//printArray(ptr, length);
	return 0;
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

void printArray(float arr[], int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
