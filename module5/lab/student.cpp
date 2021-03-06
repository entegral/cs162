#include "student.h"
#include <cstring>
//implement the required 3 functions here

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}

Student::Student(const char initId[], double gpa)
{								// initilize a newly created student object with passed in ID#
	strcpy(id, initId);
	this->gpa = gpa;
}

bool Student::isLessThanByID(const Student &aStudent) const
{
	if (std::strcmp(id, aStudent.id) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::isLessThanByGpa(const Student &aStudent) const
{
	if (gpa < aStudent.gpa)
	{
		return true;
	}
	else
	{
		return false;
	}
}
