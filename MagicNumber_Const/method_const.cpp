#include <iostream>
#include "method_const.h"


method_const::method_const(int age)
{
	this->age = age;
}

int method_const::getAge() const
{
	return age;
}

