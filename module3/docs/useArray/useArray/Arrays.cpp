/* This program demonstrates how to use arrays.

   Written by: Li Liang
   Date: 09/20/2009

   Sources: None
*/

#include <iostream>                 
#include <string>                   

using namespace std;  

const int MONTH_IN_YEAR = 12;
const int LONG_MONTH = 31;

int main ()
{
	int			daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char		monthNames[][MONTH_IN_YEAR] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int			month;
	int			monthIndex;
	int			index;
	int			numLongMonth;

	//read in the month. You should do error checking for legal integer and legal month number here
	cout << endl << "Please enter the month: (1-12) ";
	cin >> month;	

	//access individual element of the array. Note array index starts from 0
	monthIndex = month - 1;
	cout << endl << "The number of days in " << monthNames[monthIndex] << " is " << daysInMonth[monthIndex] << endl;

	//find out how many long month after this input month. Use a for loop to step through an array
	numLongMonth = 0;
	for (index=monthIndex+1; index<MONTH_IN_YEAR; index++)
	{
		if (daysInMonth[index] == LONG_MONTH)
			numLongMonth++;
	}

	//display how many 31-day month after the input month
	if(numLongMonth == 0 || numLongMonth == 1)
		cout << endl << "There is " << numLongMonth << " 31-day month after " << monthNames[monthIndex] << endl;
	else
		cout << endl << "There are " << numLongMonth << " 31-day months after " << monthNames[monthIndex] << endl;
	
    return 0;
}


