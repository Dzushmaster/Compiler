#pragma once
#include "Error.h"

typedef short GRBALPHABET;	// ������� �������� ���������� ��������� > 0,����������� < 0

namespace GRB
{
	struct Rule	//������� � ���������� 
	{
		GRBALPHABET nn;			//���������� (����� ������ �������) < 0
		int iderror;			//������������� ���������������� ���������
		short size;				//�������(������ ����� �������)

		struct Chain
		{
			short size;			//����� �������
			GRBALPHABET* nt;	//������� ����������(>0) � �������������� (<0)

			Chain() { size = 0; nt = 0; };

			Chain(short psize, GRBALPHABET s, ...);	// psize ���������� �������� � �������, s ������� (�������� ��� �� ��������)

			char* getCChain(char* b);									//�������� ������ ������� �������
			static GRBALPHABET T(char t) { return GRBALPHABET(t); }		// ��������
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); }	// �� ��������
			static bool isT(GRBALPHABET s) { return s > 0; }			// ��������?	
			static bool isN(GRBALPHABET s) { return s < 0; }			// ����������?
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(-s); };

		}*chains;

		Rule() { nn = 0x00; size = 0; }

		Rule(
			GRBALPHABET pnn,		//���������� (< 0)
			int iderror,			//������������� ���������������� ��������� (Error)
			short psize,			//���������� ������� - ������ ������ �������
			Chain c, 				//��������� ������� - ������ ������ �������
			...
		);

		char* getCRule(char* b, short nchain);							//�������� ������� � ���� N->�������
		short getNextChain(GRBALPHABET t, Rule::Chain& pchain, unsigned short j);//�������� ��������� �� j ���������� ������� ������� �� ����� ��� -1
	};

	struct Greibach				// ���������� �������
	{
		GRBALPHABET size;		//���������� ������
		GRBALPHABET startN;		//��������� ������
		GRBALPHABET stbottomT;  //��� �����
		Rule* rules;			//��������� ������

		Greibach()
		{
			size = 0;
			startN = 0;
			stbottomT = 0;
			rules = 0;
		};
		Greibach(
			GRBALPHABET startN,
			GRBALPHABET pstbottomT,
			short psize,
			Rule r,
			...
		);

		short getRule(GRBALPHABET pnn, Rule& prule);	//�������� �������, ������������ ����� ������� ��� -1
		Rule getRule(short n);							//�������� ������� �� ������
	};

	Greibach getGreibach();								//�������� ����������
};
