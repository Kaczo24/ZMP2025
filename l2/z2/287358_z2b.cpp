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
    
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (arr[mid] == x) {
            cout << "tak " << mid;
            return 0;
        }

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    cout << "nie";
    return 0;
}