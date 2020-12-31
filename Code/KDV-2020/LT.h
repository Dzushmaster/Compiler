#pragma once
#include <fstream>
#include <string>
#include "Lexemes.h"
#define LEXEMA_FIXSIZE 1				//фиксированный размер лексемы
#define LT_MAXSIZE 4096					//максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX 0xffffffff		//нет элемента таблицы идентификаторов
#define AMOUNTEXPRESSIONS 10

//подключить в in эту библиотеку и если символ не нужно разбирать, то просто записать эту лексему
namespace LT//таблица лексем
{
	struct Entry
	{
		char lexema;//лексема
		char arithmeticSymbol;
		int sn;						//номер строки в исходном тексте
		int idxTI;					//индекс в таблице идентификаторов или LT_TI_NULLIDX
		int priority;				//приоритет операции
	};
	struct LexTable//экземпл€р таблицы лексем
	{
		int maxsize;//емкость таблицы лексем < LT_MAXSIZE 
		int size;//текущий размер таблицы лексем <maxsize
		Entry* table;//массив строк таблицы лексем
	};

	LexTable Create(//создать таблицу лексем
		int size//емкость таблицы лексем < LT_MAXSIZE
	);
	void Add(		//добавить строку в таблицу лексем
		LexTable& lextable, //экземпл€р таблицы лексем
		Entry entry			//строка таблицы лексем
	);
	Entry GetEntry(//получить строку таблицы лексем
		LexTable& lextable,//экземлп€р таблицы лексем
		int n//номер получаемой строки
	);
	void Delete(LexTable& lextable);//удалить таблицу лексем(освободить пам€ть)
};
