#include <iostream>
using namespace std;
struct point 
{
    int x,y;
};
int main()
{
    point toaDo[4];
    for(int i = 0; i < 4; i++)
    {
        cin >> toaDo[i].x >> toaDo[i].y;
    }
    for(int i = 0; i < 4; i++)
    {
        cout << toaDo[i].x << " " << toaDo[i].y << endl;
    }
}