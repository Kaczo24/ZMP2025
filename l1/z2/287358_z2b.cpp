#include <iostream>

using namespace std;

int euler(int x) {
    int count = 0;
    for(int n = 1; n <= x; n++) {
        int a = x, b = n;
        while(a != b) if(a > b) a -= b; else b -= a;
        if(a == 1) 
            count++;
    }
    return count;
}

int F(int x) {
    int sum = 0;
    for(int n = 1; n <= x; n++) {
        if(x % n == 0) {
            sum += euler(n);
        }
    }
    return sum;
}

int main() {
    int liczba;
    cin >> liczba;
    cout << F(liczba);
    
    return 0;
}