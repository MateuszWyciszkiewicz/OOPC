#pragma once

#include <iostream>

using namespace std;

class KeyDoesNotExistException {};
class KeyAlreadyExistsException {};
template <class Key, class Value> class Map {
  private:
	size_t size;
	size_t top;

	struct entry {
		Key key;
		Value value;
        entry(){};
		entry(Key inKey, Value inValue)
		{
			key = inKey;
			value = inValue;
		}
	};

	entry* data;

	bool isFull()
	{
		return top >= this->size - 2;
	}

	void resize()
	{
		Map::entry* newMap = new entry[2 * this->size];
		copy(this->data, this->data + this->size, newMap);
		swap(newMap, data);
		delete[] newMap;
		this->size = this->size * 2;
	}

  public:
	Map()
	{
		this->data = new entry[2];
		this->size = 2;
		this->top = 0;
	};

	Map(const Map& m)
	{
		this->size = m.size;
		this->top = m.top;
		this->data = new entry[this->size];
		copy(m.data, m.data + m.top + 1, this->data);
	};

	~Map()
	{
		delete[] this->data;
	}

	Map& operator=(const Map& m)
	{
		if (this == &m) {
			return *this;
		}
		if (m.top + 1 > this->size) {
			this->size = m.size;
			delete[] this->data;
			this->data = new entry[this->size];
		}
		this->top = m.top;
		copy(m.data, m.data + m.top + 1, this->data);
		return *this;
	}

	Value* find(Key key)
	{
		for (int i = 0; i < (int)this->top; i++) {
			if (this->data[i].key == key) {
				return &this->data[i].value;
			}
		}
		throw KeyDoesNotExistException();
	}

	void add(Key key, Value val)
	{
		if (isFull()) {
			resize();
		}
		if (top == 0) {
			this->data[0].key = key;
			this->data[0].value = val;
		}
		else {
			for (int i = 0; i <= (int)this->top; i++) {
				if (this->data[i].key > key || i == (int)top) {
					copy(this->data + i, this->data + this->top + 1,
						 this->data + i + 1);
					this->data[i].key = key;
					this->data[i].value = val;
					break;
				}
				else if (this->data[i].key == key) {
					throw KeyAlreadyExistsException();
				}
			}
		}
		this->top++;
	}
    
    friend ostream& operator << (ostream& out, const Map& m){
        for(int i = 0; i < (int) m.top; i++){
            out << i+1;
            out << ". ";
            out << m.data[i].key;
            out << " ";
            out << m.data[i].value;
            out << endl;
            }
            return out;
        }
};
