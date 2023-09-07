#include <iostream>
using namespace std;
void reverse(string s)
{
    int left = 0;
    int right = s.length() - 1;
    while(left <= right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    } 
    cout << s << " ";
}
int main()
{
    for(int i = 0; i < 100; i++)
    {
        string s;
        cin >> s;
        reverse(s);
    }
    return 0;
}