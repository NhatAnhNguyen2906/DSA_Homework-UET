#include <iostream>
#include <vector>
using namespace std;

class queue
{
private:
    vector<int> data;

public:
    bool empty_()
    {
        return data.empty();
    }
    void enqueue(int x)
    {
        data.push_back(x);
    }
    void dequeue()
    {
        if (empty_()) return;
        data.erase(data.begin()); 
    }
    void duyet()
    {
        for (int x : data)
        {
            cout << x << ' ';
        }
    }
};

int main()
{
    int n;
    cin >> n;
    queue myQueue;
    while (n--)
    {
        string command;
        cin >> command; // You were missing this line to read the command.

        if (command == "enqueue")
        {
            int x;
            cin >> x;
            myQueue.enqueue(x);
        }
        else if (command == "dequeue") 
        {
            myQueue.dequeue();
        }
    }
    myQueue.duyet();
    return 0;
}
