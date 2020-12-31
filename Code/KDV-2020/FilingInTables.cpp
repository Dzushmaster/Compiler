#include "Machines.h"
#include "IT.h"
#include "LT.h"
#include "PrintTables.h"
#pragma warning (disable:4996)
int checkIndEntry(IT::IdTable& idtable,IT::Entry elemOfTable)//во время проверки этой или после вызывать таблицу
{
	for (int i = 0; i < idtable.size; i++)
	{
		if ((idtable.table[i].idtype != IT::IDTYPE::P) && IT::IsId(idtable.table[i],elemOfTable))
			return i;
		//if (IT::IsOtherFunc(idtable.table[i], elemOfTable))
		//	return i;
	}
	return -1;
}
int checkLitEntry(IT::IdTable& idtable, char* word)
{
	for (int i = 0; i < idtable.size; i++)
	{
		if((idtable.table[i].idtype ==IT::IDTYPE::L) && IT::LitIsRepeated(idtable.table[i],word))
			return i;
	}
	return -1;
}
int checkLitEntry(IT::IdTable& idtable, int lit)
{
	for (int i = 0; i < idtable.size; i++)
	{
		if (IT::LitIsRepeated(idtable.table[i], lit))
			return i;
	}
	return -1;
}

namespace MCH
{
	static char nameFunction[PREFIX_SIZE];
	void inputToIdTable(IT::IdTable& idtable, LT::LexTable& lextable, In::IN& in, IT::IDDATATYPE dataType, char* word, bool* FOutFIntUIntStrFunVarMain)
	{
		IT::Entry partOfTable;
		partOfTable.iddatatype = dataType;
		partOfTable.idxfirstLE = in.lines;
		partOfTable.idtype = typeofId(FOutFIntUIntStrFunVarMain);
		defineIdName(partOfTable, word);
		DefineScope(partOfTable, FOutFIntUIntStrFunVarMain, idtable);
		if (checkIndEntry(idtable, partOfTable) != -1)
		{
			if (partOfTable.idtype == IT::IDTYPE::K)
				return;
			throw ERROR_THROW_IN(129, in.lines, in.currentPosition - strlen(word));
		}
		if (dataType == IT::IDDATATYPE::STR && (IT::F != partOfTable.idtype))
		{
			partOfTable.value.vstr->ken = 0;
			partOfTable.value.vstr->str[0] = TI_STR_DEFAULT;
		}
		else if (IT::F != partOfTable.idtype || IT::K != partOfTable.idtype)
			partOfTable.value.vint = TI_INT_DEFAULT;
		IT::Add(idtable, partOfTable);
	}
	void defineIdName(IT::Entry& partOfTable, char* word)//заменить переменную, в которую записывается значение
	{
		strncpy_s(partOfTable.id, word, ID_MAXSIZE);
	}
	char* getNextLiteralName()						// сгенерировать следующее имя литерала
	{
		static int literalNumber = 1;
		char* buf = new char[TI_MAXSIZE];
		char num[3];
		strcpy_s(buf, ID_MAXSIZE, "L");
		_itoa_s(literalNumber++, num, 10);
		strcat(buf, num);
		return buf;
	}
	int inputToIdTable(IT::IdTable& idtable, LT::LexTable& lextable, In::IN& in, IT::IDDATATYPE iddatatype, char* word, IT::IDTYPE idtype)
	{
		IT::Entry partOfTable;
		int lit = 0;
		if (iddatatype == IT::IDDATATYPE::SYMB)
		{
			int index = checkLitEntry(idtable, word);
			if (index != -1)
				return index + 1;
			partOfTable.value.vstr->ken = strlen(word);
			strncpy_s(partOfTable.value.vstr->str, word, strlen(word));
		}
		else if (iddatatype == IT::IDDATATYPE::UINT)
		{
			int index = checkLitEntry(idtable, lit = atoi(word));
			if (index != -1)
				return index + 1;
			partOfTable.value.vint = lit;
		}
		else
		{
			int index = checkLitEntry(idtable, word);
			if (index != -1)
				return index + 1;
		}
		partOfTable.iddatatype = iddatatype;
		partOfTable.idtype = idtype;
		strcpy_s(partOfTable.id, getNextLiteralName());
		partOfTable.prefix[0] = '\0';
		partOfTable.idxfirstLE = in.lines;
		IT::Add(idtable, partOfTable);
		return idtable.size;
	}

	IT::IDTYPE typeofId(bool* FOutFIntUIntStrFunVarMain)
	{
		if (FOutFIntUIntStrFunVarMain[4])						//переменная
			return IT::IDTYPE::V;
		if (FOutFIntUIntStrFunVarMain[3])						//функция
			return IT::IDTYPE::F;
		if (FOutFIntUIntStrFunVarMain[0])
			return IT::IDTYPE::K;
		return IT::IDTYPE::P;							//параметр
	}

	void DefineScope(IT::Entry& partOfTable, bool* FOutFIntUIntStrFunVarMain, IT::IdTable& idtable)
	{
		static int idFunc = 0;
		if ((FOutFIntUIntStrFunVarMain[3] && !FOutFIntUIntStrFunVarMain[4]))//возможно, заменить на функцию
		{
			strncpy_s(nameFunction, partOfTable.id, 10);
			FOutFIntUIntStrFunVarMain[3] = false;
			partOfTable.prefix[0] = NULL;
			idFunc = idtable.size;
			return;
		}
		if (FOutFIntUIntStrFunVarMain[5])
		{
			strncpy_s(nameFunction, "huvud", 5);
			FOutFIntUIntStrFunVarMain[5] = false;
			strncpy_s(partOfTable.prefix, nameFunction, PREFIX_SIZE);
			idFunc = -1;
			return;
		}
		if (partOfTable.idtype == IT::IDTYPE::P)
			idtable.table[idFunc].countParam++;
		if (partOfTable.idtype == IT::IDTYPE::K)
		{
			changeParamsForFOut(partOfTable);
			partOfTable.prefix[0] = '\0';
			return;
		}
		strncpy_s(partOfTable.prefix, nameFunction, PREFIX_SIZE);
	}

	void inputToLexTable(LT::LexTable& lextable, In::IN in, char lexem, int idxTI, char arithmeticSymbol, int priority)
	{
		LT::Entry partOfTable;
		partOfTable.lexema = lexem;
		partOfTable.sn = in.lines;
		partOfTable.idxTI = idxTI;
		partOfTable.arithmeticSymbol = arithmeticSymbol;
		partOfTable.priority = priority;
		LT::Add(lextable, partOfTable);
	}



	bool changingMachine(char* word, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable, FST::FST* machine)
	{
		static bool FOutFIntUIntStrFunVarMain[6] = { false,false,false,false,false,false };
		switch (word[0])
		{
			case 'a':
			{
				if (FST::execute(machine[0]))						//annan(else)
				{
					inputToLexTable(lextable, in, LEX_ANNAN, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'B':
			{
				if (FST::execute(machine[18]))						//numbers literal
				{
					BaseToDecimal(word, 2);
					int index = inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, IT::IDTYPE::L);
					inputToLexTable(lextable, in, LEX_LITERAL, index - 1, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'c':
			{
				if (FST::execute(machine[1]))						//cos
				{
					inputToLexTable(lextable, in, LEX_COS, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'd':												//dekl(declare)
			{
				if (FST::execute(machine[2]))
				{
					FOutFIntUIntStrFunVarMain[4] = true;
					inputToLexTable(lextable, in, LEX_DEKLARE, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'e':
			{
				if (FST::execute(machine[3]))						//exp
				{
					inputToLexTable(lextable, in, LEX_EXP, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'E':
			{	
				if (FST::execute(machine[17]))						//numbers literal
				{
					BaseToDecimal(word, 8);
					int index = inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, IT::IDTYPE::L);
					inputToLexTable(lextable, in, LEX_LITERAL, index - 1, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'f':
			{
				if (FST::execute(machine[4]))						//fung
				{
					FOutFIntUIntStrFunVarMain[3] = true;
					inputToLexTable(lextable, in, LEX_FUNG, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'h':
			{
				if (FST::execute(machine[5]))						//hela(int)
				{
					FOutFIntUIntStrFunVarMain[0] = true;
					inputToLexTable(lextable, in, LEX_VARIABLE, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				else if (FST::execute(machine[6]))					//huvud(main)
				{
					FOutFIntUIntStrFunVarMain[5] = true;
					inputToLexTable(lextable, in, LEX_HUVUD, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'H':
			{
				if (FST::execute(machine[16]))						//numbers literal
				{
					BaseToDecimal(word, 16);
					int index = inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, IT::IDTYPE::L);
					inputToLexTable(lextable, in, LEX_LITERAL, index - 1, EMPTYARITHMETIC);
					return true;
				}
				break;             
			}
			case 'K':
			{
				if (FST::execute(machine[19]))						//KRAFT(pow(n))
				{
					FOutFIntUIntStrFunVarMain[0] = true;
					inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, FOutFIntUIntStrFunVarMain);
					int index = -2;
					if((index = IT::GetIdxTI(idtable,word, nameFunction)) <0)
						inputToLexTable(lextable, in, LEX_KRAFT, idtable.size-1, EMPTYARITHMETIC);
					else
						inputToLexTable(lextable, in, LEX_KRAFT, index, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'm':
			{
				if (FST::execute(machine[7]))						//medan(while)
				{
					inputToLexTable(lextable, in, LEX_MEDAN, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'o':
			{
				if (FST::execute(machine[8]))						//ohela(unsgined int)
				{
					FOutFIntUIntStrFunVarMain[1] = true;
					inputToLexTable(lextable, in, LEX_VARIABLE, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				else if (FST::execute(machine[9]))					//om(if)
				{
					inputToLexTable(lextable, in, LEX_OM, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'r':
			{
				if (FST::execute(machine[10]))						//return
				{
					inputToLexTable(lextable, in, LEX_RETURN, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}

				break;
			}
			case 'R':
			{
				if (FST::execute(machine[20]))						//rot(pow(1/n))
				{
					FOutFIntUIntStrFunVarMain[0] = true;
					inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, FOutFIntUIntStrFunVarMain);
					int index = -2;
					if ((index = IT::GetIdxTI(idtable, word, nameFunction)) < 0)
						inputToLexTable(lextable, in, LEX_ROT, idtable.size - 1, EMPTYARITHMETIC);
					else
						inputToLexTable(lextable, in, LEX_ROT, index, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 's':
			{
				if (FST::execute(machine[11]))						//sin
				{
					inputToLexTable(lextable, in, LEX_SIN, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				else if (FST::execute(machine[12]))					//skriva(print)
				{
					inputToLexTable(lextable, in, LEX_SKRIVA, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				else if (FST::execute(machine[13]))					//symb
				{
					FOutFIntUIntStrFunVarMain[2] = true;
					inputToLexTable(lextable, in, LEX_VARIABLE, LT_TI_NULLIDX, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			case 'S':
			{
				if (FST::execute(machine[21]))						//rot(pow(1/n))
				{
					FOutFIntUIntStrFunVarMain[0] = true;
					inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, FOutFIntUIntStrFunVarMain);
					int index = -2;
					if ((index = IT::GetIdxTI(idtable, word, nameFunction)) < 0)
						inputToLexTable(lextable, in, LEX_SLUMP, idtable.size - 1, EMPTYARITHMETIC);
					else
						inputToLexTable(lextable, in, LEX_SLUMP, index, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
			default:
			{
				if (FST::execute(machine[15]))						//numbers literal
				{
					int index = inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, IT::IDTYPE::L);
					inputToLexTable(lextable, in, LEX_LITERAL, index - 1, EMPTYARITHMETIC);
					return true;
				}
				break;
			}
		}
		if (FST::execute(machine[22]))							//identificator
		{
			int index = 0;
			if (FOutFIntUIntStrFunVarMain[1])
			{
				inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::UINT, word, FOutFIntUIntStrFunVarMain);
				for (int i = 0; i < sizeof(FOutFIntUIntStrFunVarMain) / sizeof(bool); i++) FOutFIntUIntStrFunVarMain[i] = false;
			}
			else if (FOutFIntUIntStrFunVarMain[2])
			{
				inputToIdTable(idtable, lextable, in, IT::IDDATATYPE::STR, word, FOutFIntUIntStrFunVarMain);
				for (int i = 0; i < sizeof(FOutFIntUIntStrFunVarMain) / sizeof(bool); i++) FOutFIntUIntStrFunVarMain[i] = false;
			}
			else
			{
				char* newWord = new char[ID_MAXSIZE + 1];
				strncpy(newWord, word, ID_MAXSIZE);
				newWord[ID_MAXSIZE] = '\0';
				int index = -1;
				if ((index = IT::GetIdxTI(idtable, newWord, nameFunction)) < 0)
					throw ERROR_THROW_IN(132, in.lines, 0);
				inputToLexTable(lextable, in, LEX_ID, index, EMPTYARITHMETIC);
				return true;
			}
			inputToLexTable(lextable, in, LEX_ID, idtable.size - 1, EMPTYARITHMETIC);

			return true;
		}


		return false;
	}

	bool changingSymbol(char word, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		switch (word)
		{
		case BRACELEFT:
		{
			inputToLexTable(lextable, in, LEX_BRACELEFT, LT_TI_NULLIDX, BRACELEFT);
			return true;
		}
		case COMMA:
		{
			inputToLexTable(lextable, in, LEX_COMMA, LT_TI_NULLIDX, COMMA);
			return true;
		}
		case DIRSLASH:
		{
			inputToLexTable(lextable, in, LEX_OPER, LT_TI_NULLIDX, DIRSLASH, 2);
			return true;
		}
		case EQGREATER:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, EQGREATER);
			return true;
		}
		case EQLESS:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, EQLESS);
			return true;
		}
		case EQUAL:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, EQUAL);
			return true;
		}
		case EQUALS:
		{
			inputToLexTable(lextable, in, LEX_EQUALS, LT_TI_NULLIDX, EQUALS);
			return true;
		}

		case GREATER:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, GREATER);
			return true;
		}
		case LEX_SQ_LBRACELET:
		{
			inputToLexTable(lextable, in, LEX_SQ_LBRACELET, LT_TI_NULLIDX, LEX_SQ_LBRACELET);
			return true;
		}
		case LEFTBRACE:
		{
			inputToLexTable(lextable, in, LEX_LEFTBRACE, LT_TI_NULLIDX, LEFTBRACE);
			return true;
		}
		case LEFTHESIS:
		{
			inputToLexTable(lextable, in, LEX_LEFTHESIS, LT_TI_NULLIDX, LEFTHESIS, 0);
			return true;
		}
		case LESS:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, LESS);
			return true;
		}
		case MINUS:
		{
			inputToLexTable(lextable, in, LEX_OPER, LT_TI_NULLIDX, MINUS, 1);
			return true;
		}
		case NOTEQUALS:
		{
			inputToLexTable(lextable, in, LEX_BOOL, LT_TI_NULLIDX, NOTEQUALS);
			return true;
		}
		case LEX_SQ_RBRACELET:
		{
			inputToLexTable(lextable, in, LEX_SQ_RBRACELET, LT_TI_NULLIDX, LEX_SQ_RBRACELET);
			return true;
		}
		case PLUS:
		{
			inputToLexTable(lextable, in, LEX_OPER, LT_TI_NULLIDX, PLUS, 1);
			return true;
		}
		case REIGHTHESIS:
		{
			inputToLexTable(lextable, in, LEX_REIGHTHESIS, LT_TI_NULLIDX, REIGHTHESIS, 0);
			return true;
		}
		case SEMICOLON:
		{
			inputToLexTable(lextable, in, LEX_SEMICOLON, LT_TI_NULLIDX, SEMICOLON);
			return true;
		}
		case STAR:
		{
			inputToLexTable(lextable, in, LEX_OPER, LT_TI_NULLIDX, STAR, 2);
			return true;
		}
		}
		return false;
	}
	void BaseToDecimal(char* lexema, int base)
	{
		int number = 0;
		int k;
		for (int i = 1; lexema[i] != '\0'; i++)
		{
			if (lexema[i] <= '9' && lexema[i] >= '0') k = lexema[i] - '0';
			else if (lexema[i] >= 'A' && lexema[i] <= 'F') k = lexema[i] - 'A' + 10;
			else if (lexema[i] >= 'a' && lexema[i] <= 'f') k = lexema[i] - 'a' + 10;
			else continue;
			number = base * number + k;
		}
		sprintf(lexema, "%d", number);
	}
	void changeParamsForFOut(IT::Entry& partOfTable)
	{
		if (strcmp("Kraft", partOfTable.id) == 0)
		{
			partOfTable.countParam = 2;
			return;
		}
		if (strcmp("Rot", partOfTable.id) == 0)
		{
			partOfTable.countParam = 1;
			return;
		}
		if (strcmp("Slump", partOfTable.id) == 0)
		{
			partOfTable.countParam = 1;
			return;
		}
		throw ERROR_THROW_IN(131, partOfTable.idxfirstLE+1, 0);
	}
}
