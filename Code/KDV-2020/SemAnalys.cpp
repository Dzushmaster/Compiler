#include "SemAnalys.h"
#define INTMAX 2147483647
#define INTMIN -2147483648
#define UINTMIN 0
#define UINTMAX 4294967295
namespace SA
{
	void SemAnalys(const LT::LexTable& lextable, IT::IdTable& idtable)
	{
		std::list<Func> funcInfo;
		bool isMain = false;
		bool inMain = false;
		bool isFunc = false;
		short countBrace = 0;
		short countHesis = 0;
		short countSQ = 0;
		for (int i = 0; i < lextable.size; i++)
		{
			switch (lextable.table[i].lexema)
			{
				case LEX_HUVUD: 
				{
					checkSecondMain(lextable.table[i].sn, isMain);
					inMain = true;
				}
				break;
				case LEX_ID:
				{
					//если функция, ставим флажок и записываем тип данных 
					checkDefine(lextable.table[i]);
					if (i != 1)
					{
						if (checkIdentFunc(lextable.table[i - 2].lexema))
						{
							funcInfo.push_back(filingFuncList(lextable, idtable, i));
							break;
						}
					}
					isFunc = checkFunc(idtable.table[lextable.table[i].idxTI].idtype);
					break;
				}
				case LEX_BOOL:
				case LEX_OPER:
				{
					if (i != 0)
					{						
						operWithString(idtable, lextable.table[i - 1]);
						if (idtable.table[lextable.table[i-1].idxTI].iddatatype != idtable.table[lextable.table[i + 1].idxTI].iddatatype)
							throw ERROR_THROW_IN(407, lextable.table[i].sn, 0);
					}
					if (lextable.table[i].arithmeticSymbol == DIRSLASH)
					{
						if (lextable.table[i - 1].lexema == LEX_LITERAL && idtable.table[lextable.table[i + 1].idxTI].value.vint == 0)
							throw ERROR_THROW_IN(412, lextable.table[i].sn, 0);
					}
					break;
				}
				case LEX_LITERAL:
				{
					if (idtable.table[lextable.table[i].idxTI].iddatatype == IT::IDDATATYPE::INT)
					{
						checkRange(idtable.table[lextable.table[i].idxTI].value.vint, INTMAX, INTMIN, lextable.table[i].idxTI);
						break;
					}
					if (idtable.table[lextable.table[i].idxTI].iddatatype == IT::IDDATATYPE::UINT)
					{
						checkRange(idtable.table[lextable.table[i].idxTI].value.vint, UINTMAX, UINTMIN, lextable.table[i].idxTI);
						break;
					}
					break;
				}
				case LEX_BRACELEFT:
				{
					countBrace--;
					break;
				}
				case LEX_LEFTBRACE:
				{
					countBrace++;
					break;
				}
				case LEX_LEFTHESIS:
				{
					countHesis++;
					break;
				}
				case LEX_REIGHTHESIS:
				{
					countHesis--;
					break;
				}
				case LEX_SQ_LBRACELET:
				{
					countSQ++;
					break;
				}
				case LEX_SQ_RBRACELET:
				{
					countSQ--;
					break;
				}

				case LEX_RETURN:
				{
					if (!inMain)
						if (!checkRetType(lextable.table[i + 1], idtable, i, funcInfo))
							throw ERROR_THROW_IN(406, lextable.table[i].sn,0);
					inMain = false;
					break;
				}
				case LEX_EQUALS:
				{
					checkTypes(lextable,idtable,i);
					break;
				}
					break;
			default:
				continue;
			}
		}
		if (!isMain)
			throw ERROR_THROW(400);
		if (countBrace != 0)
			throw ERROR_THROW_IN(402, lextable.table[lextable.size].sn ,0);
		if (countHesis != 0)
			throw ERROR_THROW_IN(403, lextable.table[lextable.size].sn, 0);
		if (countSQ != 0)
			throw ERROR_THROW_IN(415, lextable.table[lextable.size].sn, 0);
	}
	void checkSecondMain(int line, bool& isMain)
	{
		if (isMain == true)
			throw ERROR_THROW_IN(401, line, 0);
		isMain = true;
	}
	void checkDefine(const LT::Entry& elemLex)
	{
		if (elemLex.idxTI < 0)
			throw ERROR_THROW_IN(404, elemLex.sn, 0);
	}
	void checkRange(int number,unsigned int max, int min, int line)
	{
		if (number > max || number < min)
			throw ERROR_THROW_IN(405, line, 0);
	}
	bool checkRetType(LT::Entry elemLex, IT::IdTable& idtable, int lexIndex,std::list<Func> listFunc)
	{//могут быть как литералы, так и идентификаторы
		for (Func list: listFunc)
		{
			if (idtable.table[elemLex.idxTI].idtype == IT::IDTYPE::L)
				if (idtable.table[list.indexIDTable].iddatatype == idtable.table[elemLex.idxTI].iddatatype)
					return true;
			if ((strcmp(idtable.table[list.indexIDTable].id, idtable.table[elemLex.idxTI].prefix) == 0) && (idtable.table[list.indexIDTable].iddatatype == idtable.table[elemLex.idxTI].iddatatype))
				return true;
		}
		return false;
		//throw ERROR_THROW_IN(406, elemLex.sn, 0);
	}
	void operWithString(const IT::IdTable& idtable, const LT::Entry& entry)
	{
		if (idtable.table[entry.idxTI].iddatatype == IT::IDDATATYPE::STR )
			throw ERROR_THROW_IN(408, entry.sn, 0);
	}
	bool checkIdentFunc(char func)
	{
		return func == LEX_FUNG;
	}
	bool checkFunc(int type)
	{ return type == IT::IDTYPE::F; }
	Func filingFuncList(const LT::LexTable& lextable,const IT::IdTable& idtable, int& index)
	{
		Func func;
		func.indexIDTable = lextable.table[index].idxTI;
		index++;
		countParam(lextable, idtable,++index,func);
		return func;//считаем количество переменных после этой с типом Param
	}
	void countParam(const LT::LexTable& lextable, const IT::IdTable&idtable, int& index,Func& func)
	{
		int countBracket = 1;
		for (; countBracket!=0;index++)
		{
			if (lextable.table[index].lexema == LEX_LEFTHESIS)
			{
				countBracket++; continue;
			}
			if (lextable.table[index].lexema == LEX_REIGHTHESIS)
			{
				countBracket--; continue;
			}
			if(lextable.table[index].lexema == LEX_ID)
				if (idtable.table[lextable.table[index].idxTI].idtype == IT::IDTYPE::P)
				{
					func.typeParam[func.countParam] = idtable.table[lextable.table[index].idxTI].iddatatype;
					func.countParam++;
					if (func.countParam > 5)
						throw ERROR_THROW_IN(409, lextable.table[index].sn, 0);
				}
		}
		index--;
	}
	void checkTypes(const LT::LexTable& lextable, const IT::IdTable& idtable, int index)
	{
		if (idtable.table[lextable.table[index - 1].idxTI].iddatatype != idtable.table[lextable.table[index + 1].idxTI].iddatatype)
			throw ERROR_THROW_IN(414, lextable.table[index].sn,0);
	}
}