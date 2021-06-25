/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* Data.hpp            |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619192749 :||:::                      */
/* U20210619193156 :||::|                      */
/*                                             */
/* ******************************************* */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

std::string random_string(std::string fixed, int len);
int random_int(int min, int max);

struct s_block
{
	std::string * str_a;
	int r_int;
	std::string * str_b;
};

class Data
{
	private:
		std::string * str_a; // 8 bytes.
		int r_int; // 4 bytes;
		std::string * str_b; // 8 more bytes. Nhac!
	public:
		Data(void);
		Data(Data const & src);
		Data & operator = (const Data &);
		~Data(void);
};

#endif
