// Task6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 5;				//Количество цифр в числе
	const unsigned int m = n * 4;			//Количество цифр в BCD-числе
	static unsigned char num1[n];			//Первое число
	static unsigned char num2[n];			//Второе число
	static unsigned char num1BCD[m];		//Первое BCD-число
	static unsigned char num2BCD[m];		//Второе BCD-число
	static unsigned char divider = 2;		//Делитель для перевода
	static unsigned char checker = 4;		//Делитель для проверки
	static signed char res = 0;				//Результирующая переменная
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
		push edi
		mov ecx, n
		mov esi, n
		mov edi, m
		dec edi
		dec esi
		loopTranslateNum1:
			mov al, num1[esi]
			labelInternalNum1:
			div divider
			mov num1BCD[edi], ah
			add num1BCD[edi], 48
			dec edi
			push eax
			mov eax, edi
			inc eax
			div checker
			cmp ah, 0
			pop eax
			jne labelInternalNum1
		dec esi
		loop loopTranslateNum1
		mov esi, n
		mov ecx, n
		mov edi, m
		dec edi
		dec esi
		loopTranslateNum2:
			mov al, num2[esi]
			labelInternalNum2:
			div divider
			mov num2BCD[edi], ah
			add num2BCD[edi], 48
			dec edi
			push eax
			mov eax, edi
			inc eax
			div checker
			cmp ah, 0
			pop eax
			jne labelInternalNum2
		dec esi
		loop loopTranslateNum2
		mov ecx, m
		mov esi, -1
		xor eax, eax
		loopCmp:
			inc esi
			mov al, num1BCD[esi]
			cmp num2BCD[esi], al
			jnbe labelMinus
			mov res, 1
			jnae labelRes
			mov res, 0
		loop loopCmp
		jmp labelRes
		labelMinus:
		mov res, -1
		labelRes:
		pop eax
		pop ecx
		pop esi
		pop edi
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
