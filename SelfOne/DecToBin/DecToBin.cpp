// DecToBin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const unsigned int n = 4;
	unsigned int multiple = 10;
	unsigned int divider = 2;
	static unsigned char str[n];
	static unsigned char res[CHAR_MAX];
	static signed int resultd;
	static signed char resultb;
	static signed short resultw;
	static bool overb;
	static bool overw;
	static bool overd;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}
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
		mov ecx, n
		cmp str[0], '+'
		jne labelNextCheck
		dec ecx
		inc esi
		jmp loopNumber
		labelNextCheck:
		cmp str[0], '-'
		jne loopNumber
		dec ecx
		inc esi
		loopNumber:
			mov dl, str[esi]
			inc esi
			sub dl, 48
			add al, dl
			mul multiple
		loop loopNumber
		div multiple
		cmp str[0], 45
		jne labelResult
		neg eax
		labelResult:
		mov resultd, eax
		mov resultw, ax
		mov resultb, al
		pop ecx
		pop eax
		pop esi
		pop edx
		pop ebx
	}
	cout << "Double word: " << resultd << '\n';
	cout << "Word: " << resultw << '\n';
	cout << "Byte: " << resultb + 0;
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
