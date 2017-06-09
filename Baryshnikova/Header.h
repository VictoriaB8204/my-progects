#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

class InvalidArgument {};

string encode(string str);
string decode(string str);