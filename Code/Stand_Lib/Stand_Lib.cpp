#include <iostream>
#include <Windows.h>
#include <time.h>
extern "C"
{
	//standart
	unsigned int Kraft(unsigned int number,unsigned int power)	//pow(n,m)
	{
		std::cout << "Kraft(" << number << ',' << power << ")\n";
		return (unsigned int)pow((double)number,(double)power);
	}
	unsigned int Rot(unsigned int number)
	{
		std::cout << "Rot(" << number << ")\n";
		return (unsigned int)sqrt((double)number);
	}
	unsigned int Slump(int number)//number - до какого числа производить выбор
	{
		std::cout << "Slump(" << number  << ")\n";
		srand(time(NULL));
		return rand()%number;
	}
	//output
	void numout(int value)
	{
		std::cout << value << '\n';
	}
	void strlineout(char* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}
		std::cout << ptr << "\n\n";
	}
	void printError(char* error)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
		std::cout << error << '\n';
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	}
	//pause
	void system_pause()
	{
		system("pause");
	}
}