#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

class LinkedList
{
private:
    node *list;

public:
    LinkedList();
    bool isEmpty();
    void Create(int val);
    void insert_beg(int val);
    void insert_end(int val);
    int delete_beg();
    int delete_end();
    void Traverse();
};
// Defining Constructor
LinkedList::LinkedList()
{
    list = NULL;
}
// check for empty
bool LinkedList::isEmpty()
{
    if (list == NULL)
    {
        return true;
        return false;
    }
}
// create a first node
void LinkedList::Create(int val)
{
    node *p;
    p = new node;
    p->info = val;
    p->next = NULL;
    list = p;
}
// insert at begining
void LinkedList::insert_beg(int val)
{
    if (!isEmpty())
    {
        node *p;
        p = new node;
        p->info = val;
        p->next = list;
        list = p;
    }
    else
    {
        Create(val);
    }
}
// insert at end
void LinkedList::insert_end(int val)
{
    if (!isEmpty())
    {
        node *p;
        p = new node;
        p->info = val;
        p->next = NULL;
        node *q = list;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    else
    {
        Create(val);
    }
}
// delete from begining
int LinkedList::delete_beg()
{
    int val = -1;
    if (!isEmpty())
    {
        node *q = list;
        list = list->next;
        val = q->info;
        delete q;
    }
    return val;
}
// delete form end
int LinkedList::delete_end()
{
    int val = -1;
    if (!isEmpty())
    {
        if (list->next != NULL)
        {
            delete_beg();
        }
        else
        {
            node *q = list;
            while (q->next != NULL)
            {
                q = q->next;
            }
            node *p = q->next;
            q->next = NULL;
            val = p->info;
            delete p;
        }
    }
    return val;
}
// Traverse a list of item
void LinkedList::Traverse()
{
    if (!isEmpty())
    {
        node *q = list;
        while (q != NULL)
        {
            std::cout << q->info << "-->";
            q = q->next;
        }
        std::cout << "NULL\n";
    }
}
class Queue : public LinkedList
{
public:
    void enqueue(int val);
    int dequeue();
    void display();
};

void Queue::enqueue(int val)
{
    insert_end(val);
}

int Queue::dequeue()
{
    return delete_beg();
}

void Queue::display()
{
    Traverse();
}

int main()
{
    LinkedList sll;
    Queue que;
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 100 + 1;
        que.enqueue(x);
    }
    while (!sll.isEmpty())
    {
        cout << que.dequeue();
    }
    que.display();
    return 0;
}