// Task9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 3;
	const unsigned int m = 3;
	static unsigned char mas1[n];
	static unsigned char mas2[m];
	static unsigned char resmas[n + m];
	static unsigned char sign;
	static unsigned int k;
	for (int i = 0; i < n; ++i) {
		cin >> mas1[i];
	}
	cin >> sign;
	for (int i = 0; i < m; ++i) {
		cin >> mas2[i];
	}
	__asm {
		push eax
		push ecx
		push edi
		push esi
		push ebx
		xor ebx, ebx
		mov al, sign
		xor esi, esi
		cmp al, 43
		jne otherOpMul
		mov ecx, n
		loopCheckMas1:
			cld
			mov al, mas1[esi]
			lea edi, resmas
			push ecx
			mov ecx, ebx
			inc ecx
repnz		scas resmas
			je labelNextMas1
			mov resmas[ebx], al
			inc ebx
			labelNextMas1:
			pop ecx
			inc esi
		loop loopCheckMas1
		xor esi, esi
		mov ecx, m
		loopCheckMas2:
			cld
			mov al, mas2[esi]
			lea edi, resmas
			push ecx
			mov ecx, ebx
			inc ecx
repnz		scas resmas
			je labelNextMas2
			mov resmas[ebx], al
			inc ebx
			labelNextMas2:
			pop ecx
			inc esi
		loop loopCheckMas2
		jmp quit
		otherOpMul:
		cmp al, 42
		jne otherOpMin
		mov ecx, n
		loopMul:
			cld
			lea edi, resmas
			mov al, mas1[esi]
			push ecx
			mov ecx, ebx
			inc ecx
repnz		scas resmas
			je nextEl
			cld
			lea edi, mas2
			mov ecx, m
repnz		scas mas2
			jne nextEl
			mov resmas[ebx], al
			inc ebx
			nextEl:
			pop ecx
			inc esi
		loop loopMul
		jmp quit
		otherOpMin:
		cmp al, 45
		jne otherOpIn
		mov ecx, n
		loopMinus:
			cld
			mov al, mas1[esi]
			lea edi, resmas
			push ecx
			mov ecx, ebx
			inc ecx
repnz		scas resmas
			je nextElMinus
			cld
			lea edi, mas2
			mov ecx, m
repnz		scas mas2
			je nextElMinus
			mov resmas[ebx], al
			inc ebx
			nextElMinus:
			pop ecx
			inc esi
		loop loopMinus
		jmp quit
		OtherOpIn:
		mov ecx, ecx
		quit:
		mov k, ebx
		pop eax
		pop ecx
		pop edi
		pop esi
	}
	for (int i = 0; i < k; ++i) {
		cout << resmas[i] << ' ';
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
