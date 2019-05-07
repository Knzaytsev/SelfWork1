// SelfOne.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 4; //Строки
	const unsigned int m = 4; //Столбцы
	static unsigned int A[n][m]; //Массив размера двойного слова
	static unsigned char min_row; //Индекс строки
	static unsigned char max_col; //Индекс столбца
	unsigned int k = m * 4;		  //Переменная для перехода на следующую строку
	unsigned short divider_row = 16; //Переменная для приведения в нормальный вид индекс строки
	unsigned short divider_col = 4;  //Переменная для приведения в нормальный вид индекс столбца
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
		mov ecx, n
		loopExternal:
		push ecx
			mov eax, A[esi]
			mov edi, 4
			mov ecx, m
			dec ecx
			loopInternal :
			mov edx, A[edi + esi]
			cmp eax, edx
			jbe minL
			mov eax, edx
			mov ebx, edi
			minL:
			add edi, 4
			loop loopInternal
			push esi
			xor esi, esi
			mov ecx, n
			loopFind :
				mov edx, A[esi + ebx]
				cmp eax, edx
				jae label
				jmp newLoop
				label:
				add esi, k 
				loop loopFind
				xor eax, eax
				pop esi
				mov eax, esi
				div divider_row
				add al, 49
				mov min_row, al
				xor eax, eax
				;mov min_row, esi
				mov eax, ebx
				div divider_col
				add al, 49
				mov max_col, al
				;mov max_col, ebx
				jmp labelExit
				newLoop:
				pop esi
				pop ecx
				add esi, k
			loop loopExternal
			mov min_row, 48
			mov max_col, 48
			labelExit:
			pop eax
			pop esi
			pop edi
			pop ecx
			pop ebx
			pop edx
	}

	cout << min_row << " " << max_col;
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
