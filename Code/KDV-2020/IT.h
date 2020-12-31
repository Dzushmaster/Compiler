#pragma once
#define ID_MAXSIZE 15				//������������ ���������� �������� � ��������������
#define TI_MAXSIZE 4096				//������������ ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT 0x00000000	//�������� �� ��������� ��� ���� integer
#define TI_STR_DEFAULT 0x00			//�������� �� �������� ��� ���� string
#define TI_NULLIDX 0xffffffff		//��� �������� ������� ���������������
#define TI_STR_MAXSIZE 255
#define PREFIX_SIZE 15
#include <iostream>
namespace IT
{
	enum IDDATATYPE {INT = 1,UINT = 2 ,STR = 3, SYMB = 4};//���� ������ integer � string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, K = 5};//���� ���������������: ����������, �������, ��������, �������, ��������� �������
	struct Entry						//������ ������� ���������������
	{
		int idxfirstLE;								//������ ������ ������ � ������� ������
		char id[ID_MAXSIZE+1];						//�������������(������������� ��������� �� ID_MAXSIZE)
		char prefix[PREFIX_SIZE+1];					//������������ ��� ����������� ������� ���������
		short countParam = 0;							
		IDDATATYPE iddatatype;						//��� ������
		IDTYPE idtype;								//��� ��������������
		union
		{
			int vint;
			char symb;
			struct
			{
				char ken;						//���������� �������� � string
				char str[TI_STR_MAXSIZE - 1];	//������� string
			}vstr[TI_STR_MAXSIZE];				//�������� string
		}value;//�������� ��������������
	};
	struct IdTable				//��������� ������� ���������������
	{
		int maxsize;			//������� ������� ��������������� <TI_MAXSIZE
		int size;				//������� ������ ������� ��������������� < maxsize
		Entry* table;			//������ ����� ������� ���������������
	};
	IdTable Create(				//������� ������� ���������������
		int size				//������� ������� ���������������
	);
	void Add(					//�������� ������ � ������� ���������������
		IdTable& idtable,		//��������� ������� ���������������
		Entry entry					// ����� ���������� ������
	);
	Entry GetEntry(				//�������� ������ ������� ���������������
		IdTable& idtable,		//��������� ������� ���������������
		int n		//�������������
	);
	bool IsId(					
		Entry& elemOfTable,			//��������� ������� ���������������
		Entry elemTable
		);
	bool RightID(Entry elemOfTable, char* id, char* prefix);
	bool RightID(Entry elemOfTable, char* id);
	int GetIdxTI(const IdTable& idtable,char* word, char* prefix);
	bool IsOtherFunc(Entry&, Entry);
	bool LitIsRepeated(Entry& elemOfTable, char lit[ID_MAXSIZE]);
	bool LitIsRepeated(Entry& elemOfTable, int lit);
	void Delete(IdTable& idtable);//������� ������� ������(���������� ������)
}