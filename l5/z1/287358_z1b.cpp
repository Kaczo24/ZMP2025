#include <iostream>

using namespace std;

int merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
  
    int L[n1], M[n2];
  
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    
    int i = 0, j = 0, k = p, count = 0;

    while (i < n1 && j < n2)
        if (L[i] <= M[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = M[j++];
            count += n1 - i;
        }

    while (i < n1) 
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = M[j++];
    
    return count;
}


int mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2, count = 0;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);

        return count + merge(arr, l, m, r);
    }
    return 0;
}


int main()
{
    int size;
    cin >> size;
    
    int arr[size];
    
    for(int n = 0; n < size; n++)
        cin >> arr[n];
        
    int inv = 0;
    
            
    cout << mergeSort(arr, 0, size - 1);
    
    return 0;
}