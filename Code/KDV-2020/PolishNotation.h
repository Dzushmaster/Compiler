#pragma once
#include "LT.h"
#include "IT.h"
#include <stack>
#include <queue>

namespace PN
{
	void workWithPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable);
	int PolishNotation(int lexPos, LT::LexTable& lextable, IT::IdTable idtable);
	int ChangeLex(int lexPos, int lexIndex, LT::LexTable& lextable, std::queue<LT::Entry> queue);
}
//Вызов PolishNotation из другой функции c помощью массива
//если дошли до =, то применяем польскую запись. В функцию отправляем номер позиции, где находится '='и тбалицы
//в этой функции цикл по while(lextable.table[i].lexema!=';')
//записываем первый символ,
//если он равен v или скобке, то записываем арифметический символ в стек, если не равен, то в массив
//если в стеке есть символ с таким же приоритетом, то сносим его в выходную строку
//если с приоритетом ниже, то просто записываем рядом
//если с приоритетом больше, то сразу сносим в строку


//при работе с функциями идет замена в таблице лексем функции на @
//с количеством параметров в ней, параметры описаны перед @, количество после