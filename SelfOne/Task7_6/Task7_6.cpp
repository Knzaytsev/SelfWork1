// Task7_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 4;
	static unsigned char mas1[n];
	static unsigned char mas2[n];
	static signed int index;
	for (int i = 0; i < n; ++i) {
		cin >> mas1[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> mas2[i];
	}
	__asm {
		push ecx
		push esi
		push edi
		push ebx
		mov ebx, n
		lea esi, mas1
		lea edi, mas2
		mov ecx, n
		cld
repe	cmps
		jne notEqual
		mov ecx, n
		inc ecx
		notEqual:
		sub ebx, ecx
		mov index, ebx
		pop ecx
		pop esi
		pop edi
		pop ebx
	}
	cout << index;
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
