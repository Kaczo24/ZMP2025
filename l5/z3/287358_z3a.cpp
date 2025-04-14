#include <iostream>

using namespace std;

inline int max(int n, int m) { return m < n ? n : m; }

int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
        
    int x = 0;
    for(int n = 0; n < size; n++)
        for(int m = n+1; m < size; m++)
            x = max(x, arr[m] - arr[n]);
            
    cout << x;
    
    return 0;
}