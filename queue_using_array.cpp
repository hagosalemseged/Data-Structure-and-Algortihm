#include <iostream>
#define MAX 20
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int Q[MAX];

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int val);
    int dequeue();
    void display();
};
// constructor
Queue::Queue()
{
    front = 0;
    rear = -1;
}
// check is empty
bool Queue::isEmpty()
{
    if (rear <= -1)
        return true;
    return false;
}
// check is full
bool Queue::isFull()
{
    if (rear >= MAX - 1)
        return true;
    return false;
}
// Enqueue or insert operation
void Queue::enqueue(int val)
{
    if (!isFull())
    {
        Q[++rear] = val;
    }
    else
    {
        std::cout << "Queus is Overflow\n";
    }
}
// Dequeue or delete operation
int Queue::dequeue()
{
    if (!isEmpty())
    {
        return Q[front++];
    }
}
// Display
void Queue::display()
{
    if (!isEmpty())
    {
        for (int i = front; i <= rear; i++)
        {
            std::cout << Q[i] << " ";
        }
    }
}

int main()
{
    Queue que;
    int opt;
    int val;
    do
    {
        std::cout << "Press 1 to Enqueue\nPress 2 to Dequeue\nPress 3 to display\nPress 4 to exit\n";
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cout << "Enter the item: ";
            std::cin >> val;
            que.enqueue(val);
            break;
        case 2:
            que.dequeue();
            break;
        case 3:
            que.display();
            break;
        case 4:
            exit(0);
            break;
        default:
            std::cout << "You Have Entered Wrong Input\n";
        }

    } while (opt != 'F');
    return 0;
}