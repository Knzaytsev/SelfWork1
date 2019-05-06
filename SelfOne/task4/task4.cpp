﻿// task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	/*unsigned int n = 5;
	unsigned int m = 5;
	unsigned char num1[5];
	unsigned char num2[5];
	unsigned char res[6]{ 0,0,0,0,0,0 };*/
	const unsigned int n = 5;
	static unsigned int m = n;
	static unsigned char num1[n];
	static unsigned char num2[n];
	static unsigned char res[CHAR_MAX];
	for (int i = 0; i < n; ++i) {
		cin >> num1[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> num2[i];
	}
	/*for (int i = 0; i < m; ++i) {
		cin >> num2[i];
	}*/
	__asm {
		push eax
		push ecx
		push esi
		push esp
		xor eax, eax
		xor ecx, ecx
		xor esi, esi
		xor edi, edi
		mov edi, n
		mov ecx, n
		dec edi
		loopAddition:
			mov al, num1[edi]
			add al, ah
			add al, num2[edi]
			;add al, ah
			mov ah, 0
			aaa
			mov res[esi], al
			add res[esi], 48
			dec edi
			inc esi
		loop loopAddition
		cmp ah, 0
		je labelExit
		mov res[esi], ah
		add res[esi], 48
		inc esi
		labelExit:
		;mov n, esi
		mov m, esi
		pop eax
		pop ecx
		pop esi
		;pop esp
	}
	for (int i = m - 1; i >= 0; --i) {
		cout << res[i];
	}
	/*for (int i = n - 1; i >= 0; --i) {
		cout << res[i];
	}*/
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
