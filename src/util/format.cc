#include "format.hh"

std::string fFormatNumber(int number)
{
	std::string numberWithFormat = std::to_string(number);
	int insertPosition = numberWithFormat.length() - 3;
	while (insertPosition > 0)
	{
		numberWithFormat.insert(insertPosition, ",");
		insertPosition -= 3;
	}

	return numberWithFormat;
}