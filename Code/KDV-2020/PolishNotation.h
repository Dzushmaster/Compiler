#pragma once
#include "LT.h"
#include "IT.h"
#include <stack>
#include <queue>

namespace PN
{
	void workWithPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable);
	int PolishNotation(int lexPos, LT::LexTable& lextable, IT::IdTable idtable);
	int ChangeLex(int lexPos, int lexIndex, LT::LexTable& lextable, std::queue<LT::Entry> queue);
}
//����� PolishNotation �� ������ ������� c ������� �������
//���� ����� �� =, �� ��������� �������� ������. � ������� ���������� ����� �������, ��� ��������� '='� �������
//� ���� ������� ���� �� while(lextable.table[i].lexema!=';')
//���������� ������ ������,
//���� �� ����� v ��� ������, �� ���������� �������������� ������ � ����, ���� �� �����, �� � ������
//���� � ����� ���� ������ � ����� �� �����������, �� ������ ��� � �������� ������
//���� � ����������� ����, �� ������ ���������� �����
//���� � ����������� ������, �� ����� ������ � ������


//��� ������ � ��������� ���� ������ � ������� ������ ������� �� @
//� ����������� ���������� � ���, ��������� ������� ����� @, ���������� �����