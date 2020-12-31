#include "Out.h"
#include "Error.h"
#include <time.h>
using namespace Out;

	OUT Out::getout(wchar_t outfile[])
	{
		OUT temp;
		temp.stream = new ofstream;
		temp.stream->open(outfile);
		if (!temp.stream->is_open())
		{
			temp.stream->close();
			throw ERROR_THROW(114);
		}
		wcscpy_s(temp.logfile, outfile);

		return temp;
	}
	void Out::WriteAnalyze(OUT out, In::IN in, Log::LOG log)
	{
		//int j=0;
		//int chain = 0;
		////*out.stream << "��������� �������� �����:" << IN_CODE_ENDL << in.text << IN_CODE_ENDL;

		//time_t rawtime;
		//struct tm timeinfo;								//��������� �������� ������� �����
		//char buffer[PARM_MAX_SIZE];
		//time(&rawtime);									//������� ���� � ��������
		//localtime_s(&timeinfo, &rawtime);				//������� ��������� �����, �������������� � ���������
		//*out.stream << IN_CODE_ENDL << "----- ������ ----- ";
		//strftime(buffer, 300, " ����: %d.%m.%Y %H:%M:%S", &timeinfo);
		//*out.stream << buffer << " ----- " << IN_CODE_ENDL << IN_CODE_ENDL;
		//������ �������������� ��������� ����� � ����� ��� ��� � VS
		//����� ������ �� ������
	}
	void Out::OutClose(OUT out)
	{
		out.stream->close();
		delete out.stream;
		out.stream = NULL;
	}
