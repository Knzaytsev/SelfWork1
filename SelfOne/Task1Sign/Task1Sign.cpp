// Task1Sign.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 4;
	const unsigned int m = 6;
	static signed int A[n][m];
	static unsigned char min_row = 1;
	static unsigned char max_col = 1;
	unsigned short divider_row = n * m;
	unsigned char divider_col = 4;
	static unsigned int offs = m * 4;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> A[i][j];
		}
	}

	__asm {
		push eax
		push esi
		push edi
		push ecx
		push ebx
		push edx
		xor ecx, ecx
		xor eax, eax; minium
		xor ebx, ebx; maximum
		xor edx, edx; temp
		xor esi, esi
		xor edi, edi
		lea esi, A
		mov ecx, n; 4
		labelExternal:
			push ecx
			xor ebx, ebx
			mov eax, [esi]
			mov edi, 4
			mov ecx, m
			dec ecx
			labelInternal:
			mov edx, [edi + esi]
			cmp eax, edx
			jle minL
			mov eax, edx
			mov ebx, edi
			minL :
			add edi, 4
			dec ecx
			cmp ecx, 0
			jne labelInternal
			push esi
			xor esi, esi
			lea esi, A
			mov ecx, n
			labelFind:
			mov edx, [esi + ebx]
			cmp eax, edx
			jge label
			jmp newLoop
			label:
			add esi, offs
			dec ecx
			cmp ecx, 0
			jne labelFind
			xor eax, eax
			; mov min_row, esi
			mov eax, ebx
			div divider_col
			add al, 49
			mov max_col, al
			; mov max_col, ebx
			jmp labelExit
			newLoop :
			inc min_row
			pop esi
			pop ecx
			add esi, offs
			dec ecx
			cmp ecx, 0
			jne labelExternal
			mov min_row, 0
			mov max_col, 48
			labelExit:
			pop eax
			pop esi
			pop edi
			pop ecx
			pop ebx
			pop edx
	}

	cout << min_row + 0 << " " << max_col;
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
