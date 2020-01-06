#pragma once


class method_const
{
private:
	int age;
	int num;

public:
	method_const(int age);

	int getAge() const;

	void setNum(int);

};