#include <iostream>
#include <tuple>

// O(n) btw, dokładniej 2n-1

using namespace std;

inline int min(int n, int m) { return m > n ? n : m; }
inline int max(int n, int m) { return m < n ? n : m; }


tuple<int, int, int> seek(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        auto left = seek(arr, l, m);
        auto right = seek(arr, m + 1, r);

        return {
            min(get<0>(left), get<0>(right)),
            max(get<1>(left), get<1>(right)), 
            max(max(get<2>(left), get<2>(right)), get<1>(right) - get<0>(left))
        };
    }
    return {arr[l], arr[r], 0};
}

int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
            
    auto out = seek(arr, 0, size - 1);
            
    cout << get<2>(out);
    
    return 0;
}