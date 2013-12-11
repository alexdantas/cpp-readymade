#include "Array2D.hpp"

template <class T>
Array2D<T>::Array2D(int width, int height)
{
	contents.resize(width);

	for (int i = 0; i < width; i++)
		contents[i].resize(height);
}

template <class T>
size_t Array2D<T>::width()
{
	return contents.size();
}

template <class T>
size_t Array2D<T>::height()
{
	return contents[0].size();
}


// No need to call this temporary function.
// It was made just to avoid linker problems.
//
// Source:
// http://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
void tmpFunction()
{
	Array2D<int> tmpObject(1, 1);
}

