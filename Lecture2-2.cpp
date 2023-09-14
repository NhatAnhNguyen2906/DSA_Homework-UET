#include <iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};
class linkedList
{
    private:
        node* head;
    public:
        linkedList()
        {
            head = nullptr;
        }
        void insert_node(int position, int data);
        void delete_node(int position);
        void duyet();
};
void linkedList::insert_node(int position, int data)
{
    if(position < 0)
    {
        return ;
    }
    else
    {
        node* newNode = new node(data);
        if(position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node* tmp = head;
            for(int i = 0; i < position - 1 && tmp != nullptr; i++)
            {
                tmp = tmp->next;
            }
            if(tmp == nullptr) return;
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
}
void linkedList::delete_node(int position)
{
    if(position < 0)
    {
        return;
    }
    node* tmp = head;
    if(position == 0)
    {
        if(head != nullptr)
        {
            head = head->next;
            delete tmp;
        }
    }
    else
    {
        for(int i = 0; i < position - 1; i++)
        {
            if(tmp == nullptr || tmp->next == NULL)
            {
                return;
            }
            tmp = tmp->next;
        }
        node *deleteNode = tmp->next;
        tmp->next = deleteNode->next;
        delete deleteNode;
    }
}
void linkedList::duyet()
{
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    linkedList myList;
    int n; cin >> n;
    while(n--)
    {
        string command;
        int position;
        int data;
        cin >> command >> position >> data;
        if(command == "insert")
        {
            myList.insert_node(position, data);
        }
        if(command == "delete")
        {
            myList.delete_node(position);
        }
    }
    myList.duyet();
    return 0;
}