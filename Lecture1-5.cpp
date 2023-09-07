#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v;
    for(int i = 0; i < 5; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
    cout << v[0] + v[v.size() - 1];
    return 0;
}