// Task9Bit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 256;
	const unsigned int m = 2;
	const unsigned int k = 4;
	static unsigned resn;
	static signed char sign;
	static unsigned char mas1[m];
	static unsigned char mas2[k];
	static unsigned char set1[n];
	static unsigned char set2[n];
	static unsigned char resset[n];
	for (int i = 0; i < m; ++i) {
		cin >> mas1[i];
	}
	cin >> sign;
	for (int i = 0; i < k; ++i) {
		cin >> mas2[i];
	}
	__asm {
		push esi
		push edi
		push eax
		push ecx
		xor eax, eax
		xor esi, esi
		xor edi, edi
		lea esi, mas1
		lea edi, set1
		mov ecx, m
		call copyMas
		lea esi, mas2
		lea edi, set2
		mov ecx, k
		call copyMas
		mov al, sign
		mov ecx, n
		xor esi, esi
		xor edi, edi
		cmp al, '+'
		jne labelNextOpMul
		loopPlus:
			mov al, set1[esi]
			or al, set2[esi]
			cmp al, 0
			je nextPlus
			mov eax, esi
			mov resset[edi], al
			inc edi
			nextPlus:
			inc esi
		loop loopPlus
		mov resn, edi
		jmp endProg
		labelNextOpMul:
		cmp al, '*'
		jne labelNextOpMinus
		loopMul:
			mov al, set1[esi]
			and al, set2[esi]
			cmp al, 0
			je nextMul
			mov eax, esi
			mov resset[edi], al
			inc edi
			nextMul:
			inc esi
		loop loopMul
		mov resn, edi
		jmp endProg
		labelNextOpMinus:
		cmp al, '-'
		jne labelNextOpIn
		loopMinus:
			mov al, set1[esi]
			push eax
			xor al, set2[esi]
			cmp al, 0
			je nextMinus
			pop eax
			cmp al, 0
			je nextMinus
			mov eax, esi
			mov resset[edi], al
			inc edi
			nextMinus:
			inc esi
		loop loopMinus
		mov resn, edi
		jmp endProg
		labelNextOpIn:
		jmp endProg

		copyMas:
			loopInsert:
				mov al, [esi]
				mov [edi + eax], 1
				inc esi
			loop loopInsert
		ret

		endProg:
		pop esi
		pop edi
		pop eax
		pop ecx
	}
	for (int i = 0; i < resn; ++i) {
		cout << resset[i] << ' ';
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
