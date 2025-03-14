#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _len;

public:
	Array(void) : _arr(new T[0]), _len(0) {};
	Array(unsigned int n)
	{
		this->_len = n;
		this->_arr = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			this->_arr[i] = T();
		}
	}
	~Array(void)
	{
		if (this->_arr != 0)
			delete[] this->_arr;
	}
	Array(const Array &arr): _arr(0), _len(0)
	{
		*this = arr;
	}
	Array &operator=(const Array &arr)
	{
		if (this != &arr)
		{
			if (this->_arr != 0)
				delete[] this->_arr;
			this->_len = arr.size();
			this->_arr = new T[this->_len];
			if (this->_arr)
			{
				for (unsigned int i = 0; i < arr._len; i++)
				{
					this->_arr[i] = arr._arr[i];
				}
			}
		}
		return *this;
	}
	T &operator[](unsigned int i)
	{
		if (i > this->_len - 1 || i < 0)
			throw std::out_of_range("Index is out of bounds");
		return this->_arr[i];
	}
	int size(void) const
	{
		return this->_len;
	}
};
#endif