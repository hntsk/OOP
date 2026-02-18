#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string ERRORCOUNTINPUT = "Неверное количество входных данных";
const string ERROROTHERSYMBOLS = "Присутствуют посторонние символы, помимо цифр";
const string ERRORRANGENUMBER = "Число больше 255";
const string VALIDSYMBOLS = "0123456789";


string Bin2Dec(string number)
{
	int int_result = 0;
	string result;
	for (int i = 0; i < number.size(); i++)
	{
		int_result = ((int_result) << 1) | (number[i] - '0');
	}
	result = to_string(int_result);
	result.erase(0, result.find_first_not_of('0'));
	if (result == "")
	{
		result = "0";
	}
	return result;
}



string Dec2Bin(string number)
{
	string remains = "";
	int divisible = stoi(number);
	while (divisible != 0)
	{
		remains = to_string(divisible % 2) + remains;
		divisible = divisible / 2;
	}
	remains.insert(0, 8 - remains.length(), '0');
	return remains;
}


string Reverse(string number)
{
	reverse(number.begin(), number.end());
	return number;
}

string flipbyte(string number)
{
	number = Dec2Bin(number);
	number = Reverse(number);
	number = Bin2Dec(number);
	return number;
}


bool CheckOnCorrectInput(int argc, char* argv[])
{
	if (argc == 1 or argc > 2)
	{
		cout << ERRORCOUNTINPUT << endl;
		return false;
	}
	string number = argv[1];
	if (number.find_first_not_of(VALIDSYMBOLS) != string::npos)
	{
		cout << ERROROTHERSYMBOLS << endl;
		return false;
	}
	int check_number = stoi(argv[1]);
	if (check_number > 255)
	{
		cout << ERRORRANGENUMBER << endl;
		return false;
	}
	return true;
}


int main(int argc, char* argv[])
{
	if (CheckOnCorrectInput(argc, argv) == false)
	{
		return false;
	}
	string number;
	number = argv[1];
	cout << flipbyte(number);
	return 0;
}
