// Task10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	static unsigned int m;
	static unsigned int k;
	static unsigned int res;		//Результат
	static bool ok = true;			//Флаг
	cin >> m;
	cin >> k;
	__asm {
		push ebx
		push eax
		push ecx
		mov eax, k
		call checkK
		cmp ebx, 0
		je endComp
		mov eax, m
		call computeMul
		mov res, eax
		jmp endProg
		endComp:
		mov ok, 0 
		jmp endProg

		checkK:
			mov ebx, eax
			dec eax
			and eax, ebx
			xor ebx, ebx
			cmp eax, 0
			jne endProc
			inc ebx
			endProc:
		ret 

		computeMul:
			mov ecx, k
			mul ecx
		ret

		endProg:
		pop ebx
		pop eax
		pop ecx
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
