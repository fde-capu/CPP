/* ******************************************* */
/*                                             */
/*                     :|||::|||:||||:::|||||| */
/* Base.hpp            :|::||::|::|:||::::||:| */
/*                     |:|:|:::|::::::|:|:|||: */
/*                                             */
/*                                             */
/* C20210622150744 |:||::                      */
/* U20210622162716 :||||:                      */
/*                                             */
/* ******************************************* */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		Base(void);
		virtual ~Base(void); // Just to make polymorphic, also base classes w/o virtual destructors are dangerous.
};

#endif
