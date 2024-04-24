#include<iostream>

class ArrayList {

	int _capacity;
	int _size;
	int* _data;
	int _err;

	bool indexValid(int index)
	{
		return (0 <= index && index < _size);
	}
	void expand(int add = 0)
	{
		add = (add == 0 ? _capacity : add);
		int* newdata = new int[_capacity + add] { 0 };
		for (int i = 0; i < _size; newdata[i] = _data[i++]);
		delete[] _data;
		_data = newdata;
		_capacity += add;
	}


public:

	ArrayList(int capacity = 1) : _capacity(capacity), _size(0), _data(new int[capacity] { 0 }), _err(0) {}

	ArrayList(const ArrayList& src) : _capacity(src._size), _size(src._size), _data(new int[_size] { 0 }), _err(0)
	{
		for (int i = 0; i < _size; _data[i] = src._data[i++]);
	}

	~ArrayList()
	{
		delete[] _data;
	}

	void print(std::ostream& stream)
	{
		stream << "[" << _size << "/" << _capacity << "] : ";
		for (int i = 0; i < _size; ++i)
		{
			stream << _data[i] << " ";
		}
		stream << std::endl;
	}
	void push_back(int el)
	{
		while (_size >= _capacity)
		{
			expand();
		}
		_data[_size++] = el;
	}

	int size() {
		return _size;
	}

	void setSize(int newSize)
	{
		if (indexValid(newSize))
		{
			_size = newSize;
		}
		else if (_size <= newSize && newSize < _capacity)
		{
			_size = newSize;
		}
		else
		{
			expand(newSize - _capacity + 1);
			_size = newSize;
		}
	}

	void set(int index, int val)
	{
		if (indexValid(index))
		{
			_data[index] = val;
		}
		else if (index == _size)
		{
			push_back(val);
		}
	}

	int& cell(int index)
	{
		if (indexValid(index))
		{
			return _data[index];
		}
		else if (index == _size)
		{
			push_back(0);
			return _data[index];
		}
		else
		{
			return _err;
		}
	}

	int& operator[](int index)
	{
		if (indexValid(index))
		{
			return _data[index];
		}
		else if (index == _size)
		{
			push_back(0);
			return _data[index];
		}
		else
		{
			return _err;
		}
	}

	ArrayList& operator+=(int el)
	{
		push_back(el);
		return *this;
	}

	ArrayList& operator=(const ArrayList& src)
	{
		delete[] _data;
		_size = src._size;
		_capacity = src._capacity;
		_data = new int[_capacity];
		for (int i = 0; i < _size; _data[i] = src._data[i++]);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);
	ArrayList& push_forward(int el)
	{
		if (_size == 0)
		{
			push_back(el);
		}
		else
		{
			expand();
			for (int i = _size; i > 0; --i)
			{
				_data[i] = _data[i - 1];
			}
			_data[0] = el;
			_size++;
		}
		return *this;
	}
	ArrayList& insert(int index, int element)
	{
		if (indexValid(index))
		{
			if (index == _size)
			{
				push_back(element);
			}
			else
			{
				expand();
				for (int i = _size; i > index; --i)
				{
					_data[i] = _data[i - 1];
				}
				_data[index] = element;
				_size++;
			}
		}
		return *this;
	}

	int extract_forward()
	{
		if (_size == 0)
		{
			return _err;
		}
		else
		{
			int extracted = _data[0];
			for (int i = 0; i < _size - 1; ++i)
			{
				_data[i] = _data[i + 1];
			}
			--_size;
			return extracted;
		}
	}

	int extract_back()
	{
		if (_size == 0)
		{
			return _err;
		}
		else
		{
			--_size;
			return _data[_size];
		}
	}

	int extract(int index)
	{
		if (indexValid(index))
		{
			if (index == _size - 1)
			{
				return extract_back();
			}
			else
			{
				int extracted = _data[index];
				for (int i = index; i < _size - 1; ++i)
				{
					_data[i] = _data[i + 1];
				}
				--_size;
				return extracted;
			}
		}
		return _err;
	}

	ArrayList& remove_forward()
	{
		extract_forward();
		return *this;
	}

	ArrayList& remove_back()
	{
		extract_back();
		return *this;
	}

	ArrayList& remove(int index)
	{
		extract(index);
		return *this;
	}

	void clear()
	{
		_size = 0;
	}

	int len()
	{
		return _size;
	}
};

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
	stream << "[" << list.size() << "/" << list._capacity << "] : ";
	for (int i = 0; i < list.size(); ++i)
	{
		stream << list[i] << " ";
	}
	return stream;
}
int main(int argc, char* argv[])
{
	ArrayList list;
	list += 1;
	list += 2;
	list += 3;
	std::cout << "Original List: " << list << std::endl;

	list.push_forward(0);
	std::cout << "List after push_forward: " << list << std::endl;

	list.insert(2, 10);
	std::cout << "List after insert: " << list << std::endl;

	std::cout << "Extracted element from front: " << list.extract_forward() << std::endl;
	std::cout << "List after extract_forward: " << list << std::endl;

	std::cout << "Extracted element from back: " << list.extract_back() << std::endl;
	std::cout << "List after extract_back: " << list << std::endl;

	list.remove(1);
	std::cout << "List after remove: " << list << std::endl;

	list.clear();
	std::cout << "List after clear: " << list << std::endl;

	list += 4;
	list += 5;
	list += 6;
	std::cout << "List after adding elements: " << list << std::endl;

	std::cout << "Length of the list: " << list.len() << std::endl;

	ArrayList list2;
	list2 += 7;
	list2 += 8;
	list2 += 9;

	std::cout << "List 2: " << list2 << std::endl;

	list2 = list;
	std::cout << "List 2 after assignment: " << list2 << std::endl;

	list2[1] = 100;
	std::cout << "List 2 after modifying element: " << list2 << std::endl;

	std::cout << "List 2[1]: " << list2[1] << std::endl;

	std::cout << "List 2 using operator<<: " << list2 << std::endl;
	return EXIT_SUCCESS;
}