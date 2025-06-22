#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
class Multiset;
template <typename T>
ostream& operator<<(ostream&, const Multiset<T>&);

template <typename T>
class Multiset {
    private:
    unordered_map<T, unsigned int> data;
    
    public:
    
    void addElement(T element) {
        data[element]++;
    }
    
    void addElementN(T element, unsigned int number) {
        data[element] += number;
    }
    
    void RemoveElement(T element) {
        if(data.contains(element)) {
            data[element]--;
            if(data[element] <= 0) 
                data.erase(element);
        }
    }
    
    void RemoveElementN(T element, unsigned int number) {
        if(data.contains(element)) {
            data[element] -= number;
            if(data[element] <= 0) 
                data.erase(element);
        }
    }
    
    bool operator==(const Multiset<T> &other) {
        for(auto &pair : data) {
            if(!other.data.contains(pair.first))
                return false;
            if(pair.second != other.data.at(pair.first))
                return false;
        }
        return true;
    }
    
    bool operator!=(const Multiset<T> &other) {
        return !((*this) == other);
    }
    
    bool operator <=(const Multiset<T> &other) {
        for(auto &pair : data) {
            if(!other.data.contains(pair.first))
                return false;
            if(pair.second > other.data.at(pair.first))
                return false;
        }
    }
    
    bool operator>(const Multiset<T> &other) {
        return !((*this) <= other);
    }
    
    bool operator >=(const Multiset<T> &other) {
        for(auto &pair : data) {
            if(!other.data.contains(pair.first))
                return false;
            if(pair.second < other.data.at(pair.first))
                return false;
        }
    }
    
    bool operator<(const Multiset<T> &other) {
        return !((*this) >= other);
    }
    
    Multiset operator+(const Multiset<T> &other) {
        Multiset<T> result;
        for(auto &pair : data)
            result.addElementN(pair.first, pair.second);
        for(auto &pair : other.data)
            result.addElementN(pair.first, pair.second);
        return result;
    }
    
    Multiset operator+=(const Multiset<T> &other) {
        for(auto &pair : other.data)
            addElementN(pair.first, pair.second);
        return *this;
    }
    
    Multiset operator*(const Multiset<T> &other) {
        Multiset<T> result;
        for(auto &pair : data) {
            if(other.data.contains(pair.first))
                result.addElementN(pair.first, pair.second < other.data.at(pair.first) ? pair.second : other.data.at(pair.first));
        }
        return result;
    }
    
    Multiset operator*=(const Multiset<T> &other) {
        for(auto &pair : data)
            if(other.data.contains(pair.first))
                data[pair.first] = pair.second < other.data.at(pair.first) ? pair.second : other.data.at(pair.first);
            else data.erase(pair.first);
        return *this;
    }
    
    Multiset operator-(const Multiset<T> &other) {
        Multiset<T> result;
        for(auto &pair : data)
            if(other.data.contains(pair.first))
                if(pair.second > other.data.at(pair.first))
                    result.addElementN(pair.first, pair.second - other.data.at(pair.first));
        return result;
    }
    
    Multiset operator-=(const Multiset<T> &other) {
        for(auto &pair : data)
            if(other.data.contains(pair.first)) {
                if(pair.second > other.data.at(pair.first))
                    data[pair.first] = pair.second - other.data.at(pair.first);
                else data.erase(pair.first);
            } else data.erase(pair.first);
        return *this;
    }
    
    friend ostream& operator<< <>(ostream&, const Multiset<T>&);
};

template <typename T>
ostream& operator<<(ostream &os, const Multiset<T> &m)
{
    for(auto &pair : m.data)
        os << "{" << pair.first << ", " << pair.second << "}, ";
    os << endl;
    return os;
}

int main()
{
    int n1, n2, temp;
    Multiset<int> m1, m2;
    cin >> n1 >> n2;
    for(int n = 0; n < n1; n++) {
        cin >> temp;
        m1.addElement(temp);
    }
    for(int n = 0; n < n2; n++) {
        cin >> temp;
        m2.addElement(temp);
    }
    
    cout << m1 << m2 << m1 + m2 << m1 * m2 << m1 - m2 << (m1 <= m2 ? "true" : "false");
    
    return 0;
}