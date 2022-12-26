#pragma once

#include <iostream>

using namespace std;

template <class Key, class Value> class Map {
  private:
	size_t size;
	size_t top;

	struct entry {
		Key key;
		Value value;
		entry(Key inKey, Value inValue)
		{
			key = inKey;
			value = inValue;
		}
	};

	entry* array;

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
    Map() {
        this -> data = new entry[2];
        this -> size = 2;
        this -> top = 0;
        };
        
    Map(consst Map& m){
        this -> size = m.size;
        this -> top = m.top;
        delete this -> data;
        this -> data = new entry[this -> size];
        copy(m.data, m.data + m.top + 1, this -> data);
        };
        
        ~Map() {
            delete[] this -> data;
            }
};
