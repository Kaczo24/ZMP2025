#include <iostream>

using namespace std;

void NWD(int a[]) {
    while(a[0] != a[1])
        if(a[0] > a[1]) a[0] -= a[1];
        else a[1] -= a[0];
}


int main()
{
    int size;
    cin >> size;
    
    int a[2];
    cin >> a[0];
    cin >> a[1];
    NWD(a);
    
    for(int n = 2; n < size; n++)
        cin >> a[1];
        NWD(a);
    
    cout << a[0];

    return 0;
}