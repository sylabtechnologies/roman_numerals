// test_roman.cpp : NEED 10 MIN MORE TO COMPLETE THE SORT
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <set>
using namespace std;

typedef vector<string>			RoyalNames;
typedef RoyalNames::iterator    R_Iter;

struct Royal_Entry {
	string name;
	string roman_num;
	int number;
	bool operator< (const Royal_Entry& right) const
	{
		if (name == right.name)
			return number < right.number;
		else
			return name < right.name;
	}
};
typedef vector<Royal_Entry>			Name_and_Number;
typedef Name_and_Number::iterator   NN_Iter;

int roman_val(char);
int roman2dec(string);
Name_and_Number get_sorted(RoyalNames);

int main()
{
	string str = "xx";
	RoyalNames names;
	Name_and_Number names2;

	// Enter French monarchs as name/roman numeral
	do
	{
		getline(cin, str);
		if (str != "go")
		{
			names.push_back(str);
		}
	} while (str != "go");

	cout << endl;

	names2 = get_sorted(names);

	for (NN_Iter iter = names2.begin(); iter != names2.end(); ++iter)
	{
		cout << iter->name << " " << iter->number;
		cout << endl;
	}

	return 0;
}

Name_and_Number get_sorted(RoyalNames names)
{
	Name_and_Number result;

	for (size_t i = 0; i < names.size(); i++)
	{
		Royal_Entry elem;
		stringstream mystream(names[i]);

		mystream >> elem.name >> elem.roman_num;
		elem.number = roman2dec(elem.roman_num);

		result.push_back(elem);
	}

	sort(result.begin(), result.end());

	return result;
}


int roman_val(char r)
{
	switch (r)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: break;
	}

	return -1;
}

int roman2dec(string myinput)
{
	int result = 0;

	// seek roman numerals
	for (size_t i = 0; i < myinput.length(); i++)
	{
		int val1 = roman_val(myinput[i]);

		// test for subractive notation
		if (i + 1 < myinput.length())
		{
			// value of next symbol
			int val2 = roman_val(myinput[i + 1]);

			if (val1 >= val2)
			{
				result = result + val1;
			}
			else
			{
				result = result + val2 - val1;
				i++;
			}
		}
		else
		{
			result = result + val1;
		}
	}

	return result;
}

