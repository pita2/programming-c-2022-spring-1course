#pragma once
#include<ostream>
class ArrayList
{
private:
    int* data;
    int capacity;
    int count;
    void expand(int count = 1);
    void swap(int posi, int posj);
    int ind(int index);

public:
    ArrayList(int capacity = 10);
    ArrayList(const ArrayList& list);
    ~ArrayList();
    /// <summary>
    /// длина
    /// </summary>
    int size();
    /// <summary>
    /// вставкв элемента element в конец
    /// </summary>
    void pushend(int element);
    /// <summary>
    /// вставкв элемента element в начало
    /// </summary>

    void pushbegin(int element);
    /// <summary>
    /// вставкв элемента element на position
    /// </summary>
    ///
    void insert(int element, int position);
    /// <summary>
    /// удвление первого элемента
    /// </summary>
    ///
    int extractbegin();
    /// <summary>
    /// удвление последнего элемента
    /// </summary>
    ///
    int extractend();
    
    /// <summary>
    /// удаление элемента на position
    /// </summary>
    int extract(int position);
    
    /// <summary>
    /// QuickSort
    /// </summary>
    void qsort(int begin, int end);
    void sort();
    int& operator[](int pos);
    
    friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);
};
