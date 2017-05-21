// Set.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Set {
	int value;
	Set* head;
public:
	Set() {
		this->value = 0;
		this->head = NULL;
	};
	~Set() {
		delete head;
		this->head = NULL;
	};
	void Print() {
		Set* curr = this->head;
		if (curr == NULL) {
			return;
		}
		else {
			while (curr->head != NULL) {
				cout << curr->value << "  ";
				curr = curr->head;
			}
			cout << curr->value << "  ";
		};
	};
	int Depth(){
		int depth = 0;
		Set* curr = this->head;
		while (curr != NULL){
			depth++;
			curr = curr->head;
		}
		return depth;
	};
	Set& operator +(int _value) {
		Set* curr = this->head;
		while (curr != NULL) {
			if (curr->value != _value)
				curr = curr->head;
			else
				return *this;
		}
		Set* tmp = new Set;
		tmp->value = _value;
		tmp->head = this->head;
		this->head = tmp;
		return *this;
	};
	Set& operator *(int _value) {
		if (this->head == NULL) {
			return *this;
		}
		Set* curr = this->head;
		Set* res = new Set;
		while (curr != NULL) {
			if (curr->value == _value) {
				*res = *res + _value;
				return *res;
			}
			else
				curr = curr->head;
		}
		return *res;
	};
	Set& operator =(Set& _set){
	if (*this == _set)
		return *this;
	else{
		this->head=NULL;
		Set* tmp = new Set;
		Set* curr = _set.head;
		while (curr != NULL){
			*tmp = *tmp + curr->value;
			curr = curr->head;
		};
		curr = tmp->head;
		while (curr != NULL){
			*this = *this + curr->value;
			curr = curr->head;
		};
		return *this;
	}
	};
	Set& operator =(int _value){
		if (*this == _value)
			return *this;
		else{
			this->head = NULL;
			*this = *this + _value;
			return *this;
		}
	};
	bool operator ==(Set& _b){
		if (this->head != NULL&&_b.head == NULL || this->head == NULL&&_b.head != NULL)
			return false;
		if (this->Depth() != _b.Depth())
			return false;
		bool res = false;
		Set* curr1 = this->head;
		Set* curr2 = _b.head;
		while (curr1 != NULL){
			while (curr2 != NULL&&!res){
				if (curr2->value != curr1->value){
					curr2 = curr2->head;
				}
				else
					res = true;
			}
			if (!res)
				return false;
			else{
				curr1 = curr1->head;
				res = false;
				curr2 = _b.head;
			}
		}
		return true;
	};
	bool operator ==(int _value){
		if (this->Depth() != 1)
			return false;
		Set* curr = this->head;
		if (curr->value == _value)
			return true;
		else
			return false;
	};

	friend Set& operator +(int _value, Set& _set);
	friend Set& operator +(Set& _s1, Set& _s2);
	friend Set& operator *(int _value, Set& _set);
	friend Set& operator *(Set& _s1, Set& _s2);
	friend bool operator ==(int _value, Set& _s);
};

bool operator ==(int _value, Set& _s){
	if (_s.Depth() != 1)
		return false;
	Set* curr = _s.head;
	if (curr->value == _value)
		return true;
	else
		return false;
};

Set& operator *(int _value, Set& _set) {
	if (_set.head == NULL) {
		return _set;
	}
	Set* curr = _set.head;
	Set* res = new Set;
	while (curr != NULL) {
		if (curr->value == _value) {
			*res = *res + _value;
			return *res;
		}
		else
			curr = curr->head;
	}
	return *res;
};

Set& operator *(Set& _s1, Set& _s2) {
	if (&_s1 == NULL) {
		return _s1;
	};
	if (&_s2 == NULL) {
		return _s2;
	};
	Set* res = new Set;
	Set* curr1 = _s1.head;
	Set* curr2 = _s2.head;
	while (curr2 != NULL) {
		while (curr1 != NULL) {
			if (curr1->value == curr2->value)
				*res = *res + curr2->value;
			curr1 = curr1->head;
		}
		curr1 = _s1.head;
		curr2 = curr2->head;
	}
	return *res;
};

Set& operator +(int _value, Set& _set) {
	Set* curr = _set.head;
	while (curr != NULL) {
		if (curr->value != _value)
			curr = curr->head;
		else
			return _set;
	}
	Set* tmp = new Set;
	tmp->value = _value;
	tmp->head = _set.head;
	_set.head = tmp;
	return _set;
};

Set& operator +(Set& _s1, Set& _s2) {
	if (&_s1 == NULL) {
		return _s2;
	};
	if (&_s2 == NULL) {
		return _s1;
	};
	Set* curr1 = _s1.head;
	Set* curr2 = _s2.head;
	while (curr2 != NULL) {
		while (curr1 != NULL) {
			if (curr1->value != curr2->value)
				curr1 = curr1->head;
			else {
				_s1 = _s1 + *curr2;
				return _s1;
			}
		}
		_s1 = _s1 + curr2->value;
		curr2 = curr2->head;
	}
	return _s1;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Set a;
	for (int i = 0; i < 10; i++) {
		a = i + a;
	}
	cout << "a:" << endl;
	a = a + 2;
	a.Print();
	cout << endl;

	Set b;
	for (int i = 9; i >=0; i--) {
		b = i + b;
	}
	cout << "b:" << endl;
	b.Print();
	cout << endl;

	a = 55;
	cout << "new a:" << endl;
	a.Print();
	system("pause");
	return 0;
}

