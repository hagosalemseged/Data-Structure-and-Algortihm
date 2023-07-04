#include <iostream>
#define MAX 10
using namespace std;

class Stack
{
private:
    int top;
    int a[MAX];

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int val);
    int pop();
};

Stack::Stack()
{
    top = -1;
}
bool Stack::isEmpty()
{
    if (top <= -1)
        return false;
    return true;
}
bool Stack::isFull()
{
    if (top >= MAX - 1)
        return false;
    return true;
}
void Stack::push(int val)
{
    if (!isFull())
    {
        a[++top] = val;
    }
    else
    {
        cout << "Stack is Overflow\n";
    }
}
int Stack::pop()
{
    if (!isEmpty())
    {
        return a[top--];
    }
}

int main(int argc, char **argv)
{
    Stack s1;
    int num[100];
    int n;
    cout << "Enter how many elements to insert->";
    cin >> n;
    cout << "Push elements->";
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        s1.push(num[i]);
    }
    cout << "Displaying the pushed elements->\n";
    for (int i = 0; i < n; i++)
    {
        cout << s1.pop() << " ";
    }
    return 0;
}