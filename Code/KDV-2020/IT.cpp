#include "IT.h"
#include "LT.h"
#include "Error.h"

using namespace IT;
IdTable IT::Create(int size)
{
	if (size > TI_MAXSIZE)
		throw ERROR_THROW(123);
	IdTable idtable;
	idtable.maxsize =size;
	idtable.size = 0;
	idtable.table = new Entry[size];
	return idtable;
}
void IT::Add(IdTable& idtable, Entry entry)
{
	idtable.table[idtable.size++] = entry;
	if (idtable.size > TI_MAXSIZE)
		throw ERROR_THROW(123);
}
Entry IT::GetEntry(IdTable& idtable, int n)
{
	if (n > idtable.size)
		throw ERROR_THROW(121);
	return idtable.table[n];
}
//нужна проверка и одинаковости символов, и общей области видимости
bool IT::IsId(Entry& elemOfTable, Entry elem)
{
	return (strcmp(elemOfTable.id, elem.id) == 0) && (strcmp(elemOfTable.prefix, elem.prefix) == 0);
}
bool IT::LitIsRepeated(Entry& elemOfTable, char lit[ID_MAXSIZE])
{
	return strcmp(elemOfTable.value.vstr->str, lit) == 0;
}
bool IT::LitIsRepeated(Entry& elemOfTable, int lit)
{
	return elemOfTable.value.vint == lit;
}
void IT::Delete(IdTable& idtable)
{
	delete[] idtable.table;
}
bool IT::RightID(Entry elemOfTable, char* id, char* prefix)
{
	return strcmp(elemOfTable.id, id) == 0 && strcmp(elemOfTable.prefix, prefix) == 0;
}
bool IT::RightID(Entry elemOfTable, char* id)
{
	return strcmp(elemOfTable.id, id) == 0;
}

int IT::GetIdxTI(const IdTable& idtable,char* id,char* prefix)
{
	for (int i = 0; i < idtable.size; i++)
	{
		if ((idtable.table[i].idtype == IDTYPE::F && RightID(idtable.table[i], id)) || (idtable.table[i].idtype == IDTYPE::K && RightID(idtable.table[i], id)))
			return i;
		if (RightID(idtable.table[i], id, prefix))
			return i;		
	}
	return -1;
}

