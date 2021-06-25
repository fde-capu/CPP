/* ******************************************* */
/*                                             */
/*                     |||:|:|:|||:||||::|:|:: */
/* CoplienTest.hpp     |::|||:::|:||:|:::||:|| */
/*                     ::||::::|::::::||||||:| */
/*                                             */
/*                                             */
/* C20210619183746 ||||:|                      */
/* U20210619194030 |::||:                      */
/*                                             */
/* ******************************************* */

#ifndef COPLIENTEST_HPP
# define COPLIENTEST_HPP
# include <iostream>

template <class C>
void CoplienTestExec()
{
	C * c_heap = new C;
	C * d_heap = new C(*c_heap);
	delete d_heap;
	delete c_heap;
	C c_stack;
	C d_stack = c_stack;
}

class CoplienTest
{
	public:
		CoplienTest(void);
		CoplienTest(CoplienTest const & src);
		CoplienTest & operator = (CoplienTest const & rhs);
		~CoplienTest(void);
};

#endif
