// Task10Div.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	static unsigned int m;
	static unsigned char k;
	static unsigned int res;
	static bool ok = true;
	cin >> m;
	cin >> k;
	__asm {
		push ebx
		push eax
		push ecx
		mov al, k
		sub al, 48
		call checkK
		cmp ebx, 0
		je endComp
		mov eax, m
		call computeMul
		mov res, eax
		jmp endProg
		endComp:
		mov ok, 0 
		pop ebx
		pop eax
		pop ecx
		jmp endProg

		checkK:
			mov bl, al
			dec al
			and al, bl
			xor ebx, ebx
			cmp al, 0
			jne endProc
			inc ebx
			endProc:
		ret 

		computeMul:
			mov cl, k
			sub cl, 48
			shr eax, cl
		ret

		endProg:
	}
	if (ok) {
		cout << res;
	}
	else {
		cout << "Wrong k!";
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
