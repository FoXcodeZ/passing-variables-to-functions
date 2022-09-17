// ======================================================================
// Passing variables to functions. Simple examples.
// Created by Marcin 'FoXcodeZ' Grabowy.
// Github: https://github.com/FoXcodeZ
// License: MIT
// ======================================================================

#include <iostream>
#include <random>


void noSwap(int a, int b);
void swapByReference(int& a, int& b);
void swapByPointer(int* a, int* b);
void randomizeNumbers();

int x {};
int y {};

int main(int argc, char* argv[])
{

	std::cout << "============================================================\n";
	randomizeNumbers();
	std::cout << "Generated numbers: " << x << ", " << y << std::endl;
	std::cout << "Before noSwap() x = " << x << ", y = " << y << std::endl;
	noSwap(x, y);
	std::cout << "After noSwap() x = " << x << ", y = " << y << std::endl;

	std::cout << "============================================================\n";
	randomizeNumbers();
	std::cout << "Generated numbers: " << x << ", " << y << std::endl;
	std::cout << "Before swapByReference() x = " << x << ", y = " << y << std::endl;
	swapByReference(x, y);
	std::cout << "After swapByReference() x = " << x << ", y = " << y << std::endl;

	std::cout << "============================================================\n";
	randomizeNumbers();
	std::cout << "Generated numbers: " << x << ", " << y << std::endl;
	std::cout << "Before swapByPointer() x = " << x << ", y = " << y << std::endl;
	swapByPointer(&x, &y);
	std::cout << "After swapByPointer() x = " << x << ", y = " << y << std::endl;

	//std::cin.get();
	return 0;
}


// Parameters are ONLY COPY of original variables,
// in this function, is NOT possible to modify the original variables.
void noSwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Reference is an address of the variable, we can't change it.
// Passing arguments by reference we're literally changing x and y, without
// making a copy of those variables.
void swapByReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


// Pointer is a variable, which store an address to the another variable.
// We can change this him. We can choose address of which variable we want to store.
// While passing arguments by pointer we have to use dereference * to get
// a value which is stored in that address.
// We have saved an address of the variables, and we are changing variables
// stored in saved address (so, we changed 'x', and 'y' - 'a' and 'b' are addresses of 'x' and 'y').
void swapByPointer(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


// Here, we simply just randomized numbers from 0 to 9.
// We use while loop, until numbers will be different,
// to prevent possible same values of the variables
void randomizeNumbers()
{
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random mean between 0 and 9
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 9);
	x = uniform_dist(e1);
	y = uniform_dist(e1);

	while(x == y)
	{
		y = uniform_dist(e1);
	}
}