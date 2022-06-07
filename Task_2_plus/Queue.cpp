#include "Queue.h"
QueueArr::QueueArr(int qsize) : size(qsize), head(0), tail(0), data(new double[qsize])
{
}
QueueArr::QueueArr(const QueueArr& anotherq) : size(anotherq.size), head(anotherq.head), tail(anotherq.tail)
{
    for (int i = 0; i < anotherq.size; i++) {
        data[i] = anotherq.data[i];
    }
}
QueueArr::~QueueArr()
{
    clear();
    delete[] data;
}
void QueueArr::put(double value)
{
    if (tail != size)
    {
        data[tail] = value;
        tail = tail + 1;
    }
    else {
        throw std::exception("Queue is full");
    }
}
double QueueArr::take()
{
    if (isEmpty())
    {
        throw std::exception("Queue is Empty");
    }
    double value = data[head];
    head = head + 1;
    return value;
}
double QueueArr::check() const
{
    if (!isEmpty())
    {
        return data[head];
    }
    throw std::exception("Queue is Empty");
}
int QueueArr::getSize() const
{
    return size;
}
void QueueArr::clear()
{
    head = 0;
    tail = 0;
}
bool QueueArr::isEmpty() const
{
    return head == tail;
}



QueueArr::Iterator::Iterator(const QueueArr& queue) : queue(queue)
{

}
bool QueueArr::Iterator::finish() const
{
    return current == queue.data + queue.head + queue.tail;
}
void QueueArr::Iterator::next()
{
    current = current + 1;
}
void QueueArr::Iterator::start()
{
    current = queue.data + queue.head;
}
double QueueArr::Iterator::getValue() const
{
    return *current;
}
