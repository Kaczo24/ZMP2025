#include <iostream>

using namespace std;

void merge(int arr[], int start, int size1, int size2) { 
    int L[size1], R[size2];
    
    for (int n = 0; n < size1; n++) L[n] = arr[start + n];
    for (int n = 0; n < size2; n++) R[n] = arr[start + size1 + n];
    
    int i = 0, j = 0, k = start;
    
    while (i < size1 && j < size2)
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];

    while (i < size1) arr[k++] = L[i++];

    while (j < size2) arr[k++] = R[j++];
}

int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
            
    for(int sectionSize = 2; sectionSize < size; sectionSize <<= 1) {
        for(int start = 0; start + sectionSize <= size; start += sectionSize) 
            merge(arr, start, sectionSize >> 1, sectionSize >> 1);
        merge(arr, size - sectionSize - (size % sectionSize), sectionSize, (size % sectionSize));
    }

    for(int n = 0; n < size; n++) cout << arr[n] << " ";
    
    return 0;
}