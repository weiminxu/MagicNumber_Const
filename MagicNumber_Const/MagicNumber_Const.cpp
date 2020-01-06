/*
	//const
	//A compile time constraint that an object can not modified

	Why use const:
	1)Guards against inadvertent write to the variable
	2)Self documenting
	3)Enables compiler to do more optimiztion, making code tighter
	4)const means the variable can be put in ROM
*/

#include <iostream>
#include "method_const.h"

using namespace std;

extern const int buffsize = 512;// the size of buff

int main()
{
	
	const std::string str = "Hello";
	const_cast<std::string&>(str) = "Hello the world!";
	
	const int i = 120;//the data is const
	
	const int* str1 = &i;//the data is const, but pointer is not
	str1++;
	
	int* const str2 = NULL;//pointer is const, data is not

	const int* const p3 = NULL;//data and pointer are const

	int const* str3 = &i;
	//const int* str3 = &i;//the data is const, it can not be changed

	method_const mc(23);
	cout << "the const age is : " << mc.getAge() <<endl;

	return 0;
}