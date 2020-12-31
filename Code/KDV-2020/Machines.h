#pragma once
#include "FST.h"
#define EMPTYARITHMETIC ' '

#define FST_HUVUD word,6,\
FST::NODE(1, FST::RELATION('h',1)),\
FST::NODE(1, FST::RELATION('u',2)),\
FST::NODE(1, FST::RELATION('v',3)),\
FST::NODE(1, FST::RELATION('u',4)),\
FST::NODE(1, FST::RELATION('d',5)),\
FST::NODE()

#define FST_MEDAN word,6,\
FST::NODE(1, FST::RELATION('m',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('d',3)),\
FST::NODE(1, FST::RELATION('a',4)),\
FST::NODE(1, FST::RELATION('n',5)),\
FST::NODE()

#define FST_KRAFT word,6,\
FST::NODE(1, FST::RELATION('K',1)),\
FST::NODE(1, FST::RELATION('r',2)),\
FST::NODE(1, FST::RELATION('a',3)),\
FST::NODE(1, FST::RELATION('f',4)),\
FST::NODE(1, FST::RELATION('t',5)),\
FST::NODE()

#define FST_ROT word,4,\
FST::NODE(1, FST::RELATION('R', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('t', 3)), \
FST::NODE()

#define FST_SYMB word, 5,\
FST::NODE(1, FST::RELATION('s',1)),\
FST::NODE(1, FST::RELATION('y',2)),\
FST::NODE(1, FST::RELATION('m',3)),\
FST::NODE(1, FST::RELATION('b',4)),\
FST::NODE()

//Random
#define FST_SLUMP word, 6,\
FST::NODE(1, FST::RELATION('S',1)),\
FST::NODE(1, FST::RELATION('l',2)),\
FST::NODE(1, FST::RELATION('u',3)),\
FST::NODE(1, FST::RELATION('m',4)),\
FST::NODE(1, FST::RELATION('p',5)),\
FST::NODE()


#define FST_FUNG word, 5,\
FST::NODE(1, FST::RELATION('f',1)),\
FST::NODE(1, FST::RELATION('u',2)),\
FST::NODE(1, FST::RELATION('n',3)),\
FST::NODE(1, FST::RELATION('g',4)),\
FST::NODE()

#define FST_DEKL word, 5,\
FST::NODE(1, FST::RELATION('d',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('k',3)),\
FST::NODE(1, FST::RELATION('l',4)),\
FST::NODE()

#define FST_RETURN word, 7,\
FST::NODE(1, FST::RELATION('r',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('u',4)),\
FST::NODE(1, FST::RELATION('r',5)),\
FST::NODE(1, FST::RELATION('n',6)),\
FST::NODE()

#define FST_SKRIVA word, 7,\
FST::NODE(1, FST::RELATION('s',1)),\
FST::NODE(1, FST::RELATION('k',2)),\
FST::NODE(1, FST::RELATION('r',3)),\
FST::NODE(1, FST::RELATION('i',4)),\
FST::NODE(1, FST::RELATION('v',5)),\
FST::NODE(1, FST::RELATION('a',6)),\
FST::NODE()

#define FST_HELA word, 5,\
FST::NODE(1,FST::RELATION('h',1)),\
FST::NODE(1,FST::RELATION('e',2)),\
FST::NODE(1,FST::RELATION('l',3)),\
FST::NODE(1,FST::RELATION('a',4)),\
FST::NODE()

#define FST_OHELA word,6,\
FST::NODE(1, FST::RELATION('o', 1)), \
FST::NODE(1, FST::RELATION('h', 2)), \
FST::NODE(1, FST::RELATION('e', 3)), \
FST::NODE(1, FST::RELATION('l', 4)), \
FST::NODE(1, FST::RELATION('a', 5)), \
FST::NODE()

#define FST_OM word,3,\
FST::NODE(1, FST::RELATION('o', 1)), \
FST::NODE(1, FST::RELATION('m', 2)), \
FST::NODE()

#define FST_ANNAN word,6,\
FST::NODE(1, FST::RELATION('a', 1)), \
FST::NODE(1, FST::RELATION('n', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE(1, FST::RELATION('a', 4)), \
FST::NODE(1, FST::RELATION('n', 5)), \
FST::NODE()

#define FST_EXP word,4,\
FST::NODE(1, FST::RELATION('e', 1)), \
FST::NODE(1, FST::RELATION('x', 2)), \
FST::NODE(1, FST::RELATION('p', 3)), \
FST::NODE()

#define FST_SIN word,4,\
FST::NODE(1, FST::RELATION('s', 1)), \
FST::NODE(1, FST::RELATION('i', 2)), \
FST::NODE(1, FST::RELATION('n', 3)), \
FST::NODE()

#define FST_COS word,4,\
FST::NODE(1, FST::RELATION('c', 1)), \
FST::NODE(1, FST::RELATION('o', 2)), \
FST::NODE(1, FST::RELATION('s', 3)), \
FST::NODE()

#define FST_16NUMB word,3,\
FST::NODE(1,  FST::RELATION('H',1)),\
FST::NODE(1,  FST::RELATION('x',2)),\
FST::NODE(16, FST::RELATION('1',2),\
			  FST::RELATION('2',2),\
			  FST::RELATION('3',2),\
			  FST::RELATION('4',2),\
			  FST::RELATION('5',2),\
			  FST::RELATION('6',2),\
			  FST::RELATION('7',2),\
			  FST::RELATION('8',2),\
			  FST::RELATION('9',2),\
			  FST::RELATION('0',2),\
			  FST::RELATION('A',2),\
			  FST::RELATION('B',2),\
			  FST::RELATION('C',2),\
			  FST::RELATION('D',2),\
			  FST::RELATION('E',2),\
			  FST::RELATION('F',2))

#define FST_10NUMB word,1,\
FST::NODE(11, FST::RELATION('1',0),\
			  FST::RELATION('2',0),\
			  FST::RELATION('3',0),\
			  FST::RELATION('4',0),\
			  FST::RELATION('5',0),\
			  FST::RELATION('6',0),\
			  FST::RELATION('7',0),\
			  FST::RELATION('8',0),\
			  FST::RELATION('9',0),\
			  FST::RELATION('0',0),\
			  FST::NODE())

#define FST_8NUMB word,3,\
FST::NODE(1,  FST::RELATION('E',1)),\
FST::NODE(1,  FST::RELATION('x',2)),\
FST::NODE(8,  FST::RELATION('0',2),\
			  FST::RELATION('1',2),\
			  FST::RELATION('2',2),\
			  FST::RELATION('3',2),\
			  FST::RELATION('4',2),\
			  FST::RELATION('5',2),\
			  FST::RELATION('6',2),\
			  FST::RELATION('7',2))

#define FST_2NUMB word,3,\
FST::NODE(1,  FST::RELATION('B',1)),\
FST::NODE(1,  FST::RELATION('x',2)),\
FST::NODE(2,  FST::RELATION('0',2),\
			  FST::RELATION('1',2))




#define FST_IDENTIFICATOR word, 1,\
FST::NODE(55, FST::RELATION('a',0),\
			  FST::RELATION('b',0),\
			  FST::RELATION('c',0),\
			  FST::RELATION('d',0),\
			  FST::RELATION('e',0),\
			  FST::RELATION('f',0),\
			  FST::RELATION('g',0),\
			  FST::RELATION('h',0),\
			  FST::RELATION('i',0),\
			  FST::RELATION('j',0),\
			  FST::RELATION('k',0),\
			  FST::RELATION('l',0),\
			  FST::RELATION('m',0),\
			  FST::RELATION('n',0),\
			  FST::RELATION('o',0),\
			  FST::RELATION('p',0),\
			  FST::RELATION('q',0),\
			  FST::RELATION('r',0),\
			  FST::RELATION('s',0),\
			  FST::RELATION('t',0),\
			  FST::RELATION('u',0),\
			  FST::RELATION('v',0),\
			  FST::RELATION('w',0),\
			  FST::RELATION('x',0),\
			  FST::RELATION('y',0),\
			  FST::RELATION('z',0),\
			  FST::RELATION('A',0),\
			  FST::RELATION('B',0),\
			  FST::RELATION('C',0),\
			  FST::RELATION('D',0),\
			  FST::RELATION('E',0),\
			  FST::RELATION('F',0),\
			  FST::RELATION('G',0),\
			  FST::RELATION('H',0),\
			  FST::RELATION('I',0),\
			  FST::RELATION('J',0),\
			  FST::RELATION('K',0),\
			  FST::RELATION('L',0),\
			  FST::RELATION('M',0),\
			  FST::RELATION('N',0),\
			  FST::RELATION('O',0),\
			  FST::RELATION('P',0),\
			  FST::RELATION('Q',0),\
			  FST::RELATION('R',0),\
			  FST::RELATION('S',0),\
			  FST::RELATION('T',0),\
			  FST::RELATION('U',0),\
			  FST::RELATION('V',0),\
			  FST::RELATION('W',0),\
			  FST::RELATION('X',0),\
			  FST::RELATION('Y',0),\
			  FST::RELATION('Z',0),\
			  FST::NODE())

#define FST_STRLITERAL word,4,\
FST::NODE(1, FST::RELATION('\'',1)),\
FST::NODE(37, FST::RELATION('a',2),\
			  FST::RELATION('b',2),\
			  FST::RELATION('c',2),\
			  FST::RELATION('d',2),\
			  FST::RELATION('e',2),\
			  FST::RELATION('f',2),\
			  FST::RELATION('g',2),\
			  FST::RELATION('h',2),\
			  FST::RELATION('i',2),\
			  FST::RELATION('j',2),\
			  FST::RELATION('k',2),\
			  FST::RELATION('l',2),\
			  FST::RELATION('m',2),\
			  FST::RELATION('n',2),\
			  FST::RELATION('o',2),\
			  FST::RELATION('p',2),\
			  FST::RELATION('q',2),\
			  FST::RELATION('r',2),\
			  FST::RELATION('s',2),\
			  FST::RELATION('t',2),\
			  FST::RELATION('u',2),\
			  FST::RELATION('v',2),\
			  FST::RELATION('w',2),\
			  FST::RELATION('x',2),\
			  FST::RELATION('y',2),\
			  FST::RELATION('z',2),\
			  FST::RELATION('A',2),\
			  FST::RELATION('B',2),\
			  FST::RELATION('C',2),\
			  FST::RELATION('D',2),\
			  FST::RELATION('E',2),\
			  FST::RELATION('F',2),\
			  FST::RELATION('G',2),\
			  FST::RELATION('H',2),\
			  FST::RELATION('I',2),\
			  FST::RELATION('J',2),\
			  FST::RELATION('K',2),\
			  FST::RELATION('L',2),\
			  FST::RELATION('M',2),\
			  FST::RELATION('N',2),\
			  FST::RELATION('O',2),\
			  FST::RELATION('P',2),\
			  FST::RELATION('Q',2),\
			  FST::RELATION('R',2),\
			  FST::RELATION('S',2),\
			  FST::RELATION('T',2),\
			  FST::RELATION('U',2),\
			  FST::RELATION('V',2),\
			  FST::RELATION('W',2),\
			  FST::RELATION('X',2),\
			  FST::RELATION('Y',2),\
			  FST::RELATION('Z',2),\
			  FST::RELATION('1',2),\
			  FST::RELATION('2',2),\
			  FST::RELATION('3',2),\
			  FST::RELATION('4',2),\
			  FST::RELATION('5',2),\
			  FST::RELATION('6',2),\
			  FST::RELATION('7',2),\
			  FST::RELATION('8',2),\
			  FST::RELATION('9',2),\
			  FST::RELATION('0',2),\
			  FST::RELATION(' ',2),\
			  FST::RELATION('&',2),\
			  FST::RELATION('!',2),\
			  FST::RELATION('@',2),\
			  FST::RELATION('#',2),\
			  FST::RELATION('$',2),\
			  FST::RELATION('%',2),\
			  FST::RELATION('^',2),\
			  FST::RELATION('*',2),\
			  FST::RELATION('(',2),\
			  FST::RELATION(')',2),\
			  FST::RELATION(':',2),\
			  FST::RELATION(';',2),\
			  FST::RELATION('"',2),\
			  FST::RELATION('-',2),\
			  FST::RELATION('+',2),\
			  FST::RELATION('=',2),\
			  FST::RELATION('*',2),\
			  FST::RELATION('?',2),\
			  FST::RELATION('.',2),\
			  FST::RELATION(',',2),\
			  FST::RELATION('>',2),\
			  FST::RELATION('<',2)),\
FST::NODE(1,FST::RELATION('\'',3)),\
FST::NODE()

#define AMOUNTLEXEM 23
#define ALL_MACHINES \
FST::FST Hela(FST_HELA);\
FST::FST Ohela(FST_OHELA);\
FST::FST Symb(FST_SYMB);\
FST::FST Medan(FST_MEDAN);\
FST::FST Kraft(FST_KRAFT);\
FST::FST Rot(FST_ROT);\
FST::FST Fung(FST_FUNG);\
FST::FST Dekl(FST_DEKL);\
FST::FST Return(FST_RETURN);\
FST::FST Skriva(FST_SKRIVA);\
FST::FST Slump(FST_SLUMP);\
FST::FST Huvud(FST_HUVUD);\
FST::FST Om(FST_OM);\
FST::FST Annan(FST_ANNAN);\
FST::FST Exp(FST_EXP);\
FST::FST Sin(FST_SIN);\
FST::FST Cos(FST_COS);\
FST::FST Numb10(FST_10NUMB);\
FST::FST Numb16(FST_16NUMB);\
FST::FST Numb8(FST_8NUMB);\
FST::FST Numb2(FST_2NUMB);\
FST::FST STRLiteral(FST_STRLITERAL);\
FST::FST Identificator(FST_IDENTIFICATOR);\
FST::FST CHOOSINGMACHINE[AMOUNTLEXEM] = {Annan, Cos, Dekl, Exp, Fung, Hela, Huvud, Medan, Ohela, Om, Return, Sin, Skriva, Symb, STRLiteral,Numb10,Numb16,Numb8,Numb2,Kraft,Rot,Slump, Identificator};

namespace MCH
{
	bool changingMachine(char* word, In::IN & in, LT::LexTable & lextable, IT::IdTable & idtable, FST::FST* machine);
	bool changingSymbol(char word, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable);
	void inputToIdTable(IT::IdTable & idtable, LT::LexTable&, In::IN & in, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId);
	int inputToIdTable(IT::IdTable & idtable, LT::LexTable&, In::IN & in, IT::IDDATATYPE dataType, char* word, IT::IDTYPE);
	void DefineScope(IT::Entry&, bool*,IT::IdTable&);
	void inputToLexTable(LT::LexTable & lextable, In::IN in, char lexem, int,char,int priority = -1);
	IT::IDTYPE typeofId(bool* isTypeOfId);
	void defineIdName(IT::Entry&, char*);
	void BaseToDecimal(char* lexema, int base);
	void changeParamsForFOut(IT::Entry& partOfTable);
}