#include "type_traits.hpp"

struct S	{ int a; int b; };

int main(void)
{
	S 								val;
	// ft::set_const<S*, true>::type	ptr = &val;
	ft::conditional<true, const S*, S*>::type	ptr = &val;
	// const S* ptr = &val;

	ptr->a = 42;
	ptr->b = 21;
}
