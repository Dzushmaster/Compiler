#pragma once
#include <iostream>
#include "Error.h"
#include "In.h"
#include "LT.h"
#include "IT.h"

namespace FST
{
	struct RELATION		//�����:������ -> ������� ����� ��������� ��
	{
		char symbol;	//������ ��������
		short nnode;	//����� ������� �������
		RELATION(char c=0x00, short ns=NULL);
	};
	struct NODE	//������� ����� ���������
	{
		short n_relation;//���������� ����������� �����
		RELATION* relations;//����������� �����
		NODE();
		NODE(short n, RELATION rel, ...);//���������� �����, ������ �����
	};
	struct FST
	{
		char* string;	//�������
		short position;
		short nstates;	//���������� ���������
		NODE* nodes;	//���� ���������
		short* rstates;//��������� ���������
		FST(char* s, short ns, NODE n, ...);
	};
	bool execute(FST& fst);
}
void choiceOfMachines(int wordSize, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable);
void choiceOfMachines(char symbol, In::IN& in, LT::LexTable& lextable, IT::IdTable& idtable);


