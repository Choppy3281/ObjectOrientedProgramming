// Homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>
using namespace std;


bool test_pal(int start, int  end, string line) {
	if (start >= end) {
		return true;
	}
	if (line[start] == line[end]) {
		start++;
		end--;
		test_pal(start, end, line);
	}
	else {
		return false;
	}
}

void reverse(string &line, int l, int h){
	if (l < h) {
		swap(line[l], line[h]);
		reverse(line, l + 1, h - 1);
	}
}

int main() {
	string line;
	ifstream file;
	file.open("Homework 3 Data.txt");

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, line);
				try
				{
					for (int i = 0; i < line.length(); i++) {
						if (isdigit(line[i]) > 0)
						{
							throw invalid_argument(line + " Error. Digit found in string");
						}
					}
				}
				catch(invalid_argument e)
				{
					cout << e.what() << endl;
					continue;
				}
				bool result = test_pal(0, line.length() - 1, line);
				if (result) {
					cout << line << " This is a palindrome." << endl;
				}
				else {
					cout << line << " This is not a palindrome. ";
					reverse(line, 0, line.length() - 1);
					cout << line << endl;
				}
			}
			file.close();
		}
		else cout << "Unable to open file";

		system("pause");
	return 0;
}