﻿// Task9In.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 256;
	const unsigned int m = 5;
	static unsigned char mas[m];
	static unsigned char bits[n];
	static unsigned char element;
	static bool res;
	cin >> element;
	for (int i = 0; i < m; ++i) {
		cin >> mas[i];
	}
	__asm {
		push esi
		push ecx
		push eax
		xor eax, eax
		xor esi, esi
		mov ecx, m
		loopInsert:
			mov al, mas[esi]
			mov bits[eax], 1
			inc esi
		loop loopInsert
		xor eax, eax
		mov al, element
		mov al, bits[eax]
		and al, 1
		mov res, al
		pop esi
		pop eax
		pop ecx
	}
	if (res) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
