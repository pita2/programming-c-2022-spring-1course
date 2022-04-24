#include <iostream>
#include "ArrayList.hpp"

void ArrayList::expand(int count)
{
    int* newdata = new int[count + this->capacity];
    for (int i = 0; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
    this->capacity += count;
}

int ArrayList::ind(int index)
{
    if (index < 0)
    {
        pushbegin(0);
        return 0;
    }
    if (index >= this->count)
    {
        pushend(0);
        return this->count - 1;
    }
    return index;
}

void ArrayList::swap(int posi, int posj)
{
    int t = this->data[posi];
    this->data[posi] = this->data[posj];
    this->data[posj] = t;
}

int ArrayList::size()
{
    return this->count;
}

ArrayList::ArrayList(int capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& list)
{
    this->capacity = list.count;
    this->count = list.count;
    this->data = new int[list.count];
    for (int i = 0; i < list.count; ++i)
    {
        this->data[i] = list.data[i];
    }
}

ArrayList::~ArrayList()
{
    this->count = 0;
    this->capacity = 0;
    for (int i = 0; i < this->capacity; ++i)
    {
        this->data[i] = 0;
    }
    delete[] this->data;
}

void ArrayList::pushend(int element)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->data[this->count] = element;
    this->count++;
}

void ArrayList::pushbegin(int element)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->count++;
    for (int i = this->count; i > 0; --i)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[0] = element;
}

void ArrayList::insert(int element, int position)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->count++;
    
    for (int i = this->count; i > position; --i)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[position] = element;
}

int ArrayList::extract(int position)
{
    int elem = this->data[position];
    this->count--;
    for (int i = position; i < this->count; ++i)
    {
        this->data[i] = this->data[i + 1];
    }
    return elem;
}

int ArrayList::extractbegin()
{
    int elem = this->data[0];
    this->count--;
    for (int i = 0; i < this->count; ++i)
    {
        this->data[i] = this->data[i + 1];
    }
    return elem;
}

int ArrayList::extractend()
{
    this->count--;
    return this->data[this->count];
}

int& ArrayList::operator[](int pos)
{
    return data[ind(pos)];
}

void ArrayList::qsort (int begin, int end)
{
    int l = begin, r = end;
    int p = data[(l + r) / 2];
    while (l <= r)
    {
        while (data[l] < p)
        {
            l++;
        }
        while (data[r] > p)
        {
            r--;
        }
        if (l <= r)
        {
            int t = data[l];
            data[l] = data[r];
            data[r] = t;
            l++;
            r--;
        }
    }
    if (begin < r)
    {
        qsort (begin, r);
    }
    if (end > l)
    {
        qsort (l, end);
    }
}

void ArrayList::sort()
{
    ArrayList sorted(*this);
    sorted.qsort(0, sorted.size() - 1);
    for (int i = 0; i < sorted.size(); ++i)
    {
        this->data[i] = sorted[i];
        
    }
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
    stream << "[" << list.count << "/" << list.capacity << "] {";
    if (list.count == 0)
    {
        stream << "EMPTY";
    }
    else
    {
        for (int i = 0; i < list.count - 1; ++i)
        {
            stream << list.data[i] << ", ";
        }
        stream << list.data[list.count - 1];
    }
    stream << "}";
    return stream;
}
