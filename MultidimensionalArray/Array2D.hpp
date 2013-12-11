#ifndef ARRAY2D_H_DEFINED
#define ARRAY2D_H_DEFINED

#include <vector>
#include <iostream> // size_t

/// Two-dimensional array.
///
/// This class tries to be as simple as C's matrix handling
/// and very extensible, with `std::vector`.
///
/// ## Note
///
/// Array's contents must be a type/class that has a
/// constructor with no arguments.
///
/// So if you create your `MyClass` and want a 2D array of it,
/// make sure `MyClass()` has a constructor that receive no
/// arguments.
///
template<class T> class Array2D
{
public:
	/// Creates a 2D array with `width` and `height`.
	Array2D(int width, int height);

	/// Returns element at `x` `y`.
	T& at(int x, int y)
	{
		return contents[x][y];
	}

	/// Width size of the array.
	size_t width();

	/// Height size of the array.
	size_t height();

private:
	/// Internal storage of elements.
	std::vector<std::vector<T> > contents;
};

#endif //ARRAY2D_H_DEFINED

