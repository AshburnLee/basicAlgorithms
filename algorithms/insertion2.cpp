#include<iostream>
#include<cstdlib>
using namespace std;

float* generateData();
void printArray(float*, int);
void insertion_i(float*, int);

int length=100;
int main(int argc, char const *argv[])
{
    float* ptr = generateData();
    printArray(ptr, length);
    insertion_i(ptr, length);
    printArray(ptr, length);

    return 0;
}

void insertion_i(float arr[], int length)
{
    for(int i = 0;i<length;i++){  // i has changed

        int j = i+1;
        int count = 0;
        float tmp = arr[j];
        while(tmp < arr[i] && j>=0 && i>=0){
            arr[i+1] = arr[i];
            i--;
            count++;
        }
        arr[i+1] = tmp;
        i = i+count;      // change i to the original value!!!!:                                                                                                                                                                                                                                                         
    }
}

void insertion_j(float arr[], int length)
{
    for(int i=0;i<length;i++){   // i do not change
        float tmp = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>tmp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}

float* generateData()
{
    float* ptr = new float[length];
    for(int i=0;i<length;i++)
        *(ptr+i) = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/20));

    return ptr;
    delete ptr;
    ptr=NULL;
}
void printArray(float arr[], int length)
{
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}    