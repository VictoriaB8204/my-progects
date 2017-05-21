// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <string>  
#include<cmath> 
#include <iostream>

using namespace std;

struct Product{
	unsigned int price = 0;
	string name;
	int status = 0;
	Product(){
		this->name = "";
		this->price = 0;
		this->status = 0;
	};
	Product(unsigned int price, string name){
		this->name = name;
		this->price = price;
		this->status = 0;
	};
};

class Catalog{
	unsigned int size = 0;
	Product *table;
	int hesh1(string Key){
		return Key.size() % size;
	};
	int hesh2(unsigned int i, unsigned int j){
		return (i + j*j) % size;
	};
public:
	Catalog(unsigned int _size){
		this->size = _size;
		this->table = new Product[size];
	}

	~Catalog(){
		delete[](this->table);
	};

	Product Element(int i){
		Product tmp;
		if (i < size){
			tmp.name = this->table[i].name;
			tmp.price = this->table[i].price;
			return tmp;
		}
		else{
			cout << "Product is not found" << endl;
			system("pause");
			return tmp;
		}
	};

	string DelSpace(string _name){
		while (_name[_name.size() - 1] == ' '){
			_name.erase(_name.size() - 1, 1);
		};
		return _name;
	}

	bool Add(string _name, unsigned int _price){
		if (_name != ""){
			if (Search(_name) < 0){
				int i = hesh1(_name);
				int j = 0;
				while (true) {
					if (!(this->table[i].status == 1)) {
						this->table[i].price = _price;
						this->table[i].name = _name;
						this->table[i].status = 1;
						return true;
					}
					else {
						j++;
						i = hesh2(i, j);
						if (i == hesh1(_name)){
							 cout << "Product " << _name << " " << _price << " is not hashed" << endl;
							//system("pause");
							return false;
						}
					}
				}
			}
			else
				cout << "Product with such name exists" << endl;
		}
		else
			cout << "Product is not hashed: name=''" << endl;
	};

	int NotFound(){
	//	cout << "Product is not found" << endl;
		return -1;
	};

	int Search(string _name){
		_name = DelSpace(_name);
		int i = hesh1(_name);
		int j = 0;
		while (true){
			switch (this->table[i].status){
			case 0:
				return NotFound();
				break;
			case 2:
				j++;
				i = hesh2(i, j);
				if (i == hesh1(_name))
					return NotFound();
				break;
			case 1:
				if (DelSpace(this->table[i].name) == _name){
					return i;
				}
				else {
					j++;
					i = hesh2(i, j);
					if (i == hesh1(_name))
						return NotFound();
				};
				break;
			}
		}
	};

	void Delete(string _name, unsigned int _price){
		int i = Search(_name);
		if (i >= 0&&this->table[i].price==_price)
			this->table[i].status = 2;
	}

	void Print(){
		cout << "  Name       Price" << endl;
		for (int i = 0; i < size; i++){
			if (table[i].status == 1){
				if (table[i].name.size() < 14)
					for (int j = 1; j < 14 - table[i].name.size(); j++)
						table[i].name = table[i].name + " ";
				cout << i << "  " << table[i].name << " " << table[i].price << endl;
			}
			else{
				cout << i << "              " << 0 << endl;
			}
		};
	};
};
int _tmain(int argc, _TCHAR* argv[])
{
	/*setlocale(LC_ALL, "Russian"); int i = 0;
	cout << "Введите размер таблицы" << endl;
	int size;
	cin >> size;
	if (size <= 0){
		cout << "Ошибка: Размер таблицы <= 0" << endl;
		system("pause");
		return 0;
	}
	else {*/


		Catalog table(20);

		unsigned int price;

		string name = "AAAA";
		string name1 = "BBBBBBB";

		for (int i = 1; i <11; i++) {
			table.Add(name, 10 + i);
			name [3]++;
			table.Add(name1, 40 + i);
			name1 [0]++;

			//table.Print();
		}
		table.Print();
		cout << endl <<"_________________________________________________________"<< endl;
		//system("pause");
		

		 name = "AAAA";
		 name1 = "BBBBBBB";

		for (int i = 1; i <11; i=i+2) {
			cout << "del  " << name << ' ' << i<<endl;
			table.Delete(name);
			name[3]=name[3]+2;
			
			cout << "del  " << name1 << ' ' << i+30 << endl;
			table.Delete(name1);
			name1[ 0]=name1[0]+2;
		
		};
			

	
		table.Print();
		




	 name = "AAAA";
		 name1 = "BBBB";

		for (int i = 1; i < 21; i++) {
			table.Add(name, 10 + i);
			name += "A*";
			table.Add(name1, 40 + i);
			name1 += "B*";
			//table.Print();
		}
		table.Print();
		cout << endl << "_________________________________________________________" << endl;
		//system("pause");

		/*
		for (int i = 1; i < 5; i++) {
			table.Delete(name, i * 10);
			name += "oo";
			table.Print();
			system("pause");
		}
		table.Print();
		system("pause");
	}*/

		system("pause");
}

