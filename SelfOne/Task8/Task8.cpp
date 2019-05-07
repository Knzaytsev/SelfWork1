// Task8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 5;					//Количество букв
	static unsigned char source[n];				//Исходный текст
	static unsigned char table[26]{ 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
									'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd' };	//Алфавит
	static unsigned char result[n];				//Результат шифровки
	static unsigned char resultDec[n];			//Результат дешифровки
	for (int i = 0; i < n; ++i) {
		cin >> source[i];
	}
	__asm {
		push eax
		push ebx
		push ecx
		push esi
		xor esi, esi
		xor eax, eax
		xor ebx, ebx
		mov ecx, n
		lea ebx, table
		loopCipher:
			mov al, source[esi]
			sub al, 97
			xlat
			mov result[esi], al
			inc esi
		loop loopCipher
		xor esi, esi
		mov ecx, n
		loopDecipher:
			mov al, result[esi]
			sub al, 4
			cmp al, 97
			jae labelDec
			sub al, 97
			add al, 123
			labelDec:
			mov resultDec[esi], al
			inc esi
		loop loopDecipher
		push eax
		push ebx
		push ecx
		push esi
	}
	for (int i = 0; i < n; ++i) {
		cout << result[i];
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		cout << resultDec[i];
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
