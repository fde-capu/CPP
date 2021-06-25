/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* Data.cpp            |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619184158 |:|:||                      */
/* U20210619194312 ||:::|                      */
/*                                             */
/* ******************************************* */

#include "Data.hpp"
#include <iostream>

Data::Data(void)
{
	str_a = new std::string(random_string("ConstructA:", 5));
	r_int = random_int(0, 42);
	str_b = new std::string(random_string("ConstructB:", 5));
	return ;
}

Data::~Data(void)
{
	delete str_a;
	delete str_b;
	return ;
}

Data::Data(Data const & src)
{
	*this = src;
}

Data & Data::operator = (const Data & rhs)
{
	if (this != &rhs)
	{
		str_a = new std::string(*rhs.str_a);
		r_int = rhs.r_int;
		str_b = new std::string(*rhs.str_b);
	}
	return *this;
}
