#pragma once
#include <iostream>
#include "Error.h"
#include "In.h"
#include "LT.h"
#include "IT.h"

namespace FST
{
	struct RELATION		//ребро:символ -> вершина графа переходов КА
	{
		char symbol;	//символ перехода
		short nnode;	//номер смежной вершины
		RELATION(char c=0x00, short ns=NULL);
	};
	struct NODE	//вершина графа переходов
	{
		short n_relation;//количество инцидентных ребер
		RELATION* relations;//инцидентные ребра
		NODE();
		NODE(short n, RELATION rel, ...);//количество ребер, список ребер
	};
	struct FST
	{
		char* string;	//цепочка
		short position;
		short nstates;	//количество состояний
		NODE* nodes;	//граф переходов
		short* rstates;//возможные состояния
		FST(char* s, short ns, NODE n, ...);
	};
	bool execute(FST& fst);
}
void choiceOfMachines(int wordSize, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable);
void choiceOfMachines(char symbol, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable);


