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
int LinkedList::delete_end(){
    int val = -1;
    if(!isEmpty()){
        if(list->next != NULL){
            delete_beg();
        }else{
            node *q = list;
            while(q->next!=NULL){
                q=q->next;
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

int main()
{
    LinkedList sll;
    int opt;
    int val;
    do
    {
        std::cout << "Press 1 to create\nPress 2 to Insert at beg\nPress 3 to insert at end\nPress 4 to Traverse\nPress 8 to exit\nPress 5 to delete from beg\nPress 6 to delete from end\n";
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cout << "Please enter item:";
            std::cin >> val;
            sll.Create(val);
            break;
        case 2:
            std::cout << "Please enter item:";
            std::cin >> val;
            sll.insert_beg(val);
            break;
        case 3:
            std::cout << "Please enter item:";
            std::cin >> val;
            sll.insert_end(val);
            break;
        case 4:
            sll.Traverse();
            break;
        case 5:
            sll.delete_beg();
            break;
        case 6:
            sll.delete_end();
            break;
        case 8:
            exit(0);
            break;
        default:
            std::cout << "You Have Entered Wrong Input\n";
        }

    } while (opt != 'F');
    return 0;
}