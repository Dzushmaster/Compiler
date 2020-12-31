#include "Generation.h"
namespace GEN
{
	string FullName(IT::Entry id)//не нужна, пока лень убирать
	{
		return 0;
	}

	void codeGen(const LT::LexTable& lextable, const IT::IdTable idtable, Parm::PARM& parm)
	{
		ofstream out(parm.out);
		out << HEAD;
		out << EXTERN;
		out << CONST;
		int countCycle = 0;
		int idFunc = 0;
		int countIfElse = 0;
		bool isMain = false;
		bool isFung = false;
		bool isIf = false;
		bool isElse = false;
		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].idtype == IT::L)
			{
				out << idtable.table[i].prefix << "_" << idtable.table[i].id;
				if (idtable.table[i].iddatatype == IT::UINT)
					out << "\tDWORD\t" << idtable.table[i].value.vint <<'\n';
				if (idtable.table[i].iddatatype == IT::STR)
					out << "\tBYTE\t" << '\'' << idtable.table[i].value.vstr->str << "\',0\n";
				if (idtable.table[i].iddatatype == IT::SYMB)
					out << "\tBYTE\t" << '\'' << idtable.table[i].value.vstr->str << "\',0\n";
			}
		}
		out << DATA;
		for (int i = 0; i < idtable.size; i++)
		{
			if (idtable.table[i].idtype == IT::V)
			{
				out << idtable.table[i].prefix << "_" << idtable.table[i].id;
				if (idtable.table[i].iddatatype == IT::STR)
					out << "\tBYTE ?\n";
				if (idtable.table[i].iddatatype == IT::SYMB)
					out << "\tBYTE ?\n";
				if (idtable.table[i].iddatatype == IT::UINT)
					out << "\tDWORD ?\n";
			}
		}
		out << CODE;
		for (int i = 0; i < lextable.size; i++)
		{
			switch (LEX(i))
			{
#pragma region Function
			case LEX_FUNG:
			{
				out << idtable.table[lextable.table[i=i+2].idxTI].id<< " PROC ";
				idFunc = lextable.table[i].idxTI;
				i = i + 3;
				while (lextable.table[i].lexema != LEX_REIGHTHESIS)
				{
					if(lextable.table[i].lexema == LEX_LITERAL || lextable.table[i].lexema == LEX_ID)
						switch (idtable.table[lextable.table[i].idxTI].iddatatype)
						{
							case IT::IDDATATYPE::UINT:
							{
								out << idtable.table[lextable.table[i].idxTI].prefix << "_" << idtable.table[lextable.table[i].idxTI].id;
								out << " : DWORD, ";
								break;
							}
							case IT::IDDATATYPE::STR:
							case IT::IDDATATYPE::SYMB:
							{
								out << idtable.table[lextable.table[i].idxTI].prefix << "_" << idtable.table[lextable.table[i].idxTI].id;
								out << " : BYTE, ";
								break;
							}
						}
					i++;
				}
				out << "\n\n";
				break;
			}
#pragma endregion
#pragma region Main
				case LEX_HUVUD:
				{
					out << "\nmain PROC\n";
					isMain = true;
					break;
				}
#pragma endregion 
#pragma region Equals
				case LEX_EQUALS:
				{
					int j = i;
					while (LEX(j) != LEX_SEMICOLON)
					{
						switch (LEX(++j))
						{
							case LEX_SLUMP:
							case LEX_KRAFT:
							case LEX_ROT:
							case LEX_ID:
							case LEX_LITERAL:
							{
								if (idtable.table[lextable.table[j].idxTI].idtype == IT::IDTYPE::F|| idtable.table[lextable.table[j].idxTI].idtype == IT::IDTYPE::K)
								{
									int countParam = idtable.table[lextable.table[j].idxTI].countParam + j;
									int k = countParam;
									while (countParam != j)
									{
										switch (idtable.table[lextable.table[countParam].idxTI].iddatatype)
										{
											case IT::IDDATATYPE::UINT:
											{
												out << "push " << idtable.table[lextable.table[countParam].idxTI].prefix << "_" << idtable.table[lextable.table[countParam].idxTI].id<< '\n';
												break;
											}
											case IT::IDDATATYPE::STR:
											case IT::IDDATATYPE::SYMB:
											{
												out << "push offset" << idtable.table[lextable.table[countParam].idxTI].prefix << "_" << idtable.table[lextable.table[countParam].idxTI].id << '\n';
												break;
											}
										}
										countParam--;
									}
									out << "call " << idtable.table[lextable.table[j].idxTI].id << '\n';
									out << "push eax\n";
									j = k;
									break;
								}
								out << "\npush " << idtable.table[lextable.table[j].idxTI].prefix << "_" << idtable.table[lextable.table[j].idxTI].id << '\n';
								break;
							}
							case LEX_OPER:
							{
								switch (lextable.table[j].arithmeticSymbol)
								{
									case PLUS:
									{	
										out << "pop ebx\npop eax\nadd eax, ebx\njo EXIT_OVERFLOW\npush eax\n";
										break;
									}
									case MINUS:
									{	
										out << "pop ebx\npop eax\nsub eax, ebx\npush eax\n";
										break;
									}
									case STAR:
									{
										out << "pop ebx\npop eax\nmul ebx\njo EXIT_OVERFLOW\npush eax\n";
										break;
									}
									case DIRSLASH:
									{	
										out << "cdq\npop ebx\ncmp ebx, 0\nje SOMETHINGWRONG\npop eax\ndiv ebx\npush eax\n";
										break;
									}


								}
								break;
							}
							case LEX_SEMICOLON:
							{
								out << "\npop " << idtable.table[lextable.table[i - 1].idxTI].prefix << "_" << idtable.table[lextable.table[i - 1].idxTI].id << '\n';
								break;
							}
						}
					}
					i = j;
					break;
				}
#pragma endregion 
#pragma region Print
				case LEX_SKRIVA:
				{	
					if (idtable.table[lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::UINT)
					{
						out << "\npush " << idtable.table[lextable.table[i + 1].idxTI].prefix << "_" << idtable.table[lextable.table[i + 1].idxTI].id;
						out << "\ncall numout\n";
					}
					if (idtable.table[lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::SYMB || idtable.table[lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::STR)
					{
						out << "\npush offset " << idtable.table[lextable.table[i + 1].idxTI].prefix << "_" << idtable.table[lextable.table[i + 1].idxTI].id;
						out << "\ncall strlineout\n";
					}
					break;
				}
#pragma endregion
#pragma region While
				case LEX_MEDAN:
				{
					out << "\ncycle" << ++countCycle << ":\n";
					out << "push " << idtable.table[lextable.table[i+1].idxTI].prefix << "_" << idtable.table[lextable.table[i+1].idxTI].id << '\n';
					out << "push " << idtable.table[lextable.table[i + 3].idxTI].prefix << "_" << idtable.table[lextable.table[i + 3].idxTI].id << '\n';
					out << "pop ebx\n";
					out << "pop eax\n";
					out << "cmp eax,ebx\n";
					switch (lextable.table[i+2].arithmeticSymbol)
					{
						case EQUAL:
							out << "jne";
							break;
						case NOTEQUALS:
							out << "je";
							break;
						case LESS:
							out << "jg";
							break;
						case EQLESS:
							out << "jge";
							break;
						case GREATER:
							out << "jl";
							break;
						case EQGREATER:
							out << "jle";
							break;
					}
					out << " endcycle" << countCycle << '\n';
					i = i + 4;
					break;
				}
#pragma endregion

#pragma region ']'
				case LEX_SQ_RBRACELET:
				{
					if (isIf)
					{
						if (lextable.table[i + 1].lexema == LEX_ANNAN)
						{
							out << "jmp endElse" << countIfElse << '\n';
							isElse = true;
						}
						out << "endIf" << countIfElse << ":\n";
						isIf = false;
						break;
					}
					else if (isElse)
					{
						out << "endElse" << countIfElse << ":\n";
						isElse = false;
						break;
					}
					out << "\njmp cycle" << countCycle << '\n';
					out << "endcycle" << countCycle << ":\n";
					break;
				}
#pragma endregion

#pragma region ifElse
				case LEX_OM:
				{
					isIf = true;
					out << "push " << idtable.table[lextable.table[i + 1].idxTI].prefix << "_" << idtable.table[lextable.table[i + 1].idxTI].id << '\n';
					out << "push " << idtable.table[lextable.table[i + 3].idxTI].prefix << "_" << idtable.table[lextable.table[i + 3].idxTI].id << '\n';
					out << "pop ebx\n";
					out << "pop eax\n";
					out << "cmp eax,ebx\n";
					switch (lextable.table[i + 2].arithmeticSymbol)
					{
					case EQUAL:
						out << "je";
						break;
					case NOTEQUALS:
						out << "jne";
						break;
					case LESS:
						out << "jl";
						break;
					case EQLESS:
						out << "jle";
						break;
					case GREATER:
						out << "jg";
						break;
					case EQGREATER:
						out << "jge";
						break;
					}
					out << " beginIf" << ++countIfElse << '\n';
					out << "jmp endIf" << countIfElse << '\n';
					out << "beginIf" << countIfElse << ":\n";
					break;
				}
#pragma endregion
#pragma region Return
				case LEX_RETURN:
				{
					if (isMain)
						throw ERROR_THROW_IN(413, lextable.table[i].sn, 0);
					out << "\npush " << idtable.table[lextable.table[i+1].idxTI].prefix << "_" << idtable.table[lextable.table[i+1].idxTI].id<< '\n';
					out << "pop eax\n";
					out << "ret\n";
					break;
				}
#pragma endregion
#pragma region '}'
				case BRACELEFT:
				{
					if (isMain)
						continue;
					out <<ERRORS<<'\n'<<idtable.table[idFunc].id <<" ENDP\n";
					break;
				}
#pragma endregion 

			}
		}
		out << END;
	}
}