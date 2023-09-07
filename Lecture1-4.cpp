#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int number;
    vector <int> v;
    cin >> number;
    for(int i = 0; i < number; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
    for(int x : v)
    {
        cout << x << " ";
    }
    return 0;
}