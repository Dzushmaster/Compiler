#include "Error.h"
namespace Error
{
	// 0-99 - ��������� ������
	// 100-109 - ������ ����������
	// 110-119 - ������ �������� � ������ ������
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,"[SYST] Invalid error code/ ������������ ��� ������"),ERROR_ENTRY(1, "[SYST] System crash/ ��������� ����"),ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"[SYST] The -in parameter must be given/�������� -in ������ ���� �����"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"[SYST] Length of input parameter exceeded/��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"[SYST] Error opening source file (-in)/������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111,"[SYST] Invalid character in source file (-in)/ ������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112,"[SYST] Error creating log file (-log)/ ������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113,"[LEX] Error creating token table file/ ������ ��� �������� ����� ������� ������"), 
		ERROR_ENTRY(114,"[LEX] Error creating ID table file/ ������ ��� �������� ����� ������� ���������������"),
		ERROR_ENTRY(115,"Error creating file after processing/ ������ ��� �������� ����� ����� ���������"),					ERROR_ENTRY_NODEF(116),ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		
		ERROR_ENTRY(120, "[LEX] Token size exceeded/ �������� ������ �������"),
		ERROR_ENTRY(121, "[LEX] Trying to get outside the table/ ������� ������� �� ������� �������"),
		ERROR_ENTRY(122, "[LEX] Missing closing quote/ ����������� ����������� �������"),
		ERROR_ENTRY(123, "[LEX] The maximum size of the identity table has been exceeded/ �������� ������������ ������ ������� ���������������"),
		ERROR_ENTRY(124, "[LEX] The maximum size of the lexem table has been exceeded/ �������� ������������ ������ ������� ������"),
		ERROR_ENTRY(125, "[LEX] Invalid start character of identifier/ ������������ ������ ������ ��������������"),
		ERROR_ENTRY(126, "[LEX] Unable to recognize expression/ ���������� ���������� ���������"),
		ERROR_ENTRY(127, "[LEX] Attempting to infer an undefined data type/ ������� ������� �������������� ��� ������"),
		ERROR_ENTRY(128, "[LEX] Attempting to infer an undefined identifier type/ ������� ������� �������������� ��� ��������������"),
		ERROR_ENTRY(129, "[LEX] Overriding/ ���������������"),
		ERROR_ENTRY(130, "[LEX] Exceeded size of character literal [1]/�������� ������ ����������� ��������[1]"),
		ERROR_ENTRY(131, "[LEX] Error, no such function exists (possibly truncation to 15 characters)/������, ����� ������� �� ����������(��������, ��������� �������� �� 15 ��������)"),
		ERROR_ENTRY(132, "[LEX] Error, you need to declare a variable before using it/������, ���������� �������� ���������� ����� �� ��������������"),
		ERROR_ENTRY_NODEF(133),ERROR_ENTRY_NODEF(134),ERROR_ENTRY_NODEF(135),ERROR_ENTRY_NODEF(136),ERROR_ENTRY_NODEF(137),ERROR_ENTRY_NODEF(138),ERROR_ENTRY_NODEF(139),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300),

		//--------------------------- Semantic analyze ---------------------------
		ERROR_ENTRY(400, "[SEM] Entry point missing/����������� ����� �����"),
		ERROR_ENTRY(401, "[SEM] The number of entry points exceeds 1/���������� ����� ����� ��������� 1"),
		ERROR_ENTRY(402, "[SEM] Closing \'}\' missing /����������� ����������� \'}\' ������"),
		ERROR_ENTRY(403, "[SEM] Missing closing '\)'\/����������� ����������� '\)'\ ������"),
		ERROR_ENTRY(404, "[SEM] Identifier not defined/������������� �� ���������"),
		ERROR_ENTRY(405, "[SEM] Range exceeded for the specified type/�������� �������� �������� ���������� ����"),
		ERROR_ENTRY(406, "[SEM] Invalid return type/�������� ��� ������������� ��������"),
		ERROR_ENTRY(407, "[SEM] Using operations for different data types/������������� �������� ��� ������ ����� ������"),
		ERROR_ENTRY(408, "[SEM] Using invalid operations for strings/������������� ������������ ��� ����� ��������"),
		ERROR_ENTRY(409, "[SEM] Max number of function parameters exceeded/��������� ������������ ���������� ���������� �������"),
		ERROR_ENTRY(410, "[SEM] Invalid number of function parameters/�������� ���������� ���������� �������"),
		ERROR_ENTRY_NODEF(411),
		ERROR_ENTRY(412, "[SEM] Error, division by 0/������, ������� �� 0"),
		ERROR_ENTRY(413, "[SEM] Error, return is not allowed in huvud/������, � huvud ����������� ������� return"),
		ERROR_ENTRY(414, "[SEM] Error, assignment to a variable of a different type is not allowed/������, ���������� ���������� ������� ���� �����������"),
		ERROR_ENTRY_NODEF(415,"[SEM] Error missing closing \']\'/ ������, ����������� ����������� \']\'"),
		ERROR_ENTRY_NODEF(416),
		ERROR_ENTRY_NODEF(417),
		ERROR_ENTRY_NODEF(418),
		ERROR_ENTRY_NODEF(419),
		ERROR_ENTRY_NODEF10(420),ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),ERROR_ENTRY_NODEF10(450),ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),ERROR_ENTRY_NODEF10(480),ERROR_ENTRY_NODEF10(490),ERROR_ENTRY_NODEF100(500),
		
		//--------------------------- Syntactic analyze ---------------------------
		ERROR_ENTRY(600, "[SYNT] Invalid program structure/ �������� ��������� ���������"),
		ERROR_ENTRY(601, "[SYNT] Erroneous operator/ ��������� ��������"),
		ERROR_ENTRY(602, "[SYNT] Expression error/ ������ � ���������"),
		ERROR_ENTRY(603, "[SYNT] Error in function parameters/ ��������� �������������� ��������"),
		ERROR_ENTRY(604, "[SYNT] Error in the parameters of the called function/ ������ � ���������� ���������� �������"),
		ERROR_ENTRY(605, "[SYNT] Error in function parameters when defining/ ������ � ���������� ������� ��� �����������"),
		ERROR_ENTRY(606, "[SYNT] Error in using boolean expressions/ ������ � ������������� ������� ���������"),
		ERROR_ENTRY(607, "[SYNT] / ������ � �������� ���������"),
		ERROR_ENTRY(608, "[SYNT] / ������ � ��������� �����"),
		ERROR_ENTRY(609, "[SYNT] / ������ � ��������� ������ �� �����"),
		ERROR_ENTRY(610, "[SYNT] / ������ � ���������, ������������ ��������"),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};
}
using namespace Error;
ERROR Error::geterror(int id)
{
	return (id<0 || id>ERROR_MAX_ENTRY) ? errors[0] : errors[id];
}
ERROR Error::geterrorin(int id, int line = -1, int col = -1)
{
	if (id<0 || id>ERROR_MAX_ENTRY)
		return errors[0];
	ERROR result{ id,"",line,col };//"" - message
	int index = 0;
	while (errors[id].message[index] != '\0')
		result.message[index] = errors[id].message[index++];
	result.message[index] = '\0';
	return result;
}
