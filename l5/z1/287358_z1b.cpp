#include <iostream>

using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int L[size1], R[size2];
  
    for (int n = 0; n < size1; n++) L[n] = arr[left + n];
    for (int n = 0; n < size2; n++) R[n] = arr[mid + 1 + n];
    
    int i = 0, j = 0, k = left, count = 0;
    
    while (i < size1 && j < size2)
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            count += size1 - i;
        }

    while (i < size1) arr[k++] = L[i++];

    while (j < size2) arr[k++] = R[j++];
    
    return count;
}


int mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2, count = 0;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);

        return count + merge(arr, left, mid, right);
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