#pragma once
#define ID_MAXSIZE 15				//максимальное количество символов в идентификаторе
#define TI_MAXSIZE 4096				//максимальное количество строк в таблице идентификаторов
#define TI_INT_DEFAULT 0x00000000	//значение по умолчанию дл€ типа integer
#define TI_STR_DEFAULT 0x00			//значение по умолчаню дл€ типа string
#define TI_NULLIDX 0xffffffff		//нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE 255
#define PREFIX_SIZE 15
#include <iostream>
namespace IT
{
	enum IDDATATYPE {INT = 1,UINT = 2 ,STR = 3, SYMB = 4};//типы данных integer и string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, K = 5};//типы идентификаторов: переменна€, функци€, параметр, литерал, сторонн€€ функци€
	struct Entry						//строка таблицы идентификаторов
	{
		int idxfirstLE;								//индекс первой строки в таблице лексем
		char id[ID_MAXSIZE+1];						//идентификатор(автоматически усекаетс€ до ID_MAXSIZE)
		char prefix[PREFIX_SIZE+1];					//используетс€ дл€ определени€ области видимости
		short countParam = 0;							
		IDDATATYPE iddatatype;						//тип данных
		IDTYPE idtype;								//тип идентификатора
		union
		{
			int vint;
			char symb;
			struct
			{
				char ken;						//количество символов в string
				char str[TI_STR_MAXSIZE - 1];	//символы string
			}vstr[TI_STR_MAXSIZE];				//значение string
		}value;//значение идентификатора
	};
	struct IdTable				//экземпл€р таблицы идентификаторов
	{
		int maxsize;			//емкость таблицы идентификаторов <TI_MAXSIZE
		int size;				//текущий размер таблицы идентификаторов < maxsize
		Entry* table;			//массив строк таблицы идентификаторов
	};
	IdTable Create(				//создать таблицу идентификаторов
		int size				//емкость таблицы идентификаторов
	);
	void Add(					//добавить строку в таблицу идентификаторов
		IdTable& idtable,		//экземпл€р таблицы идентификаторов
		Entry entry					// номер получаемой строки
	);
	Entry GetEntry(				//получить строку таблицы идентификаторов
		IdTable& idtable,		//экземпл€р таблицы идентификаторов
		int n		//идентификатор
	);
	bool IsId(					
		Entry& elemOfTable,			//экземпл€р таблицы идентификаторов
		Entry elemTable
		);
	bool RightID(Entry elemOfTable, char* id, char* prefix);
	bool RightID(Entry elemOfTable, char* id);
	int GetIdxTI(const IdTable& idtable,char* word, char* prefix);
	bool IsOtherFunc(Entry&, Entry);
	bool LitIsRepeated(Entry& elemOfTable, char lit[ID_MAXSIZE]);
	bool LitIsRepeated(Entry& elemOfTable, int lit);
	void Delete(IdTable& idtable);//удалить таблицу лексем(освободить пам€ть)
}