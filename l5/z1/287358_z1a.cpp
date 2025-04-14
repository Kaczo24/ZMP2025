#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
        
    int inv = 0;
    for(int n = 0; n < size; n++)
        for(int m = n+1; m < size; m++)
            inv += (int)(arr[n] > arr[m]);
            
    cout << inv;
    
    return 0;
}