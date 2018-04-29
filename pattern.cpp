#include<iostream>
#include<cstdlib>
using namespace std;

void pattern();
int main(int argc, char const *argv[])
{
	pattern();
	return 0;
}

void pattern()
{

	while(1){
		int n;
		cout<<"input n: "; 
		cin>>n;
		cout<<"\n";	

    	int len = 2*n -	1;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                cout<<(1 + max(abs(n-i-1),abs(n-j-1)));
            }
            cout<<'\n';
        }
	}
}