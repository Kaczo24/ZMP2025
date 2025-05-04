#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool* generateBoard(int size) {
    bool* board = new bool[size];
    for(int n = 0; n < size; n++)
        board[n] = (rand() & 1) == 1;
    return board;
}

int getFlipLocation(int hiddenKeyLocation, bool* board, int size) {
    int currentState = 0;
    for(int n = 0; n < size; n++)
        if(board[n])
            currentState ^= n;
    
    return currentState ^ hiddenKeyLocation;
}

int getKeyLocation(bool* board, int size) {
    int decodedKeyLocation = 0;
    for(int n = 0; n < size; n++)
        if(board[n])
            decodedKeyLocation ^= n;
    return decodedKeyLocation;
}

int main()
{
    srand(time({}));
    int p = 6;
    int size = (1 << p);
    
    // Generating a random board (works for all power-of-2 sized boards) and key location
    bool* board = generateBoard(size);
    int hiddenKeyLocation = rand() % size;
    
    if(p % 2 == 0) {
        int sideSize = 1 << (p/2);
        for(int n = 0; n < sideSize; n++) {
            for(int m = 0; m < sideSize; m++)
                cout << (int)board[n * sideSize + m];
            cout << endl;
        }
    } else {
        for(int n = 0; n < size; n++) 
            cout << (int)board[n];
        cout << endl;
    }
    // Fliping a coin, knowing the board layout and key location
    int flipLocation = getFlipLocation(hiddenKeyLocation, board, size);
    board[flipLocation] = !board[flipLocation];

    cout << endl << "hiddenKeyLocation: " << hiddenKeyLocation << endl
         << "flipLocation: " << flipLocation << endl << endl;

    // Getting key location knowing only the board layout
    int decodedKeyLocation = getKeyLocation(board, size);

    if(p % 2 == 0) {
        int sideSize = 1 << (p/2);
        for(int n = 0; n < sideSize; n++) {
            for(int m = 0; m < sideSize; m++)
                cout << (int)board[n * sideSize + m];
            cout << endl;
        }
    } else {
        for(int n = 0; n < size; n++) 
            cout << (int)board[n];
        cout << endl;
    }

    cout << endl << "decodedKeyLocation: " << decodedKeyLocation << endl;

    delete[] board;
    return 0;
}