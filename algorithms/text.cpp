#include<iostream>

int main(int argc, char** argv)
{
	char* buffer = new char[8];

	buffer[0] = 'H';

	char* ptr = buffer;

	std::cout<<"buffer: \t"<<buffer<<"\n";
	std::cout<<"&bffer[0]: \t"<<&buffer[0]<<"\n";
	std::cout<<"bffer[0]: \t"<<buffer[0]<<"\n";
	std::cout<<"ptr: \t"<<ptr<<"\n";
	std::cout<<"*ptr: \t"<<*ptr<<"\n";
	delete []buffer;
	buffer = NULL;

	return 0;
}