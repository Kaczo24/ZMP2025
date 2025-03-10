#include <iostream>
#include <set>

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

int main() {
    int liczba;
    cout << "Podaj liczbę:";
    cin >> liczba;
    cout << euler(liczba);
    
    return 0;
}