#include<iostream>
using namespace std;

void selectActivity(int*, int*, int);
int main(int argc, char const *argv[])
{
	int start[]= {0,1,5,9,10};
	int finish[]={2,6,8,9,15};
	int n = sizeof(start)/sizeof(start[0]);
	selectActivity(start, finish, n);
	return 0;
}

// if this activity has starttime greater than or equal
// to the finish time of the previous selected activity,
// then select it
void selectActivity(int start[], int finish[], int n)
{
	cout<<"tollowing activities gets selected: ";
	int i=0;
	cout<<i<<" ";

	for(int j = 1; j<n; j++){
		if(start[j]>=finish[i]){
			cout<<j<<" ";
			i = j; 
		}
	}
	cout<<endl;
}