#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

bool CheckingNumbers(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isdigit(a)) {
			b = false;
			break;
		}
	}
	return b;
}

int main() {
	srand(time(0));
	char ch;
	string s;
	int size, item;
	vector<int> basa;
	do {
		cout << "1 - Enter by hand\n2 - random\n";
		ch = _getch();
		switch (ch)
		{
		case'1':
			do {
				cout << "Put vector size: ";
				cin >> s;
				if (CheckingNumbers(s))
					size = stoi(s);
				else
					cout << "Its should be a digit!\n";
			} while (!CheckingNumbers(s));
			basa.resize(size);
			for (int i = 0; i < size; i++) {
				do {
					cout << "Put digit: ";
					cin >> s;
					if (CheckingNumbers(s))
						item = stoi(s);
					else
						cout << "Its should be a digit!\n";
				} while (!CheckingNumbers(s));
				basa[i] = item;
			}
			break;
		case'2':
			basa.resize(1 + rand() % 30);
			for (int i = 0; i < basa.size(); i++) {
				basa[i] = 1 + rand() % 100;
			}
			break;
		}
		for (int a : basa) {
			cout << a << "\t";
		}
	} while (ch != '1' && ch != '2');
}