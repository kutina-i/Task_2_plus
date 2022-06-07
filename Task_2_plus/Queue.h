#pragma once
#include <iostream>
class QueueArr
{
private:
    int head = 0;
    int tail = 0;
    int size;
    double* data;
public:
    QueueArr(int qsize);
    QueueArr(const QueueArr& anotherq);
    ~QueueArr();

    void put(double value);
    double take();
    double check() const;
    int getSize() const;
    void clear();
    bool isEmpty() const;


    class Iterator
    {
    private:
        const QueueArr& queue;
        const double* current;
    public:
        Iterator(const QueueArr& queue);
        void start();
        void next();
        bool finish() const;
        double getValue() const;
    };
};