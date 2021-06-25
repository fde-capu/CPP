/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* main.cpp            |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619183712 :::::|                      */
/* U20210619194200 |||:|:                      */
/*                                             */
/* ******************************************* */

/*
** Notes:
**
** As can be seen on the `plot`, the `int` variable
** actually maps to 8 bytes. This is due to memory
** alignment.
*/

#include "CoplienTest.hpp"
#include "header.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits.h>

std::string random_string(std::string fixed, int len)
{
	std::stringstream out;
	out << fixed;
	for (int i = 0; i < len; i++)
		out << static_cast<unsigned char>((rand() % ('~' - ' ')) + ' ');
	return out.str();
}

int random_int(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

void * serialize(void)
{
	s_block * block = new s_block();
	block->str_a = new std::string(random_string("StringA:", 5));
	block->r_int = random_int(4200, 4242);
	block->str_b = new std::string(random_string("StringB:", 5));
	return block;
}

Data * deserialize(void * raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	void * block = serialize();
	plot(block, "block (heap)");

	Data * data = new Data();
	plot(data, "data (defaults, heap)");
	Data * data_save_for_deletion = data;
	data = deserialize(block); // `data` is flashed over serialized `block`.
	plot(data, "data (deserialized, heap)");

	delete data_save_for_deletion;
	delete data; // Since is same address, deletes block.

	CoplienTestExec<Data>(); // Bonus: this has been implemented for future use.
	return 0;
}
