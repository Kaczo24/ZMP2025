#include <iostream>

using namespace std;

int main() {
    int liczba;
    cin >> liczba;

    int count = 0;
    
    for(int p5 = 5; liczba >= p5; p5 *= 5)
        count += liczba / p5;
    cout << count;
    
    return 0;
}