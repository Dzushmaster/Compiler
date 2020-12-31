#pragma once
#include "LT.h"
#include "IT.h"
#define IN_MAX_LEN_TEXT 1024*1024 
#define IN_CODE_ENDL '\n'
#define LINE_BREAK '|'
#define COMMENT '?'
#define IN_CODE_TABLE {\
 /*0-15*/	   IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::TB, IN::N, IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*16-31*/	   IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
 /*32-47*/     IN::S, IN::E, IN::F, IN::F, IN::E, IN::F, IN::E, IN::Q, IN::E, IN::E, IN::E, IN::E, IN::E, IN::E, IN::F, IN::E,\
 /*48-63*/     IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::E, IN::E, IN::E, IN::E, IN::C,\
 /*64-79*/     IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
 /*80-95*/     IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::E, IN::F, IN::E, IN::F, IN::F,\
 /*96-111*/    IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,\
 /*112-127*/   IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::E,IN::F, IN::E, IN::E, IN::F,\
                                                                                                                    \
/*128-143*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*144-159*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*160-175*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*176-191*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*192-207*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*208-223*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*224-239*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*240-255*/    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F  \
};
namespace In
{
	struct IN
	{
		enum {TB = 128,C = 256, N = 512, T = 1024, F = 2048, I = 4096, E = 8192, S = 16384, Q = 32768 };
		int size = 0;
		int lines = 1;
		int ignor = 0;
		int currentPosition = 1;
		unsigned char* text;	//Èñõîäíûé êîä Windows-1251
		int sizeAfterLex = 0;
		int code[256] = IN_CODE_TABLE;			//Òàáëèöà ïðîâåðêè
	};
	IN getin(wchar_t inFile[], LT::LexTable&, IT::IdTable&);
}