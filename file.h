#pragma once
#include <iostream>
#include <fstream>
#include"Pair.h"

using namespace std;

void randomize(Pair& p) {
	int x = rand() % 10;
	double y = (rand() % 1000) * 0.01;
	p = Pair(x, y);
}
bool write(int N) {
	fstream F1("file.txt", ios::out | ios::trunc);
	if (!F1) {
		cout << "�� ������� ������� ����!" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		Pair p_1;
		randomize(p_1);
		F1 << p_1 << endl;
	}
	F1.close();
	return 1;
}
bool print_file() {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "�� ������� ������� ����!" << endl;
		return 0;
	}

	Pair p_1;

	while (F1 >> p_1) {
		cout << p_1 << endl;
	}
	return 1;
}
void error(bool N) {
	if (!N) {
		cout << "���� �� ������" << endl;
	}
}
bool remove(int R) {
	fstream F1("file.txt", ios::in);
	if (!F1) {
		cout << "�� ������� ������� ����!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);

	Pair p_3;

	while (F1 >> p_3)
	{
		if ((p_3.getSecond() + p_3.getFirst()) >= R)
		{
			tmp << p_3 << endl;
		}
	}
	F1.close();
	tmp.close();
	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}

bool increase(int K) {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "�� ������� ������� ����!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);
	Pair p_4;

	while (F1 >> p_4) {
		p_4 = p_4 = p_4 + K;
		tmp << p_4 << endl;
	}

	F1.close();
	tmp.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}
bool add_el(int number, int quantity) {
	fstream F1("file.txt", ios::in);

	if (!F1) {
		cout << "�� ������� ������� ����!" << endl;
		return 0;
	}

	fstream tmp("temp.txt", ios::out | ios::trunc);

	Pair p_4;

	int counter = 0;

	while (F1 >> p_4) {
		counter++;
		tmp << p_4 << endl;

		if (counter == number) {
			for (int i = 0; i < quantity; i++) {
				Pair new_pair;
				randomize(new_pair);
				tmp << new_pair << endl;
			}
		}
	}

	if (counter < number)
		cout << "������� � ������� " << number << " �� ������!" << endl;

	F1.close();
	tmp.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");
	return 1;
}
int choosing() {
	cout << "�������� ��������" << endl;
	cout << "1 - ������� ���������� �����" << endl;
	cout << "2 - ������������ ���������� �����" << endl;
	cout << "3 - ������� ��������, ����� ����� ������� ������ ��������� ��������" << endl;
	cout << "4 - ��������� ��� ���� ����� �� K" << endl;
	cout << "5 - �������� K ������� ����� �������� � ������� N" << endl;
	cout << "0 - ���������� ������" << endl;
	int choice;
	do {
		cout << ">  ";
		cin >> choice;
	} while (choice < 0 || choice > 6);
	cout << endl;
	return choice;
}