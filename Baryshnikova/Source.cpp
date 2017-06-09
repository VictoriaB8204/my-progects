#include "Header.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <bitset>
#include <stdexcept>

using namespace std;

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int getI(char a) {
	for (int i = 0; i < letters.length(); i++)
		if (letters[i] == a)
			return i;
	throw new InvalidArgument;
};

string encode(string str) {
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		bitset<8> code = str[i];
		temp = temp + code.to_string();
	}
	int numEmpty = 0;
	string Empty = "00000000";
	while ((temp.length() % 6) != 0) {
		temp += Empty;
		numEmpty++;
	}//теперь в переменной temp имеем строку, состоящуюю из кодов символов строки str
	string tmp = "";
	string result = "";
	int i = 0;
	while (i < temp.length()) {
		while (tmp.length() < 6) {
			tmp += temp[i];
			i++;
		}
		bitset<6> B64code(tmp);
		result += letters[B64code.to_ulong()];
		tmp = "";
	}//получили в строке result перекодировку строки str с пустыми символами
	for (i = result.length() - 1; result.length() - i <= numEmpty; i--)
		result[i] = '=';
	return result;
};
string decode(string str) {
	string result = "";
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '=') {
			temp += "000000";
		}
		else {
			bitset<6> code(getI(str[i]));
			temp += code.to_string();
		}
	}
	if (temp.length() % 8 != 0)
		throw new InvalidArgument;
	string tmp = "";
	int i = 0;
	while (i < temp.length()) {
		while (tmp.length() < 8) {
			tmp += temp[i];
			i++;
		}
		bitset<8> code(tmp);
		result += char(code.to_ulong());
		tmp = "";
	}
	return result;
};