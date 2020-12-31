#pragma once
#include "GRB.h"
#include "LT.h"
#include <stack>
#include "Error.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3

template <typename T>
class Stack
{
private:
	std::stack<T> steck;
public:
	void push(T st) {
		steck.push(st);
	}
	void pop() {
		steck.pop();
	}
	T top() {
		return steck.top();
	}
	int size() {
		return steck.size();
	}
	T operator[](int s) {
		std::stack<T> st;
		st = steck;
		for (int i = (s + 1); i < steck.size(); i++)
		{
			st.pop();
		}
		return st.top();
	}
};

typedef Stack<short> MFSTSTSTACK;

#define NS(n)	GBR::Rule::Chain::N(n)
#define TS(n)	GBR::Rule::Chain::T(n)
#define ISNS(n) GBR::Rule::Chain::isN(n)

static int FST_TRACE_n = -1;
static char rbuf[205]{}, sbuf[205]{}, lbuf[1024]{};

#define MFST_TRACE_START	std::cout.setf(std::ios::left);									\
							std::cout.width (4); std::cout <<" ���"<< ':';					\
							std::cout.width(20); std::cout <<" �������";					\
							std::cout.width(30); std::cout <<" ������� �����";				\
							std::cout.width(20); std::cout <<" ����";						\
							std::cout <<std::endl;

#define MFST_TRACE1			std::cout.setf(std::ios::left);									\
							std::cout.width (4); std::cout<<++FST_TRACE_n << ": ";			\
							std::cout.width(20); std::cout<<rule.getCRule(rbuf, nrulechain);\
							std::cout.width(30); std::cout<<getCLenta(lbuf, lenta_position);\
							std::cout.width(20); std::cout<<getCSt(sbuf);					\
							std::cout <<std::endl;

#define MFST_TRACE2			std::cout.setf(std::ios::left);									\
							std::cout.width (4); std::cout<<FST_TRACE_n<< ": ";				\
							std::cout.width(20); std::cout<< " ";							\
							std::cout.width(30); std::cout<<getCLenta(lbuf, lenta_position);\
							std::cout.width(20); std::cout<<getCSt(sbuf);					\
							std::cout <<std::endl;

#define MFST_TRACE3			std::cout.setf(std::ios::left);									\
							std::cout.width (4); std::cout<<++FST_TRACE_n << ": ";			\
							std::cout.width(20); std::cout<< " ";							\
							std::cout.width(30); std::cout<<getCLenta(lbuf, lenta_position);\
							std::cout.width(20); std::cout<<getCSt(sbuf);					\
							std::cout <<std::endl;

#define MFST_TRACE4(c)		std::cout.width(4);  std::cout << ++FST_TRACE_n << ": "; std::cout.width(20); std::cout << c << std::endl;
#define MFST_TRACE5(c)		std::cout.width(4);  std::cout << FST_TRACE_n   << ": "; std::cout.width(20); std::cout << c << std::endl;
#define MFST_TRACE6(c,k)	std::cout.width(4);  std::cout << FST_TRACE_n   << ": "; std::cout.width(20); std::cout << c << k << std::endl;
#define	MFST_TRACE7			std::cout.width(4);  std::cout << state.lenta_position<<": ";						\
							std::cout.width(20); std::cout << rule.getCRule(rbuf, state.nrulechain) << std::endl;


namespace MFST
{
	struct MfstState			// ��������� �������� (��� ����������)
	{
		short lenta_position;	// ������� �� �����
		short nrule;			// ����� �������� �������
		short nrulechain;		// ����� ������� �������, �������� �������
		MFSTSTSTACK st;			// ���� ��������

		MfstState();
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrulechain	// ����� ������� �������, �������� �������
		);
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrule,		// ����� �������� �������
			short pnrulechain	// ����� ������� �������, �������� �������
		);

	};

	struct Mfst					// ���������� �������
	{
		enum RC_STEP			//��� �������� ������� step
		{
			NS_OK,				// ������� ������� � �������, ������� �������� � ���� 
			NS_NORULE,			// �� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN,		// �� ������� ��������� ������� ������� (������ � �������� ����)
			NS_ERROR,			// ���������� �������������� ������ ����������
			TS_OK,				// ���. ������ ����� == ������� �����, ������������ �����, pop �����
			TS_NOK,				// ���. ������ ����� != ������� �����, �������������� ��������� 
			LENTA_END,			// ������ ������� ����� >= lenta_size 
			SURPRISE			// ����������� ��� �������� (������ � step)
		};

		struct Mfst_Diagnosis				// �����������
		{
			short	lenta_position;		// ������� �� ����� 
			RC_STEP	rc_step;				// ��� ���������� ���� 
			short	nrule;					// ����� ������� 
			short	nrule_chain;			// ����� ������� �������
			Mfst_Diagnosis();
			Mfst_Diagnosis(					// �����������
				short plenta_position,		// �������  �� �����
				RC_STEP prc_step,			// ��� ���������� ����
				short pnrule,				// ����� �������
				short pnrule_chain			// ����� ������� �������
			);
		} diagnosis[MFST_DIAGN_NUMBER];		// ��������� ����� �������� ���������

		GRBALPHABET* lenta;					// ���������������� (TS/NS) ����� (�� LEX)
		short lenta_position;				// ������� ������� �� �����
		short nrule;						// ����� �������� �������
		short nrulechain;					// ����� ������� �������, �������� �������
		short lenta_size;					// ������ �����
		GRB::Greibach grebach;				// ���������� �������
		LT::LexTable lex;					// ��������� ������ ������������ ����������
		MFSTSTSTACK st;						// ���� ��������
		Stack<MfstState> storestate;	// ���� ��� ���������� ���������

		Mfst();
		Mfst(
			const LT::LexTable plex,		// ��������� ������ ������������ ����������
			GRB::Greibach pgrebach			// ���������� �������
		);

		char* getCSt(char* buf);								//	�������� ��������� �����
		char* getCLenta(char* buf, short pos, short n = 25);	//	�����: n ��������, ������� � pos
		char* getDiagnosis(short n, char* buf);					//	�������� n-�� ������ ����������� ��� '\0'

		bool savestate();										//	��������� ��������� ��������
		bool resetstate();										//	������������ ��������� ��������
		bool push_chain(GRB::Rule::Chain chain);				//	��������� ������� ������� � ����

		RC_STEP step();											//	��������� ��� ��������
		bool start();											//	��������� �������
		bool savediagnosis(RC_STEP pprc_step);

		void printRules();										//	������� ������������������ ������

		struct Deducation
		{
			short size;					// ���������� ����� � ������
			short* nrules;				// ����� ������� ����������
			short* nrulechains;			// ����� ������� ������� ��������(nrules)
			Deducation() {
				size = 0;
				nrules = 0;
				nrulechains = 0;
			};
		}deducation;

		bool savededucation();			// ��������� ������ ������
	};
}
