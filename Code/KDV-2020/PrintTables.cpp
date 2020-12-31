#include "PrintTables.h"
namespace PrintTB
{
	std::ofstream CreateFileForLT()
	{
		std::ofstream stream;
		stream.open("Table_Of_Lexem.txt");
		if (!stream.is_open())
			throw ERROR_THROW(115);
		return stream;
	}
	std::ofstream CreateFileForID()
	{
		std::ofstream stream;
		stream.open("Table_Of_Identificators.txt");
		if (!stream.is_open())
			throw ERROR_THROW(114);
		return stream;
	}

	std::ofstream CreateFileForText()
	{
		std::ofstream Filestream;
		Filestream.open("Text_After_Lex.txt");
		if (!Filestream.is_open())
			throw ERROR_THROW(116);
		return Filestream;
	}

	void PrintText(In::IN in, LT::LexTable lextable, IT::IdTable idtable)
	{
		std::ofstream stream = CreateFileForText();
		stream << "Обработанный текст\n";
		int line = 0;
		stream << ++line << " ";
		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == LEX_ID || lextable.table[i].lexema == LEX_LITERAL)
			{
				stream << lextable.table[i].lexema;
				stream << '[' << lextable.table[i].idxTI << ']';
				continue;
			}
			if (lextable.table[i].lexema == LINE_BREAK)
			{
				stream << '\n';
				stream << ++line << " ";
				continue;
			}
			stream << lextable.table[i].lexema;
		}
	}
	void PrintLTTable(LT::LexTable lextable)
	{
		std::ofstream stream = CreateFileForLT();
		stream << "Размер таблицы лексем: ";
		stream << lextable.size;
		stream << "\nНомер лексемы -> Лексема -> Номер строки в исходном тексте\n";
		for (int i = 0; i < lextable.size; i++)
		{
			stream.width(6);
			stream << lextable.table[i].idxTI;
			stream.width(15);
			stream << lextable.table[i].lexema;
			stream.width(12);
			stream << lextable.table[i].sn;
			stream << '\n';
		}
		stream.close();
	}
	void PrintIDTable(IT::IdTable idtable)
	{
		std::ofstream stream = CreateFileForID();
		stream << "Размер таблицы идентификаторов: ";
		stream << idtable.size;
		stream << "\n";
		stream << "Номер идентификатора -> Идентификатор -> Тип данных -> Тип идентификатора -> Строка в тексте -> Значение\n";
		for (int i = 0; i < idtable.size; i++)//исправить вывод в файл(если нет id, не выводить id)
		{
			stream.width(5);
			stream << i + 1;
			PrintPrefix(idtable.table[i], stream);
			stream.width(22);
			stream << ReturnIddatatype(idtable.table[i].iddatatype);
			stream.width(20);
			stream << ReturnIdType(idtable.table[i].idtype);
			stream.width(10);
			stream << idtable.table[i].idxfirstLE;
			stream.width(35);
			InputValue(idtable.table[i], stream);
			stream << '\n';
		}
		stream.close();
	}
	void PrintNameId(IT::Entry currentElem, std::ofstream& stream)
	{
		if (currentElem.id[0] != '\0')
			stream << currentElem.id;
	}
	void PrintPrefix(IT::Entry currentElem, std::ofstream& stream)
	{
		if (currentElem.prefix[0] != '\0' && currentElem.id)
		{
			stream.width(20);
			stream << currentElem.prefix;
			stream << "::";
		}
		else
		{
			stream.width(22);
			stream << "";
		}
		PrintNameId(currentElem, stream);
	}
	const char* ReturnIddatatype(IT::IDDATATYPE datatype)
	{
		if (datatype == IT::IDDATATYPE::STR)
			return "symb";
		if (datatype == IT::IDDATATYPE::SYMB)
			return "symb";
		if (datatype == IT::IDDATATYPE::UINT)
			return "ohela";
		throw ERROR_THROW(127);
	}
	const char* ReturnIdType(IT::IDTYPE idtype)
	{
		switch (idtype)
		{
		case 1:
			return "variable";
		case 2:
			return "function";
		case 3:
			return "parameter";
		case 4:
			return "literal";
		case 5:
			return "outsideFunction";
		}
		throw ERROR_THROW(128);
	}
	void InputValue(IT::Entry value, std::ofstream& stream)
	{
		if (value.idtype == IT::IDTYPE::F)
		{
			stream << "";
			return;
		}
		if ((value.iddatatype == IT::IDDATATYPE::INT || value.iddatatype == IT::IDDATATYPE::UINT) && value.idtype != IT::IDTYPE::P)
		{
			char symb[11];
			_itoa_s(value.value.vint, symb, 10);
			stream << symb;
			return;
		}
		if (value.iddatatype == IT::IDDATATYPE::STR && value.idtype != IT::IDTYPE::P)
			stream << value.value.vstr->str;
	}
}