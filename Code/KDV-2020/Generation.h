#pragma once
#include "Error.h"
#include "IT.h"
#include "Lexemes.h"
#include "Out.h"
#include "LT.h"
#include <stack>

#define TIENTRY(x)idtable.table[lextable.table[x].idxTI]
#define LEX(x) lextable.table[x].lexema

#define HEAD ".586\n"\
			".model flat, stdcall\n"\
			"includelib libucrt.lib\n"\
			"includelib kernel32.lib\n"\
			"includelib ..\\KDV-2020\\Debug\\Stand_Lib.lib\n"\
			"ExitProcess PROTO:DWORD\n\n"\
			".stack 4096\n\n"

#define EXTERN 	"EXTRN Kraft: proc\n"\
				"EXTRN Rot: proc\n"\
				"EXTRN Slump: proc\n"\
				"EXTRN strlineout: proc\n"\
				"EXTRN system_pause: proc\n"\
				"EXTRN numout:proc\n"\
				"EXTRN printError:proc\n"


#define CONST "\n.const\n"\
				"null_division BYTE 'ERROR:DIVISION BY ZERO', 0"\
				"\noverflow BYTE 'ERROR: VARIABLE OVERFLOW', 0\n"

#define DATA "\n.data\n"\

#define CODE "\n.code\n"
#define ERRORS  "\nSOMETHINGWRONG:"\
				"\npush offset null_division"\
				"\ncall printError\n"\
				"call system_pause"\
				"\npush -1"\
				"\ncall ExitProcess"\
				"\nEXIT_OVERFLOW:"\
				"\npush offset overflow"\
				"\ncall printError\n"\
				"call system_pause"\
				"\npush -2"\
				"\ncall ExitProcess"\

#define END "\npush 0"\
			"\ncall ExitProcess\n"\
			"\nSOMETHINGWRONG:"\
			"\npush offset null_division"\
			"\ncall printError\n"\
			"call system_pause"\
			"\npush -1"\
			"\ncall ExitProcess"\
			"\nEXIT_OVERFLOW:"\
			"\npush offset overflow"\
			"\ncall printError\n"\
			"call system_pause"\
			"\npush -2"\
			"\ncall ExitProcess"\
			"\nmain ENDP\nend main"


namespace GEN
{
	void codeGen(const LT::LexTable& lextable, const IT::IdTable idatable, Parm::PARM&parm);
	string FullName(IT::Entry);
}