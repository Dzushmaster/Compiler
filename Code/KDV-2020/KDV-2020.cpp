#include "Library.h"
int wmain(int argc, wchar_t*argv[])
{
	setlocale(LC_CTYPE, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		//создаю таблицу лексем и таблицу идентификаторов
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, L"Тест:", L"без ошибок", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		//------------------Работает---------------
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		IT::IdTable idtable = IT::Create(TI_MAXSIZE);
		//-----------------------------------------
		In::IN in = In::getin(parm.in, lextable, idtable);
		PrintTB::PrintIDTable(idtable);
		PrintTB::PrintText(in, lextable, idtable);
		//MFST_TRACE_START								//отладка
		MFST::Mfst Mfst(lextable, GRB::getGreibach());	//автомат
		if (!Mfst.start() ||! Mfst.savededucation())								//старт синтаксического анализа
			return -1;																//сохранить вывести правила вывода
		//Mfst.printRules();									//отладка: вывести правила вывода
		SA::SemAnalys(lextable, idtable);
		PN::workWithPolishNotation(lextable, idtable);
		PrintTB::PrintLTTable(lextable);
		GEN::codeGen(lextable,idtable,parm);
		system("color 0A");
		std::cout << "\nГенерация завершена, можете запускать ваш проект\n";
		Log::WriteIn(log, in);
		Log::Close(log);
		LT::Delete(lextable);
		IT::Delete(idtable);
		delete[] in.text;			//Удаляем использованную память
	}
	catch (Error::ERROR e)
	{
		system("color 0C");
		Log::WriteError(log, e);
	}

	return 0;
}