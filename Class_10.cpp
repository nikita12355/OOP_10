#include<iostream>
#include <fstream>
#include"Pair.h"
#include"file.h"
using namespace std;
int main() {
	system("chcp 1251 > NULL");
	srand(time(NULL));
	int n;
	do {
		cout << "Введите количество элементов: ";
		cin >> n;
	} while (n < 1);

	cout << endl;
	error(write(n));
	bool flag = true;
	while (flag) {
		int current_action = choosing();
		int tmp_1;
		double tmp_2;

		Pair p_2;
		switch (current_action) {
		case 1:
			cout << "Текущее содержимое файла" << endl;
			error(print_file());
			cout << endl;
			break;
		case 2:
			do {
				cout << "Введите количество элементов: ";
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(write(tmp_1));
			break;
		case 3:
			cout << "Введите значение, значения больше которого будут удалены: " << endl;
			int K;
			cin >> K;
			error(remove(K));
			break;
		case 4:
			cout << "Введите значение, которое будет добавлено ко всем записям: " << endl;
			int R;
			cin >> R;
			error(increase(R));
			cout << endl;
			break;
			
		case 5:
			int N;
			do {
				cout << "Введите номер, после которого необходимо ввести K элементов" << endl;
				cin >> N;
			} while (N < 1);

			do {
				cout << "Введите количество элементов, которые необходимо добавить: " << endl;
				cin >> tmp_1;
			} while (tmp_1 < 1);
			error(add_el(N, tmp_1));
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}