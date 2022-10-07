#pragma once
#include "Image.h"

typedef Image TElem;

template <typename Template>

class DynamicVector
{
private:
	int size, capacity;
	Template* elements;
public:
	//default constructor
	DynamicVector(int capacity = 100);
	//copy constructor
	DynamicVector(const DynamicVector& vector);
	//destructor
	~DynamicVector();

	const DynamicVector& operator=(const DynamicVector& vector);
	TElem& findId(const std::string id);
	int addElement(const Template& element);
	int deleteElement(const std::string id);
	int updateElement(const Template& element);

	int getSize();
	Template getElementOnPosition(int position);
	Template& operator[](int position);
private:
	void resize();

public:
	class iterator
	{
	private:
		Template* pointer;
	public:
		iterator(Template* pointer) : pointer{ pointer } {}
		Template& operator*();
		bool operator!=(const iterator& iterator);
		iterator operator++();
		iterator operator++(int);
	};
	typename iterator begin();
	typename iterator end();
};

template<typename Template>
inline DynamicVector<Template>::DynamicVector(int newCapacity) : capacity{ newCapacity }, size{ 0 }
{
	this->elements = new Template[this->capacity];
}

template<typename Template>
inline DynamicVector<Template>::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new Template[this->capacity];
	for (int i = 0; i < this->size; ++i)
		this->elements[i] = vector.elements[i];
}

template<typename Template>
inline DynamicVector<Template>::~DynamicVector()
{
	delete[] this->elements;
}

template<typename Template>
inline const DynamicVector<Template>& DynamicVector<Template>::operator=(const DynamicVector& vector)
{
	if (this == &vector)return *this;
	this->capacity = vector.capacity;
	this->size = vector.size;
	delete[] this->elements;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; ++i)
		this->elements[i] = vector.elements[i];
}

template<typename Template>
inline TElem& DynamicVector<Template>::findId(const std::string id)
{
	for (int i = 0; i < this->size; ++i)
		if (this->elements[i].getId() == id) 
			return this->elements[i];
	TElem element{ "","",0,0,"" };
	return element;
}

template<typename Template>
inline int DynamicVector<Template>::deleteElement(const std::string id)
{
	int ok = 0;
	for (int i = 0; i < this->size; ++i)
		if (this->elements[i].getId() == id)
		{
			ok = 1;
			this->elements[i] = this->elements[this->size];
			this->size--;
		}
	return ok;
}

template<typename Template>
inline int DynamicVector<Template>::getSize()
{
	return this->size;
}

template<typename Template>
inline Template DynamicVector<Template>::getElementOnPosition(int position)
{
	return this->elements[position];
}

template<typename Template>
inline Template& DynamicVector<Template>::operator[](int position)
{
	TElem element{ "","",1,1,"" };
	if (position > this->size)
		return element;
	return this->elements[position];
}

template<typename Template>
inline int DynamicVector<Template>::updateElement(const Template& element)
{
	int ok = 0;
	for (int i = 0; i < this->size; ++i)
		if (this->elements[i].getId() == element.getId())
		{
			this->elements[i] = element;
			ok = 1;
		}
	return ok;
}

template<typename Template>
inline void DynamicVector<Template>::resize()
{
	this->capacity *= 2;
	Template* moveElements = new Template[this->capacity];
	for (int i = 0; i < this->size; ++i)
		moveElements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = moveElements;
}

template<typename Template>
inline typename DynamicVector<Template>::iterator DynamicVector<Template>::begin()
{
	return iterator{ this->elements };
}

template<typename Template>
inline typename DynamicVector<Template>::iterator DynamicVector<Template>::end()
{
	return iterator{ this->elements + this->size };
}




template<typename Template>
inline int DynamicVector<Template>::addElement(const Template& element)
{
	int ok = 1;
	for (int i = 0; i < this->size; ++i)
		if (element.getId() == this->elements[i].getId())
			ok = 0;

	if (this->size == this->capacity)
		resize();
	this->elements[this->size++] = element;
	return ok;
}

template<typename Template>
inline Template& DynamicVector<Template>::iterator::operator*()
{
	return *this->pointer;
}

template<typename Template>
inline bool DynamicVector<Template>::iterator::operator!=(const iterator& iterator)
{
	return this->pointer != iterator.pointer;
}

template<typename Template>
inline typename DynamicVector<Template>::iterator  DynamicVector<Template>::iterator::operator++(int)
{
	iterator outIterator = *this;
	this->pointer++;
	return outIterator;
}

template<typename Template>
inline typename DynamicVector<Template>::iterator DynamicVector<Template>::iterator::operator++()
{
	this->pointer++;
	return *this;
}
