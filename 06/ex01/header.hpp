/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* header.hpp          |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619183649 :|||||                      */
/* U20210619184306 :|:|::                      */
/*                                             */
/* ******************************************* */

#ifndef HEADER_HPP
# define HEADER_HPP
# include "Data.hpp"

void hex_dump(const s_block &block_as_struct);
void plot(s_block *block_as_struct, std::string title);
void plot(void *block_as_void, std::string title);
void plot(Data *block_as_data, std::string title);
void plot(Data &block_as_data, std::string title);

#endif
