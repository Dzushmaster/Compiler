#pragma once
#include <fstream>
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include "FST.h"
using namespace std;

namespace Out {

	struct OUT {
		wchar_t logfile[PARM_MAX_SIZE];
		ofstream* stream;
	};

	OUT getout(wchar_t outfile[]);
	void WriteAnalyze(OUT out, In::IN in, Log::LOG log);
	void OutClose(OUT out);
}