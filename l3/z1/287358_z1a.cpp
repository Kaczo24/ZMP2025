#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    long* fib = new long[]{1, 1};
    
    for(int n = 0; n < x; n++)
        fib = new long[]{fib[1], fib[0] + fib[1]};

    cout << fib[0];

    return 0;
}