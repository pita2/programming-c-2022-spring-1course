#include "LinkedList.hpp"

std::ostream& operator<<(std::ostream& stream, const Node& node)
{
    stream << node.data;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
    stream << "[" << list.count << "] : { ";
    Node* temp = list.head;
    while (temp != nullptr)
    {
        stream << *temp << " ";
        //stream << temp->data << " ";
        temp = temp->next;
    }
    stream << "}";
    return stream;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        popHead();
    }
}

void LinkedList::pushHead(int element)
{
    /*
    Node* newhead = new Node();
    newhead->data = element;
    newhead->next = this->head;
    head = newhead;
    if (tail == nullptr)
    {
        tail = head;
    }
    ++count;*/
    head = new Node(element, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    ++count;
}

void LinkedList::pushTail(int element)
{
    if (tail == nullptr)
    {
        return pushHead(element);
    }
    tail->next = new Node(element);
    tail = tail->next;
    ++count;
}

void LinkedList::insert(int element, int index)
{
    if (index == 0)
    {
        return pushHead(element);
    }
    if (index == count)
    {
        return pushTail(element);
    }
    
    int k = 0;
    Node* temp = head;
    while(k < index - 1)
    {
        temp = temp->next;
        ++k;
    }
    temp->next = new Node(element, temp->next);
    ++count;
}

int LinkedList::extract(int index)
{
    if (index == 0)
    {
        return popHead();
    }
    if (index == count)
    {
        return popTail();
    }

    int k = 0;
    Node* temp = head;
    while(k < index - 1)
    {
        temp = temp->next;
        ++k;
    }
    Node* extr = temp->next;
    int value = extr->data;
    temp->next = extr->next;
    delete extr;
    --count;
    return value;
}

void LinkedList::swap(int ind1, int ind2)
{
    Node* temp1 = this->head;
    for (int i = 0; i < ind1; ++i)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = this->head;
    for (int i = 0; i < ind2; ++i)
    {
        temp2 = temp2->next;
    }
    
    int t = temp1->data;
    temp1->data = temp2->data;
    temp2->data = t;
}

int LinkedList::popHead()
{
    if (head == nullptr)
    {
        return 0;
    }
    --count;
    Node* temp = head;
    int value = head->data;
    head = head->next;
    delete temp;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    return value;
}

int LinkedList::popTail()
{
    if (tail == nullptr)
    {
        return 0;
    }
    if (head == tail)
    {
        return popHead();
    }
    Node* temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    --count;
    int value = tail->data;
    delete tail;
    tail = temp;
    tail->next = nullptr;
    return value;
    
    
}
