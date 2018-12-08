#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;



/*Run Length Encoding
Given an input string, write a function that returns the Run Length Encoded string for the ineamput string.
For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”.*/

string RunLengthEncoding(string inStr)
{
	string newString = "";
	
	int length = 1;
	for (int i = 0; i <= inStr.size(); i++)
	{
		if (i == 0)
			newString = inStr[i];
		else if (inStr[i - 1] != inStr[i])
		{
			newString += to_string(length) + inStr[i];
			length = 1;
				
		}
		else length++;
	}
	return newString;
}


int main()
{
	string resultStr=RunLengthEncoding("wwwwaaadexxxxxx");
	cout << resultStr;
	return 0;
}

