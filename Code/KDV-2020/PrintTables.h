#pragma once
#include "LT.h"
#include "IT.h"
#include "Error.h"
#include "In.h"
#define LINE_BREAK '|'
namespace PrintTB
{
	void PrintLTTable(LT::LexTable);
	void PrintIDTable(IT::IdTable);
	void PrintText(In::IN in, LT::LexTable lextable, IT::IdTable);
	const char* ReturnIdType(IT::IDTYPE idtype);
	const char* ReturnIddatatype(IT::IDDATATYPE datatype);
	void InputValue(IT::Entry value, std::ofstream&);
	void PrintPrefix(IT::Entry value, std::ofstream&);
	void PrintNameId(IT::Entry, std::ofstream&);
	std::ofstream CreateFileForLT();
	std::ofstream CreateFileForID();
	std::ofstream CreateFileForText();
}