#pragma once

#include <stddef.h>

#ifdef DEBUG
#include <iostream>
#endif

template<typename T>
class Storage
{
private:
    T *data;
    size_t size;

public:
    Storage()
    {
        data = nullptr;
        size = 0;
#ifdef DEBUG
        std::cout << "Storage constructor called" << std::endl;
#endif
    }

    Storage(const Storage<T> &orig)
    {
        size = orig.TotalSize();
        data = new T[size];
        for (size_t k = 0; k < size; ++k)
        {
            data[k] = orig.GetElemByNum(k);
        }
    }

    Storage &operator=(const Storage<T> &orig)
    {
        size = orig.TotalSize();
        if (data != nullptr)
            delete[] data;
        data = new T[size];
        for (size_t k = 0; k < size; ++k)
        {
            data[k] = orig.GetElemByNum(k);
        }
    }

    ~Storage()
    {
        if (data != nullptr)
            delete[] data;
    }

    void AddElem(T val)
    {
        if (data == nullptr)
        {
            data = new T[1];
            data[0] = val;
            size = 1;
        }
        else
        {
            T *buf = new T[size + 1];
            for (size_t i = 0; i < size; i++)
            {
                buf[i] = data[i];
            }
            buf[size] = val;
            delete[] data;
            data = buf;
            size++;
        }
    };

    T GetElemByNum(size_t num) const
    {
        return data[num];
    };

    T &operator[](size_t num) const
    {
        if (num < size)
            return data[num];
    };

    void SetElemByNum(size_t num, T val)
    {
        if (num < size)
            data[num] = val;
    };

    size_t TotalSize() const
    {
        return size;
    };

};
/*
bool testStorage4() {
	Storage<int> storage;
	for (int k = 0; k < 4; k++) {
		storage.AddElem(k);
	}
	if (storage.TotalSize() != 4) return false;
	for (int k = 0; k < 4; k++) {
		if (storage.GetElemByNum(k) != k) {
			return false;
		}
	}
	return true;
}
*/
