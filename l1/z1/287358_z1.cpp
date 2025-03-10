#include <iostream>

using namespace std;

int f(int x) {
    if(x&1==1) return 3*x + 1;
    return x >> 1;
}

int main() {
    int liczba;
    cin >> liczba;
    
    int count = 1;
    cout << liczba;
    while(liczba != 1) {
        liczba = f(liczba);
        cout << " " << liczba;
        count++;
    }
    cout << ", " << count;
    
    return 0;
}