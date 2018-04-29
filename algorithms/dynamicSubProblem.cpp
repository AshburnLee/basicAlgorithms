#include<iostream>
using namespace std;

int fib(int);
int main(int argc, char const *argv[])
{
	int n;
	cout<<"input a number: ";
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}

int fib(int n)
{
	if(n<=1)
		return n;
	return fib(n-1) + fib(n-2);
}