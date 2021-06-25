/* ******************************************* */
/*                                             */
/*                     :|||::|||:||||:::|||||| */
/* main.cpp            :|::||::|::|:||::::||:| */
/*                     |:|:|:::|::::::|:|:|||: */
/*                                             */
/*                                             */
/* C20210622151700 ||:|:|                      */
/* U20210622174952 ||:::|                      */
/*                                             */
/* ******************************************* */

#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iomanip>

int random_int(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

Base * generate(void)
{
	int r = random_int('A', 'C');
	Base * gen;
	if (r == 'A')
	{
		std::cout << "generate (random): Base * gen = new A(); >> A" << std::endl;
		gen = new A();
	}
	if (r == 'B')
	{
		std::cout << "generate (random): Base * gen = new B(); >> B" << std::endl;
		gen = new B();
	}
	if (r == 'C')
	{
		std::cout << "generate (random): Base * gen = new C(); >> C" << std::endl;
		gen = new C();
	}
	return gen;
}

void identify(Base* p)
{
	char id = 0;
	A * comp_a = dynamic_cast<A *>(p); // dynamic_cast returns 0 if fail.
	B * comp_b = dynamic_cast<B *>(p);
	C * comp_c = dynamic_cast<C *>(p);
	if (comp_a == p) id = 'A';
	if (comp_b == p) id = 'B';
	if (comp_c == p) id = 'C';
	std::cout << "identify(Base * p) >> " << id << std::endl;
	return ;
}

void identify(Base& p)
{
	// suject.pdf does not prohibit calling identify(Base *).
	// This function has no pointers.
	std::cout << "identify(Base & p) >> "; // << std::endl;
	identify(&p);
}

int main()
{
	std::cout << std::endl;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Base * gen = generate();
		std::cout << "                      "; // << std::endl;
		identify(gen);
		identify(*gen);
		delete gen;
		std::cout << std::endl;
	}
	return 0;
}
