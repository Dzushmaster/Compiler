#include "Log.h"
#include "Error.h"
#include <stdarg.h>
#include <iostream>
using namespace Log;
#pragma warning(disable : 4996)
LOG Log::getlog(wchar_t logfile[])
{
	LOG result;
	result.stream = new std::ofstream;
	result.stream->open(logfile);
	if (!result.stream->is_open())
		throw ERROR_THROW(112);
	wcscpy_s(result.logfile, logfile);
	return result;
}
void Log::WriteLine(LOG Log, const char* c, ...)
{
	int i = 0; 
	char* ptr = (char*)c;
	va_list argptr;
	va_start(argptr, c);
	while (ptr != "")
	{
		(*Log.stream) << ptr;
		ptr = va_arg(argptr, char*);
	}
	(*Log.stream) << IN_CODE_ENDL;
	va_end(argptr);
}
void Log::WriteLine(LOG Log, const wchar_t* c, ...)
{
	int i = 0;
	int size;
	char* temp;
	wchar_t* ptr = (wchar_t*)c;
	va_list argptr;
	va_start(argptr, c);
	while (ptr != L"")
	{
		temp = new char[size = wcslen(ptr) + 1];
		wcstombs(temp, ptr, size + 1);
		(*Log.stream) << temp;
		ptr = va_arg(argptr, wchar_t*);
		delete[]temp;
	}
	(*Log.stream) << IN_CODE_ENDL;
}
void Log::WriteLog(LOG Log)
{
	*Log.stream << "---- Протокол ---- Дата:";
	*Log.stream << __DATE__;
	*Log.stream << "--------\n";
}
void Log::WriteParm(LOG Log, Parm::PARM parm)
{
	*Log.stream << "----Параметры----\n";
	int i = 0;
	char ch;
	*Log.stream << "log: ";
	while ((ch = wctob(parm.log[i++])) != EOF)
		*Log.stream << ch;
	i = 0;
	*Log.stream << "\n-out: ";
	while ((ch = wctob(parm.out[i++])) != EOF)
		*Log.stream << ch;
	i = 0;
	*Log.stream << "\n-in: ";
	while ((ch = wctob(parm.in[i++])) != EOF)
		*Log.stream << ch;
}
void Log::WriteIn(LOG Log, In::IN in)
{
	*Log.stream << "\n---- Исходные данные: ----" << IN_CODE_ENDL;
	*Log.stream << "Количество символов: " << in.size << IN_CODE_ENDL;
	*Log.stream << "Проигнорировано: " << in.ignor << IN_CODE_ENDL;
	*Log.stream << "Количество строк: " << in.lines;
}
void Log::WriteError(LOG Log, Error::ERROR error)
{
	if (Log.stream == NULL)
	{
		std::cout << "Ошибка " << error.id << ": " << error.message;
		if (error.inext.col > -1 && error.inext.line > -1)
			std::cout << ", строка " << error.inext.line << ", позиция " << error.inext.col;
	}
	else
	{
		std::cout << "\nОшибка " << error.id << ": " << error.message;
		if (error.inext.col > -1 && error.inext.line > -1)
			std::cout << ", строка " << error.inext.line << ", позиция " << error.inext.col;
		*Log.stream << "\nОшибка " << error.id << ": " << error.message;
		if (error.inext.col > -1 && error.inext.line > -1)
			*Log.stream << ", строка " << error.inext.line << ", позиция " << error.inext.col;
	}
}
void Log::Close(LOG Log)
{
	Log.stream->close();
	delete[]Log.stream;
}