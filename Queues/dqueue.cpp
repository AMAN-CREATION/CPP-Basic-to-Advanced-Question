#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return 0; // if full then false
        if (isEmpty())
        { // if empty then front=rear=0 so that we can insert data now
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        { // making it circular
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return 0;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        { // making it circular
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return 0;
        int res = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
            front++;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return 0;
        int res = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    MyCircularDeque q(10);

    q.insertFront(2);
    q.insertFront(15);
    q.insertFront(3);
    q.insertLast(10);

    cout << q.deleteFront();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}