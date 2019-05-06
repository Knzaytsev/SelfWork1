// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	static unsigned int n;
	static signed int numb;
	unsigned int multiple = 10;
	unsigned int divider = 2;
	static unsigned char res[CHAR_MAX];
	cin >> numb;
	_asm {
		push ecx
		push eax
		push esi
		push edx
		push ebx
		xor eax, eax
		xor esi, esi
		xor ecx, ecx
		xor edx, edx
		xor ebx, ebx
		mov eax, numb
		cmp eax, 0
		jge labelDiv
		inc ebx
		neg eax
		labelDiv:
			div multiple
			mov res[esi], dl
			add res[esi], 48
			xor edx, edx
			inc esi
			cmp ax, 0
			jne labelDiv
		cmp ebx, 0
		je labelAddPlus
		mov res[esi], 45
		jmp labelContinue
		labelAddPlus:
		mov res[esi], 43
		labelContinue:
		mov n, esi
		pop ecx
		pop eax
		pop esi
		pop edx
		pop ebx
	}
	for (int i = n; i >= 0; --i) {
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
