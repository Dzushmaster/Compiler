#pragma once
#include "LT.h"
#include "Error.h"
#include "IT.h"
#include "In.h"
#include "Lexemes.h"
#include <list>
#define MAXCOUNTPAR 5
namespace SA
{
	struct Func
	{
		int indexIDTable = -1;		//с помощью этого можно получить тип функции и ее имя
		int typeParam[MAXCOUNTPAR];		//типы параметров, всего не больше 5
		int countParam = 0;
	};
	void SemAnalys(const LT::LexTable&, IT::IdTable&);
	void checkSecondMain(int, bool& isMain);
	void checkRange(int, unsigned int max, int min, int line);//диапазон допустимых значений
	void checkDefine(const LT::Entry& elemLex);//определен идентификатор
	bool checkRetType(LT::Entry elemLex, IT::IdTable& idtable, int lexIndex, std::list<Func> listFunc);
	bool checkIdentFunc(char func);
	bool checkFunc(int type);
	void operWithString(const IT::IdTable& idtable, const LT::Entry& lextable);
	Func filingFuncList(const LT::LexTable&, const IT::IdTable&, int& index);
	void countParam(const LT::LexTable& lextable, const IT::IdTable& idtable, int& index, Func& func);
	void chooseList(const LT::LexTable& entry, const IT::IdTable& idtable, int& index, std::list<Func> listFunc);
	void checkCountTypeParams(const LT::LexTable& , const IT::IdTable&, int& index,Func listFunc);
	void checkTypes(const LT::LexTable&, const IT::IdTable&, int index);
}