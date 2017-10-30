// asterixTriangles.cpp
// Program prints right triangles in 4 different roatation positions.
#include <iostream>
using std::cout;
using std::cin;

void triangles(int dimension); // function prototype

int main()
{
	int triangleDimension;
	
	cout << "Right triangle height: ";
	cin >> triangleDimension;

	// Print first pattern
	// e.g.
	// *
	// **
	// ***
	// ****
	for (int i=0; i < triangleDimension; ++i) {
		for (int j=0; j <= i; ++j) {
			cout << "*";
		}
		cout << "\n"; // new line
	}
	
	cout << "\n"; // new line
	// Print next pattern
	// e.g.
	// *****
	// ****
	// ***
	// **
	// *
	for (int i=triangleDimension; i > 0; --i) {
		for (int j=i; j > 0; --j) {
			cout << "*";
		}
		cout << "\n";
	}
	
	cout << "\n"; // new line
	// Print next pattern
	// e.g.
	// *****
	//  ****
	//   ***
	//    **
	//     *
	for (int i=triangleDimension; i > 0; --i) {
		// Print spaces
		for (int k=0; k < (triangleDimension - i); ++k) {
			cout << " ";
		}

		// Print asterix
		for (int j=i; j > 0; --j) {
			cout << "*";
		}

		cout << "\n"; // print new line
	}
	
	// Separate triangles with new line
	cout << "\n";
	// Print next patern
	// e.g.
	//     *
	//    **
	//   ***
	//  ****
	// *****
	for (int i=1; i <= triangleDimension; ++i) {
		// Print spaces
		for (int k=triangleDimension; k > i; --k) {
			cout << " ";
		}

		// Print asterixes
		for (int j=1; j <= i; ++j) {
			cout << "*";
		}

		cout << "\n"; // print new line
	}
	
	cout << "\n\n";
	
	triangles( triangleDimension );
	triangles( triangleDimension );

	return 0;	
} // end main function

// Display triangles side by side
void triangles(int dimension)
{
	for (int i = 1; i <= dimension; ++i)
	{
		int j;
		// First triangle
		for (j = 1; j <= i; ++j) {
			cout << "*";
		}
		// Spaces from first to second triangle
		for (j = dimension; j > i; --j) {
			cout << " "; // print space
		}

		// Second triangle
		for (j = dimension; j >= i; --j) {
			cout << "*";
		}
		// Spaces from second to third triangle
		// Number of spaces between second and third
		// triangle is 2*(i - 1) i.e. 0, 2, 4, etc.
		for (j = 1; j < (2*i-1); ++j) {
			cout << " "; // print space
		}

		// Third triangle
		for (j = dimension; j >= i; --j) {
			cout << "*";
		}

		// Spaces between third and fourth triangle
		for (j = dimension; j > i; --j) {
			cout << " ";
		}
		// Fourth asterix triangle
		for (j = 1; j <= i; ++j) {
			cout << "*";
		}
		
		// Form triangles
		cout << "\n"; // new line
	}// end for loop
}// end triangles





