// Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned n = 2;
	static unsigned char num1[n];
	static unsigned char num2[n];
	static unsigned char res[CHAR_MAX];
	for (int i = 0; i < n; ++i) {
		cin >> num1[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> num2[i];
	}
	__asm {
		push eax
		push ecx
		push esi
		push ebx
		xor ebx, ebx
		mov ecx, n
		mov esi, n
		dec esi
		loopSub:
		mov al, num1[esi]
			sub al, ah
			sub al, num2[esi]
			mov ah, 0
			aas
			cmp ah, 255
			jne labelOk
			mov ah, 1
			labelOk:
			mov res[esi], al
			add res[esi], 48
			dec esi
		loop loopSub
		labelContinue:
	}
	for (int i = 0; i < n; ++i) {
		cout << res[i];
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
