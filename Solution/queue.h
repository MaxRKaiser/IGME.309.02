#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class Queue
{
public:
	Queue(int size);

	Queue(T* orData, int size);

	Queue<T>& operator=(const Queue<T>& obj);

	~Queue();

	//globals
	T* data;
	T* data2;
	int length;
	int length2;

	void Push(T data);

	void Pop();

	void Print();

	int GetSize();

	bool IsEmpty();
};

//default constructor
template <class T>
Queue<T>::Queue(int size)
{
	cout << "Queue created" << endl;
	data = new T[size];
	length = size;

	//fill the whole thing with nulls
	for (int i = 0; i < size; i++)
	{
		T value = NULL;
		data[i] = value;
	}
}

//Copy Constructor
template <class T>
Queue<T>::Queue(T* orData, int size)
{
	cout << "copy queue created" << endl;
	//create backup parameters
	data2 = new T[size];
	length2 = size;

	for (int i = 0; i < length2; i++)
	{
		//copy over the origin data to the new array
		if (i <= size)
		{
			T value = orData[i];
			data2[i] = value;
		}
		//fill the remaining space with nulls
		else
		{
			T value2 = NULL;
			data2[i] = value2;
		}
	}
	//replace origin data with new array
	this->data = data2;
	this->length = length2;
}

//Copy Assignment Operator
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj)
{
	/*data = obj.data;
	length = obj.length;
	return *this;*/

	cout << "copy assignment queue created" << endl;
	//create backup parameters
	data2 = new T[obj.length];
	length2 = obj.length;

	for (int i = 0; i < length2; i++)
	{
		//copy over the origin data to the new array
		if (i <= obj.length)
		{
			T value = obj.data[i];
			data2[i] = value;
		}
		//fill the remaining space with nulls
		else
		{
			T value2 = NULL;
			data2[i] = value2;
		}
	}

	delete[] this->data;

	//replace origin data with new array
	this->data = data2;
	this->length = length2;

	return *this;
}


//Push new data to the queue, expand queue if you run out of room
template <class T>
void Queue<T>::Push(T stuff)
{
	for (int i = 0; i < length; i++)
	{
		//when you find a null, push the data there
		if (this->data[i] == NULL)
		{
			this->data[i] = stuff;
			break;
		}
		//if queue size allocated is exceeded, make a bigger list and copy over data (similar to copy constructor)
		else if (i == length - 1)
		{
			cout << "Queue size extended" << endl;
			data2 = new T[length * 2];
			length2 = length * 2;

			for (int i = 0; i < length2; i++)
			{
				if (i <= length)
				{
					T value = data[i];
					data2[i] = value;
				}
				else
				{
					T value2 = NULL;
					data2[i] = value2;
				}
			}
			this->data = data2;
			this->length = length2;
			this->data[length / 2] = stuff;
			break;
		}
	}
}


//Remove the top element of the queue
template <class T>
void Queue<T>::Pop()
{
	cout << "Data Popped!" << endl;
	data2 = new T[length];

	//make a new list, but leave out the first element of the origin when copying over
	for (int i = 0; i < length; i++)
	{
		T value = data[i + 1];
		data2[i] = value;
	}
	//Set the now empty value to null
	data2[length - 1] = NULL;
	//set origin data to new list
	this->data = data2;
}

//Print the data
template <class T>
void Queue<T>::Print()
{
	for (int i = 0; i < length; i++)
	{
		T value = data[i];
		cout << i << ":" << value << endl;
	}
}

//Gets number of entries in the queue
template <class T>
int Queue<T>::GetSize()
{
	int entries = 0;
	for (int i = 0; i < length; i++)
	{
		T value = data[i];
		if (value != NULL)
		{
			entries++;
		}
	}
	return entries;
}

//Returns true if all values are null, false otherwise
template <class T>
bool Queue<T>::IsEmpty()
{
	bool empty = true;
	for (int i = 0; i < length; i++)
	{
		T value = data[i];
		if (value != NULL)
		{
			empty = false;
		}
	}
	return empty;
}

//Destructor, delete data
template <class T>
Queue<T>::~Queue()
{
	delete[] data;
}
