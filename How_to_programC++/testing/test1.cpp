#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib> // qsort
#include <functional>


/* --------------------------------------------------------------------------------- */

/* function template */
template<typename T>
int cmpFunc(const void* a_a, const void* a_b)
{
	const T* a = static_cast<const T*>(a_a);
	const T* b = static_cast<const T*>(a_b);

	if      (*a > *b) return 1;
	else if (*a < *b) return -1;

	return 0;
}

void q_sort_example()
{
	const size_t size = 100;
	int* field = new int[size];

	/* initialize a trivial random engine */
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0,10000);

	for (size_t i = 0; i < size; ++i)
		field[ i ] = distribution(generator);

	int (*cmpfunc)(const void*, const void*) = &cmpFunc<int>;

	/* sort using qsort() */
	std::qsort( field,            /* list of items */
		    size,             /* number of items */
		    sizeof(field[0]), /* size of an element */
		    cmpfunc );        /* comparison function */

	std::cout << "Print first few elements of sorted field..." << std::endl;

	/* display first twenty sorted elements */
	for (size_t i = 0; i < 20; ++i)
		std::cout << field[i] << '\n';

	delete[] field;
}


/* --------------------------------------------------------------------------------- */

class ClassA
{
public:
	void Display(const char* text) { std::cout << text << std::endl; }
	static void WrapperToDisplay(void* ptrToObject, const char* text );
};

void ClassA::WrapperToDisplay(void* ptrToObject, const char* text)
{
	/* explicitly cast pointer */
	ClassA* objA = static_cast<ClassA *>(ptrToObject);

	objA->Display(text);
}

void DoIt(void* ptrToObject, void (*ptrToFunction)(void* ptrToObject, const char* txt))
{
	/* callback function */
	(*ptrToFunction)(ptrToObject, "Hi, I am calling back using a argument ;)");
}

void Callback_Using_Argument()
{
	/* instantiate class object */
	ClassA objA;

	DoIt( &objA, &ClassA::WrapperToDisplay );
}

/* --------------------------------------------------------------------------------- */

void* g_ptrToObj = nullptr;

class ClassB
{
public:
	void Display(const char* text) { std::cout << text << std::endl; }
	static void WrapperToDisplay(const char* text );
};

void ClassB::WrapperToDisplay(const char* text)
{
	/* validate initialization global pointer */
	if (g_ptrToObj == nullptr)
	{
		std::cerr << "Global object pointer is null" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	/* convert pointer to object pointer */
	ClassB* objB = static_cast<ClassB *>(g_ptrToObj);

	/* print display text */
	objB->Display(text);
}

void DoMore(void (*ptrToFunc)(const char *))
{
	if (ptrToFunc == nullptr)
	{
		std::cerr << "Global object pointer is null" << std::endl;
		std::exit( EXIT_FAILURE );
	}

	/* do something */

	(*ptrToFunc)("hi, I'm calling back using a global ;)");
}

void CallBack_Using_Global()
{
	ClassB objB;

	/* initialize global pointer */
	g_ptrToObj = static_cast<void *>(&objB);

	/* callback */
	DoMore( &ClassB::WrapperToDisplay );
}


int main()
{
	/* sort with qsort and callback function method */
	q_sort_example();

	Callback_Using_Argument();

	return 0;
}
