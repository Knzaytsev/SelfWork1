// Task7_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 5;			//Размер строки
	const unsigned int m = 2;			//Размер подстроки
	static unsigned char str[n];		//Строка
	static unsigned char substr[m];		//Подстрока
	static signed int res;				//Результат
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> substr[i];
	}
	__asm {
		push ecx
		push eax
		push edi
		push esi
		mov al, substr[0]
		lea edi, str
		mov ecx, n
		cld
		repeat:
repnz	scas str
		jne notFound
		sub ecx, n
		neg ecx
		dec ecx
		lea edi, str[ecx]
		lea esi, substr
		push ecx
		mov ecx, m
		cld
repe	cmpsb
		je found
		pop ecx
		inc ecx
		cmp ecx, n
		jae notFound
		lea edi, str[ecx]
		sub ecx, n
		neg ecx
		;inc ecx
		cld
		jmp repeat
		notFound:
		mov res, -1
		jmp quit
		found:
		pop ecx
		inc ecx
		mov res, ecx
		quit:
		cld
		pop eax
		pop ecx
		pop edi
		pop esi
	}
	cout << res + 0;
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
