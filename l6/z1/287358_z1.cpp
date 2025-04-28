#include <iostream>

using namespace std;

template<typename T>
class Vector {
private:
    T* arr;
    int sizeArr, capacity;

    void sortAug(int start, int size1, int size2) {
        T L[size1], R[size2];
        
        for (int n = 0; n < size1; n++) L[n] = arr[start + n];
        for (int n = 0; n < size2; n++) R[n] = arr[start + size1 + n];
        
        int i = 0, j = 0, k = start;
        
        while (i < size1 && j < size2)
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
    
        while (i < size1) arr[k++] = L[i++];
    
        while (j < size2) arr[k++] = R[j++];
    }

public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        sizeArr = 0;
    }
    
    ~Vector() { 
        delete[] arr; 
    }
    
    void push(T data)
    {
        if (sizeArr == capacity) {
            T* temp = new T[2 * capacity];
            for (int n = 0; n < capacity; n++)
                temp[n] = arr[n];
 
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[sizeArr++] = data;
    }
    
    void insert(T data, int index)
    {
        if(sizeArr == capacity) 
            capacity *= 2;
            
        T* temp = new T[capacity];
        for (int n = 0; n < sizeArr; n++)
            temp[n] = arr[n + (int)(n >= index)];
        
        delete[] arr;
        arr = temp;
        arr[index] = data;
        sizeArr++;
    }
    
    void pop() { sizeArr--; }
 
    int size() { return sizeArr; }
 
    int getCapacity() { return capacity; }
    
    T& operator[](int index) {
        if(index < sizeArr);
            return arr[index];
    }
    
    void sort() {
        for(int sectionSize = 2; sectionSize < sizeArr; sectionSize <<= 1) {
            for(int start = 0; start + sectionSize <= sizeArr; start += sectionSize) 
                sortAug(start, sectionSize >> 1, sectionSize >> 1);
            sortAug(sizeArr - sectionSize - (sizeArr % sectionSize), sectionSize, (sizeArr % sectionSize));
        }
    }
    
};


int main()
{
    int size, temp;
    cin >> size;
    
    Vector<int> arr;
    
    for(int n = 0; n < size; n++) {
        cin >> temp;
        arr.push(temp);
    }
    
    arr.sort();
    
    for(int n = 0; n < size; n++) cout << arr[n] << " ";
    
    return 0;
}