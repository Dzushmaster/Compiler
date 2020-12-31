#include "PolishNotation.h"
#include <iostream>
#include <cstdlib>
#pragma warning(disable : 4996)
namespace PN
{
	void workWithPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable)
	{
		for (int lextable_pos = 0; lextable_pos < lextable.size; lextable_pos++)
		{
			if (lextable.table[lextable_pos].lexema == LEX_EQUALS)
			{
				lextable_pos = PolishNotation(lextable_pos+1, lextable, idtable);
			}
		}
	}
	int PolishNotation(int lexPos,LT::LexTable& lextable,IT::IdTable idtable)
	{
		std::queue<LT::Entry> queue;
		std::stack <LT::Entry> steck;
		int countParams = 0;
		bool isParam = false;
		int Lexindex = lexPos;
		while (lextable.table[Lexindex].lexema!=LEX_SEMICOLON)
		{
			switch (lextable.table[Lexindex].lexema)
			{
				case LEX_OPER:
				{
					if (steck.empty() || steck.top().arithmeticSymbol == LEX_LEFTHESIS) 
						steck.push(lextable.table[Lexindex]);
					else
					{
						while (!steck.empty() && steck.top().priority >= lextable.table[Lexindex].priority)
						{
							queue.push(steck.top());
							steck.pop();
						}
						steck.push(lextable.table[Lexindex]);
					}
					break;
				}
				case LEX_SLUMP:
				case LEX_KRAFT:
				case LEX_ROT:
				case LEX_LITERAL:
				case LEX_ID:
					if (IT::GetEntry(idtable,lextable.table[Lexindex].idxTI).idtype == IT::F 
						|| IT::GetEntry(idtable, lextable.table[Lexindex].idxTI).idtype == IT::K)
					{
						queue.push(lextable.table[Lexindex]);
					}
					else
						queue.push(lextable.table[Lexindex]);
					break;
				case LEX_LEFTHESIS:
				{
					steck.push(lextable.table[Lexindex]);
					break;
				}
				case LEX_REIGHTHESIS:
				{
					while (steck.top().arithmeticSymbol != LEX_LEFTHESIS)
					{
						queue.push(steck.top()); steck.pop();
					}
					steck.pop();
					break;
				case LEX_COMMA:
					bool isLeftBrace = true;
					if (steck.top().arithmeticSymbol == LEX_LEFTHESIS)
						isLeftBrace = false;
					else
					{
						queue.push(steck.top()); steck.pop();
					}
					break;
				}
			}
			Lexindex++;
		}
		if (!steck.empty())
		{
			queue.push(steck.top()); steck.pop();
		}
		return ChangeLex(lexPos,Lexindex, lextable, queue);
	}
	int ChangeLex(int lexPos,int lexIndex, LT::LexTable&lextable, std::queue<LT::Entry> queue)
	{
		int index = 0;
		LT::Entry entry;
		entry.sn = -1;
		entry.idxTI = -1;
		entry.lexema = 'N';
		for (int i = queue.size(); i < lexIndex - lexPos; i++)
			queue.push(entry);
		for (; !queue.empty(); index++)
		{
			lextable.table[lexPos + index] = queue.front();
			queue.pop();
		}
		return lexPos + index;
	}
}
