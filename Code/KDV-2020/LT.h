#pragma once
#include <fstream>
#include <string>
#include "Lexemes.h"
#define LEXEMA_FIXSIZE 1				//������������� ������ �������
#define LT_MAXSIZE 4096					//������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff		//��� �������� ������� ���������������
#define AMOUNTEXPRESSIONS 10

//���������� � in ��� ���������� � ���� ������ �� ����� ���������, �� ������ �������� ��� �������
namespace LT//������� ������
{
	struct Entry
	{
		char lexema;//�������
		char arithmeticSymbol;
		int sn;						//����� ������ � �������� ������
		int idxTI;					//������ � ������� ��������������� ��� LT_TI_NULLIDX
		int priority;				//��������� ��������
	};
	struct LexTable//��������� ������� ������
	{
		int maxsize;//������� ������� ������ < LT_MAXSIZE 
		int size;//������� ������ ������� ������ <maxsize
		Entry* table;//������ ����� ������� ������
	};

	LexTable Create(//������� ������� ������
		int size//������� ������� ������ < LT_MAXSIZE
	);
	void Add(		//�������� ������ � ������� ������
		LexTable& lextable, //��������� ������� ������
		Entry entry			//������ ������� ������
	);
	Entry GetEntry(//�������� ������ ������� ������
		LexTable& lextable,//��������� ������� ������
		int n//����� ���������� ������
	);
	void Delete(LexTable& lextable);//������� ������� ������(���������� ������)
};
