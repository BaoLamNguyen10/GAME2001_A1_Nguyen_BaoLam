#pragma once
#include <cassert>

template <class T>
class OrderArray
{
public:
	//Constructor 
	OrderArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numofElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	//Destructor
	~OrderArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	//Insertion
	void push(T val)
	{
		assert(m_array != nullptr);
		if (m_numofElements >= m_maxSize)
		{
			Expand()
		}

		int i, k;
		for (i = 0; i < m_numofElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		for (k = m_numofElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}
	}

	//Deletion
	void pop()
	{
		if (m_numofElements > 0)
		{
			m_numofElements--;
		}

	}
	void remove(int index)
	{
		assert(m_array != nullptr);
		if (index >= m_numofElements)
		{

			return;
		}

		for (int i = index; i < m_numofElements; i++)
		{
			if (i + 1 < m_numofElements)
			{

				m_array[i] = m_array[i + 1];
			}
		}
		m_numofElements--;
	}
	//Searching
	//Binary Search
	int search(T val)
	{
		assert(m_array != nullptr);

		int lowerBound = 0;
		int upperBound = m_numofElements - 1;
		int current = 0;

		while (1) {
			current = (lowerBound + upperBound) >> 1;

			if (m_array[current] == searchKey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}
		return -1;
	}
	//Overloaded 
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numofElements);
		return m_array[index];
	}
	//Clear
	void clear()
	{
		m_numofElements = 0;
	}
	int GetSize()
	{
		return m_numofElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	//Expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}
		//Create new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		//Delete old array
		delete[] m_array;

		//Clean up
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;

	}
private:

	T* m_array;

	int m_maxSize;
	int m_growSize;
	int m_numofElements;


};
