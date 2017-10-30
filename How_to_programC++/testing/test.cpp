#include <iostream>
#include <cstdlib>

double Minus   (double lhs, double rhs) { return lhs - rhs; }
double Plus    (double lhs, double rhs) { return lhs + rhs; }
double Multiply(double lhs, double rhs) { return lhs * rhs; }
double Divide  (double lhs, double rhs) { return lhs / rhs; }

/* ------------------------------------------------------------------------------------- */

// solution with switch-statement
void Switch(double a, double b, char op)
{
	double result;

	switch (op)
	{
	    case '+': result = Plus(a, b);     break;
	    case '-': result = Minus(a, b);    break;
	    case '*': result = Multiply(a, b); break;
	    case '/': result = Divide(a, b);   break;
	    default:  std::cerr << "Unknown operator " << op << std::endl;
	    	      std::exit( EXIT_FAILURE );
	}

	std::cout << "Switch with Switch" << std::endl;
	std::cout << a << ' ' << op << ' ' << b << " = " << result << std::endl;
}

// solution with a function pointer - function pointer points to a function
void Switch_with_Function_Pointer(double a, double b, double (*funcPtr)(double, double))
{
	double result = funcPtr(a, b);

	std::cout << "Switch with function pointer" << std::endl;
	std::cout << result << std::endl;
}

void Replace_a_Switch()
{
	std::cout << "\nExecuting function 'Replace_a_Switch'\n";

	Switch(2, 5, '+');
	Switch_with_Function_Pointer(2, 5, Plus);
}


/* ------------------------------------------------------------------------------------- */

int DoIt  (double a, char b, char c) { std::cout << "DoIt\n";   return a+b+c; }
int DoMore(double a, char b, char c) { std::cout << "DoMore\n"; return a-b+c; }

class MyClass
{
public:
	int DoIt  (double a, char b, char c)       { std::cout << "DoIt\n";   return a+b+c; }
	int DoMore(double a, char b, char c) const { std::cout << "DoMore\n"; return a-b+c; }
};


/* ------------------------------------------------------------------------------------- */

void passPtr(int (*a_funcPtr)(double, char, char))
{
	// C short way
	// int result = a_funcPtr(12, 'a', 'b');
	int result = (*a_funcPtr)(12, 'a', 'b');

	std::cout << result << std::endl;
}

/* ------------------------------------------------------------------------------------- */
/* How to Return a Function Pointer */

/* Function takes a char and return a pointer to a function which is taking two double and
 * return double */
double (*getPtr1(char a_op))(double, double)
{
	if (a_op == '+') return &Plus;
	else             return &Minus;
}

/* define a pointer to a function which is taking two double and returns a double */
//typedef double (*ptr2Func)(double, double);
using ptr2Func = double(*)(double, double);

/* function takes char and return a function pointer which is defined with the typedef */
ptr2Func getPtr2(char a_op)
{
	if (a_op == '+') return &Plus;
	else             return &Minus;
}

void Return_A_Function_Pointer()
{
	std::cout << "Executing 'Return_A_Function_Pointer'" << std::endl;

	/* define function pointer */
	double (*ptr2func)(double, double) = nullptr;
	
	ptr2func = getPtr1('+');
	std::cout << ptr2func(2, 4) << std::endl;

	ptr2func = getPtr2('-');
	std::cout << ptr2func(2, 4) << std::endl;
}


/* ------------------------------------------------------------------------------------- */
/* How to Use Arrays of Function pointers */

void Array_of_Function_Pointers()
{
	std::cout << "Executing 'Array_of_Function_Pointers'" << std::endl;

	typedef int(*ptr2Function)(double, char, char);
	
	/* define array of function pointers returning int and takes a double and two char */
	ptr2Function funcArr1[10] = {nullptr};

	/* 2nd way directly defining the array */
	int (*funcArr2[10])(double, char, char) = {nullptr};

	/* assign the function's address - 'DoIt' and 'DoMore' are suitable functions */
	funcArr1[0] = funcArr2[0] = &DoIt;
	funcArr1[1] = funcArr2[1] = &DoMore;

	/* more assignments */

	/* call a function using an index to address the function pointer */
	for (int i = 0; i < 10; ++i)
	{
		if (funcArr1[i] != nullptr) {
			std::cout << (*funcArr1[i])(12, 'a', 'b') << std::endl;  // "correct" way of calling
		}

		if (funcArr2[i] != nullptr) {
			std::cout << (*funcArr2[0])(12, 'a', 'b') << std::endl;
		}
	}
}

void Array_of_Member_Function_Pointers()
{
	std::cout << "Executing 'Array_of_Member_Function_Pointers'" << std::endl;

	/* ptr2Member can now be used as type */
	typedef int(MyClass::*ptr2Member)(double, char, char);

	ptr2Member funcArr1[10] = {nullptr};

	/* 2nd way directly defining the array of member function pointers */
	int (MyClass::*funcArr2[10])(double, char, char) const = {nullptr};

	funcArr1[0] = &MyClass::DoIt;
	funcArr2[0] = &MyClass::DoMore;

	MyClass instance;
	std::cout << (instance.*funcArr1[0])(12, 'a', 'b') << std::endl;
	std::cout << (instance.*funcArr2[0])(12, 'a', 'b') << std::endl;
}

/* ------------------------------------------------------------------------------------- */


int main()
{
	Replace_a_Switch();

	int (*functionPtr)(double, char, char) = &DoIt;
	std::cout << functionPtr(5, 1, 2) << std::endl;

	int (MyClass::*ptr2Member)     (double, char, char) = &MyClass::DoIt;
	int (MyClass::*ptr2ConstMember)(double, char, char) const = &MyClass::DoMore;

	if (functionPtr == &DoIt)
		std::cout << "functionPtr points to DoIt()" << std::endl;

	if (ptr2Member == &MyClass::DoIt)
		std::cout << "ptr2Member points to MyClass::DoIt() member function" << std::endl;
	
	if (ptr2ConstMember == &MyClass::DoMore)
		std::cout << "ptr2ConstMember points to MyClass::DoMore() member function" << std::endl;

	MyClass instance1;
	int result1 __attribute__((unused)) = (instance1.*ptr2Member)(12, 'a', 'b');

	MyClass* instance2 = new MyClass;
	int result3 __attribute__((unused)) = (instance2->*ptr2Member)(12, 'a', 'b');
	delete instance2;

	/* test return function pointer */
	Return_A_Function_Pointer();
	
	/* test array of function pointers */
	Array_of_Function_Pointers();
	
	/* test array of member function pointers */
	Array_of_Member_Function_Pointers();

	return 0;
}
