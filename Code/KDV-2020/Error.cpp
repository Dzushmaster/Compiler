#include "Error.h"
namespace Error
{
	// 0-99 - системные ошибки
	// 100-109 - ошибки параметров
	// 110-119 - ошибки открытия и чтения файлов
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,"[SYST] Invalid error code/ Недопустимый код ошибки"),ERROR_ENTRY(1, "[SYST] System crash/ Системный сбой"),ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"[SYST] The -in parameter must be given/Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"[SYST] Length of input parameter exceeded/Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"[SYST] Error opening source file (-in)/Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111,"[SYST] Invalid character in source file (-in)/ Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112,"[SYST] Error creating log file (-log)/ Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY(113,"[LEX] Error creating token table file/ Ошибка при создании файла таблицы лексем"), 
		ERROR_ENTRY(114,"[LEX] Error creating ID table file/ Ошибка при создании файла таблицы идентификаторов"),
		ERROR_ENTRY(115,"Error creating file after processing/ Ошибка при создании файла после обработки"),					ERROR_ENTRY_NODEF(116),ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		
		ERROR_ENTRY(120, "[LEX] Token size exceeded/ Превышен размер лексемы"),
		ERROR_ENTRY(121, "[LEX] Trying to get outside the table/ Попытка попасть за пределы таблицы"),
		ERROR_ENTRY(122, "[LEX] Missing closing quote/ Отсутствует закрывающая кавычка"),
		ERROR_ENTRY(123, "[LEX] The maximum size of the identity table has been exceeded/ Превышен максимальный размер таблицы идентификаторов"),
		ERROR_ENTRY(124, "[LEX] The maximum size of the lexem table has been exceeded/ Превышен максимальный размер таблицы лексем"),
		ERROR_ENTRY(125, "[LEX] Invalid start character of identifier/ Недопустимый символ начала идентификатора"),
		ERROR_ENTRY(126, "[LEX] Unable to recognize expression/ Невозможно распознать выражение"),
		ERROR_ENTRY(127, "[LEX] Attempting to infer an undefined data type/ Попытка вывести неопределенный тип данных"),
		ERROR_ENTRY(128, "[LEX] Attempting to infer an undefined identifier type/ Попытка вывести неопределенный тип идентификатора"),
		ERROR_ENTRY(129, "[LEX] Overriding/ Переопределение"),
		ERROR_ENTRY(130, "[LEX] Exceeded size of character literal [1]/Превышен размер символьного литерала[1]"),
		ERROR_ENTRY(131, "[LEX] Error, no such function exists (possibly truncation to 15 characters)/Ошибка, такой функции не существует(возможно, произошло усечение до 15 символов)"),
		ERROR_ENTRY(132, "[LEX] Error, you need to declare a variable before using it/Ошибка, необходимо объявить переменную перед ее использованием"),
		ERROR_ENTRY_NODEF(133),ERROR_ENTRY_NODEF(134),ERROR_ENTRY_NODEF(135),ERROR_ENTRY_NODEF(136),ERROR_ENTRY_NODEF(137),ERROR_ENTRY_NODEF(138),ERROR_ENTRY_NODEF(139),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300),

		//--------------------------- Semantic analyze ---------------------------
		ERROR_ENTRY(400, "[SEM] Entry point missing/Отсутствует точка входа"),
		ERROR_ENTRY(401, "[SEM] The number of entry points exceeds 1/Количество точек входа превышает 1"),
		ERROR_ENTRY(402, "[SEM] Closing \'}\' missing /Отсутствует закрывающая \'}\' скобка"),
		ERROR_ENTRY(403, "[SEM] Missing closing '\)'\/Отсутствует закрывающая '\)'\ скобка"),
		ERROR_ENTRY(404, "[SEM] Identifier not defined/Идентификатор не определен"),
		ERROR_ENTRY(405, "[SEM] Range exceeded for the specified type/Превышен диапазон значений указанного типа"),
		ERROR_ENTRY(406, "[SEM] Invalid return type/Неверный тип возвращаемого значения"),
		ERROR_ENTRY(407, "[SEM] Using operations for different data types/Использование операций для разных типов данных"),
		ERROR_ENTRY(408, "[SEM] Using invalid operations for strings/Использование недопустимых для строк операций"),
		ERROR_ENTRY(409, "[SEM] Max number of function parameters exceeded/Превышено максимальное количество параметров функции"),
		ERROR_ENTRY(410, "[SEM] Invalid number of function parameters/Неверное количество параметров функции"),
		ERROR_ENTRY_NODEF(411),
		ERROR_ENTRY(412, "[SEM] Error, division by 0/Ошибка, деление на 0"),
		ERROR_ENTRY(413, "[SEM] Error, return is not allowed in huvud/Ошибка, в huvud недопустимо наличие return"),
		ERROR_ENTRY(414, "[SEM] Error, assignment to a variable of a different type is not allowed/Ошибка, присвоение переменной другого типа недопустимо"),
		ERROR_ENTRY_NODEF(415,"[SEM] Error missing closing \']\'/ Ошибка, отсутствует закрывающая \']\'"),
		ERROR_ENTRY_NODEF(416),
		ERROR_ENTRY_NODEF(417),
		ERROR_ENTRY_NODEF(418),
		ERROR_ENTRY_NODEF(419),
		ERROR_ENTRY_NODEF10(420),ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),ERROR_ENTRY_NODEF10(450),ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),ERROR_ENTRY_NODEF10(480),ERROR_ENTRY_NODEF10(490),ERROR_ENTRY_NODEF100(500),
		
		//--------------------------- Syntactic analyze ---------------------------
		ERROR_ENTRY(600, "[SYNT] Invalid program structure/ Неверная структура программы"),
		ERROR_ENTRY(601, "[SYNT] Erroneous operator/ Ошибочный оператор"),
		ERROR_ENTRY(602, "[SYNT] Expression error/ Ошибка в выражении"),
		ERROR_ENTRY(603, "[SYNT] Error in function parameters/ Ошибочный арифметический оператор"),
		ERROR_ENTRY(604, "[SYNT] Error in the parameters of the called function/ Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY(605, "[SYNT] Error in function parameters when defining/ Ошибка в параметрах функции при определении"),
		ERROR_ENTRY(606, "[SYNT] Error in using boolean expressions/ Ошибка в использовании булевых выражений"),
		ERROR_ENTRY(607, "[SYNT] / Ошибка в условном операторе"),
		ERROR_ENTRY(608, "[SYNT] / Ошибка в операторе цикла"),
		ERROR_ENTRY(609, "[SYNT] / Ошибка в операторе вывода на экран"),
		ERROR_ENTRY(610, "[SYNT] / Ошибка в операторе, возвращающем значение"),
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
