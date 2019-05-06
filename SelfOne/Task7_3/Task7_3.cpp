﻿// Task7_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 5;
	static unsigned char mas[n];
	static signed char num;
	for (int i = 0; i < n; ++i) {
		cin >> mas[i];
	}
	cin >> num;
	__asm {
		push ecx
		push esi
		push edi
		push eax
		lea edi, mas
		mov al, num
		mov ecx, n
repnz	scas mas
		mov eax, n
		je found
		mov ecx, n
		inc ecx
		found:
		sub eax, ecx
		mov num, al
		pop ecx
		pop esi
		pop edi
		pop eax
	}
	cout << num + 0;
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