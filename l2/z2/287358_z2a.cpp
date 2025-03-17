#include <iostream>

using namespace std;

int main()
{
    int x, size;
    cin >> x;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
    
    for(int n = 0; n < size; n++)
        if(arr[n] == x) {
            cout << "tak " << n;
            return 0;
        }
    
    cout << "nie";
    return 0;
}