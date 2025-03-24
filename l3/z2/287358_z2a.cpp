#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
    
    for(long n = 0; n < ((long)1 << (long)size); n++) {
        for(int m = 0; m < size; m++) 
            if((n & (1 << m)) != 0) 
                cout << arr[m] << " "; 
        cout << endl;
    }

    return 0;
}