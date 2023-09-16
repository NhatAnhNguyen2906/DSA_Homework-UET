#include <iostream>
#include <vector>
using namespace std;

class stack
{
private:
    vector<int> data;

public:
    bool empty_()
    {
        return data.empty();
    }

    void push(int x)
    {
        data.push_back(x);
    }

    void pop()
    {
        if (!empty_()) 
        {
            data.pop_back();
        }
    }

    void duyet()
    {
        for (int x : data)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    stack myStack;
    while (n--)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int x;
            cin >> x;
            myStack.push(x);
        }
        else if (command == "pop")
        {
            myStack.pop();
        }
    }
    myStack.duyet();
    return 0;
}
