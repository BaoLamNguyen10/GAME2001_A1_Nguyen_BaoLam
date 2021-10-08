#pragma once
#include <cassert>

template <class T>
class UnorderArray
{
public:
	//Constructor 
	UnorderArray(int size, int growBy = 1) :
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
	~UnorderArray()
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
			Expand();
		}

		m_array[m_numofElements] = val;
		m_numofElements++;
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
	int search(T val)
	{
		assert(m_array != nullptr);

		for (int i = 0; i < m_numofElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
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