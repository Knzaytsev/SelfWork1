// Task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const unsigned int n = 5;
	const unsigned int m = 15;
	static unsigned char mas1[n];
	static unsigned char mas2[m];
	static unsigned char num;
	static signed char index;
	for (int i = 0; i < n; ++i) {
		cin >> mas1[i];
	}
	cin >> num;
	/*for (int i = 0; i < n; ++i) {
		cin >> mas2[i];
	}*/
	__asm {
		; mov edi, offset mas1
		lea edi, mas1
		mov al, num
		mov ecx, n
		; cld
		std
;repne	scas mas1
repe	scas mas1
		je found
;rep		movs mas2, mas1
		mov ecx, n
		inc ecx
		found:
		mov ebx, n
		sub ebx, ecx
		mov index, bl
	}
	cout << index + 0;
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
