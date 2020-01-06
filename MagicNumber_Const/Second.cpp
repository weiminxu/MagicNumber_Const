#include <iostream>

using namespace std;

extern const int buffsize;

void foo()
{
	std::cout << buffsize << std::endl;
	/*
	for (int i=0; i!= buffsize;++i)
	{
		cout << "this buffsize is coming from MagicNumber_Const file" << endl;
	}
	*/
}