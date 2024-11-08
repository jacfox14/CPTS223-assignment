//***************************************************************************//
//**
//**  Simple Heap implementation
//**
//***************************************************************************//

#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include <vector>
#include <stdexcept> // std::out_of_range
#include <math.h>	 // pow()
#include <string>
#include <limits>

/**
 *  Declaring Heap class
 */
template <typename T>
class Heap
{

private:
	std::vector<T> _items; // Main vector of elements for heap storage. The first item in the array is a placeholder.

	/*********************************************************************/
	/*********************** Start assignment zone **********************/

	/**
	 *  Percolates the item specified at by index down 
     *   into its proper location within a heap.
	 *  Used for dequeue operations and array to heap conversions
	 *  TODO: Implement percolateDown
	 */
	void percolateDown(unsigned int hole)
	{
		int child;
		T tmp = std::move(_items[hole]);
		int count = _items.size() - 1;  // Exclude placeholder from size
		
		// Percolate down until hole is a leaf node
		for (; hole * 2 <= count; hole = child)
		{
			child = hole * 2;  // Left child index
			
			// If right child exists and is smaller than the left child, use right child
			if (child + 1 <= count && _items[child + 1] < _items[child])
				++child;
			
			// Move the smaller child up if it's smaller than tmp
			if (_items[child] < tmp)
				_items[hole] = std::move(_items[child]);
			else
				break;
		}
		
		_items[hole] = std::move(tmp);  // Place tmp in its correct position
	}


	/**
	 *  Add a new item to the end of the heap and percolate up this item to fix heap property
	 *  Used in inserting new nodes into the heap
	 *  TODO: Implement percolateUp
	 */
	void percolateUp(T item)
	{
		// Add the new item to the end of the vector
		_items.push_back(std::move(item));

		int hole = _items.size() - 1;  // Start at the last index (new item's position)

		// Temporarily store the item for comparison as we percolate up
		T copy = _items[hole];

		// Percolate up: while the item is smaller than its parent, move the parent down
		for (; hole > 1 && copy < _items[hole / 2]; hole /= 2)
		{
			_items[hole] = std::move(_items[hole / 2]);
		}

		// Place the copied item in the correct position
		_items[hole] = std::move(copy);
	}


	/********************** End Microassigment zone *********************/

public:
	/**
	 *  Default empty constructor
	 */
	Heap()
	{
		_items.push_back(std::numeric_limits<T>::min()); // Push a placeholder for the first item in the array
	}

	/**
	 *  Adds a new item to the heap
	 */
	void push(T item)
	{
		percolateUp(item);
	}

	/**
	 *  Removes minimum value from heap 
	 */
	T pop()
	{
		long unsigned int last_index = _items.size() - 1; // Calc last item index
		int root_index = 1;								  // Root index (for readability)

		if (size() == 0)
		{
			throw std::out_of_range("pop() - No elements in heap");
		}

		T minItem = _items[root_index];

		_items[root_index] = _items[last_index]; // Move last item to root
		_items.pop_back();						 // Erase last element entry

		if (size() > 0)
		{					  // Only runs if the heap isn't empty now
			percolateDown(1); // Fix heap property
		}
		return minItem;
	}

	/**
	 *  Returns true if heap is empty, else false
	 *  Consider the first placeholder in the array
	 */
	bool empty() const
	{
		if (_items.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 *  Returns current quantity of elements in heap (N)
	 *  Consider the first placeholder in the array
	 */
	long unsigned int size() const
	{
		return _items.size() - 1;
	}

	/**
	 *  Return heap data in order from the _items vector
	 */
	std::string to_string() const
	{
		std::string ret = "";
		for (unsigned int i = 1; i < _items.size(); i++)
		{
			ret += std::to_string(_items[i]) + " ";
		}
		return ret;
	}
};

#endif
