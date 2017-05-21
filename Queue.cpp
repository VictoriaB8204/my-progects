// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Queue {
	unsigned int MaxSize;
	unsigned int H;
	unsigned int T;
	float *queue;
public:
	Queue(unsigned int _MaxSize) {
		MaxSize = _MaxSize + 1;
		this->queue = new float[MaxSize];
		this->H = MaxSize / 2;
		this->T = (H - 1 + MaxSize) % MaxSize;
	};
	~Queue() {
		delete[] this->queue;
		queue = nullptr;
	};
	Queue(const Queue &_a) {
		MaxSize = _a.MaxSize;
		queue = new float[MaxSize];
		H = _a.H;
		T = _a.T;
		for (int i = H; i != (T + 1) % MaxSize; i = (i + 1) % MaxSize)
			queue[i] = _a.queue[i];
	};
	void Print(){
		if (T != (H - 1 + MaxSize) % MaxSize){
			for (int i = H; i != (T + 1) % MaxSize; i = (i + 1) % MaxSize)
				cout << i << "    " << queue[i] << endl;
		}
		else{
			cout << "Queue is empty" << endl;
		}
	};
	void Delete(){
		if (T != (H - 1 + MaxSize) % MaxSize)
			H = (H + 1) % MaxSize;
	};
	bool Add(float _elem) {
		if (T != (H - 2 + MaxSize) % MaxSize){
			T = (T + 1) % MaxSize;
			queue[T] = _elem;
			return true;
		}
		else{
			cout << "Element is not added: queue is full" << endl;
			return false;
		}
	};
	unsigned int NDReading(){
		if (T != (H - 1 + MaxSize) % MaxSize)
		return queue[H];
	};
	unsigned int Size(){
		return (T + 1 - H + MaxSize) % MaxSize;
	};
	Queue &operator=(Queue &_a){
		if (this != &_a){
			H = MaxSize / 2;
			T = (H - 1 + MaxSize) % MaxSize;
			int i = _a.H;
			while (T != (H - 2 + MaxSize) % MaxSize && Size()<_a.Size()){
				Add(_a.queue[i%_a.MaxSize]);
				i++;
			};
		};
		return *this;
	};
	friend bool operator ==(Queue &_a, Queue &_b);
};

bool operator ==(Queue &_a, Queue &_b){
	if (_a.Size() != _b.Size()){
		return false;
	}
	else{
		int j = _b.H;
		for (int i = _a.H; i != (_a.T + 1) % _a.MaxSize; i = (i + 1) % _a.MaxSize){
			if (_a.queue[i] != _b.queue[j])
				return false;
			j = (j + 1) % _b.MaxSize;
		}
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Queue a(10);
	/*for (int i = 10; i < 15; i++){
		a.Add(i);
	}*/
	Queue b(10);
	for (int i = 10; i < 15; i++){
		b.Add(i);
	}
	//a = b;
	//b.Add(20);
	//a.Delete();
	cout << "a:" << endl;
	a.Print();
	cout <<  endl;
	//a.Delete();
	cout << "b:" << endl;
	cout << endl;
	b.Print();
	if (a == b){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	/*cout << "b:" << endl;
	b.Print();
	a.Print();
	cout << a.Size()<< endl;*/
	system("pause");
	return 0;
}

