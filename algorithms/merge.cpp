#include<stdio.h>
#include<iostream>
#include<cstdlib> //rand
#include<ctime> //clock_t
using namespace std;

void preMerge(float*, int, int, int);
void merge(float*, int, int);
float* generateRandom(float*);
void swap(float*, float*);
void printArray(float* ,int);  //> (1)so here is a pointer float*
  
int length = 100000;
int main(int argc, char** argv)
{
    clock_t start,start2;
    double duration, duration2;
    
    float* ptr = new float[length];

    cout<<"GENERATING...\n";
    start = clock();
    generateRandom(ptr); 
    duration = (clock()-start)/(double) CLOCKS_PER_SEC;
    cout<<duration<<"\n";

    cout<<"MERGE: \n";
    start2 = clock();
    merge(ptr, 0, length-1);
    duration2 = (clock()-start2)/(double) CLOCKS_PER_SEC;
    cout<<duration2<<"\n";

    //printArray(ptr, length);

    delete ptr;
    ptr=NULL;
    return 0;
}

void preMerge(float arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    //create two empty arrays:
    float* subL = new float[n1];
    float* subR = new float[n2];
    //copy data:
    for(int i=0;i<n1;i++)
        subL[i] = arr[l + i];
    for(int i=0;i<n2;i++)
        subR[i] = arr[m+1 + i];

    int i=0;
    int j=0;
    int k=1;
    while(i<n1 && j<n2){
        if(subL[k] <= subL[j]){
            arr[k] = subL[i];
            i++;
        }else{
            arr[k] = subR[j];
            j++;
        }
        k++;
    }

    //copy the remaining elem:
    while(i<n1){
        arr[k]=subL[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = subR[j];
        j++;
        k++;
    }


    delete subL;
    subL=NULL;
    delete subR;
    subR=NULL;
}

void merge(float arr[], int l, int r)
{
    if(l<r){
        int m = l+(r-l)/2;
        merge(arr, l,m);
        merge(arr, m+1, r);

        preMerge(arr, l, m, r);
    }
}

float* generateRandom(float* ptr)
{

    for(int i=0;i<length;i++){

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

