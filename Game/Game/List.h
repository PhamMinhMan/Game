#pragma once


#ifndef _LIST_H_
#define _LIST_H_

#include<vector>
#include <algorithm>
using namespace std;


template<class Type>

#define FIND auto p = std::find(this->begin(),this->end(),item);		if(p==this->end())	

class List :
	public vector<Type>
{
public:

#pragma region CONSTRUCTOR
	List(void) :
		vector<Type>()
	{
		}
	List(int maxSize) :
		vector<Type>(maxSize)
	{
		}


#pragma endregion

#pragma region METHOD

	void _Add(Type item)
	{
		if(!this->_Contain(item))
			this->push_back(item);
	}
	int _IndexOf(Type item) const
	{
		FIND
			return -1;
		return p - this->begin();
	}
	bool _Remove(Type item)
	{
		if(size()==0)
			return false;
		FIND
			return false;
		this->erase(p);
		return true;
	}
	void _Insert(Type item, int position)
	{
		this->insert(this->begin() + position, item);
	}
	Type _Pop()
	{
		Type item = *(this->end() - 1);
		this->pop_back();
		return item;
	}
	bool _Contain(Type item)
	{
		FIND
			return false;

		return true;
	}

	void _Clear()
	{
		while (this->size()>0)
		{
			_Pop();
		}
	}

	void _Release()
	{
		while (this->size()>0)
		{
			Type o = _Pop();
		}
	}

	~List(void)
	{
		_Release();
	}

#pragma endregion

};


#endif // !_LIST_H_