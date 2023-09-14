#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i < j && v[i] == v[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}