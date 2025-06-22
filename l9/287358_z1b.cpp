#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int arr[n];
    for(int m = 0; m < n; m++)
        cin >> arr[m];
    
    unsigned long long subset = 0;
    for(unsigned long long mask = 1; mask < (1 << n); mask++) { // zaczyna się od 1 by nie uwzględniać multizbioru pustego, choć zgodnie z treścią zadania on zawsze działa
        int sum = 0;
        for(int m = 0; m < n; m++)
            if((mask & (1 << m)) != 0)
                sum += arr[m];
        if(sum == 0) {
            subset = mask;
            break;
        }
    }
    
    if(subset == 0)
        cout << "nie ma";
    else
        for(int m = 0; m < n; m++)
            if((subset & (1 << m)) != 0)
                cout << arr[m] << ", ";
    
    return 0;
}