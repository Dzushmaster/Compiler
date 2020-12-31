#include <iostream>
#include "Parm.h"
#include "Error.h"
#include <string.h>
using namespace Parm;
#pragma warning(disable : 4996)
	PARM Parm::getparm(int argc, wchar_t* argv[])
	{
		PARM parm;
		bool CheckIn = false;
		bool CheckOut = false;
		bool CheckLog = false;
		int indexIn = 0;
		int indexOut = 0;
		int indexLog = 0;
		for (int i = 0; i < argc; i++)
		{
			if (wcsstr(argv[i], L"-in:"))
			{
				CheckIn = true;
				indexIn++;
			}
			else if (wcsstr(argv[i], L"-out:"))
			{
				CheckOut = true;
				indexOut++;
			}
			else if (wcsstr(argv[i], L"-log:"))
			{
				CheckLog = true;
				indexLog++;
			}
		}
		if (!CheckIn)
			throw ERROR_THROW(100);
		if (wcslen(argv[indexIn]) > PARM_MAX_SIZE)
			throw ERROR_THROW(104);
		wcscpy(parm.in, argv[indexIn] + 4);
		
		if (!CheckOut)
		{
			wcscpy_s(parm.out, argv[indexIn] + 4);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}
		else
		{
			if (wcslen(argv[indexOut]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
			wcscpy_s(parm.out, argv[indexOut+1] + 5);
		}
		
		if (!CheckLog)
		{
			wcscpy_s(parm.log, argv[indexIn] + 4);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}
		else
		{
			if (wcslen(argv[indexLog]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
			wcscpy_s(parm.log, argv[indexLog+2] + 5);
		}
		return parm;
	}
