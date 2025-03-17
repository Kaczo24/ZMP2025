#include <iostream>

using namespace std;

int main()
{
    int message = 0, key = 0, bit;
    
    for(int n = 0; n < 8; n++) {
        cin >> bit;
        message = (message << 1) | bit;
    }
    
    for(int n = 0; n < 8; n++) {
        cin >> bit;
        key = (key << 1) | bit;
    }
    
    int sec = message ^ key;
    
    for(int n = 0; n < 8; n++)
        cout << (int)((sec & (1 << (7 - n))) != 0) << " ";
    
    return 0;
}