#include <iostream>

using namespace std;

long fib(int n, int f1 = 1, int f2 = 1) {
    if(n == 0) return f1;
    if(n == 1) return f2;
    return fib(n - 1, f2, f1+f2);
}

int main()
{
    int x;
    cin >> x;
    cout << fib(x);
    return 0;
}