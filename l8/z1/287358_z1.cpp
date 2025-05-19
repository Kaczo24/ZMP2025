#include <iostream>
#include <string>

using namespace std;

class Pojazd {
    protected:
    string marka;
    string model;
    int rok_produkcji;
    
    public:
    Pojazd();
    Pojazd(string _marka, string _model, int _rok_produkcji) {
        marka = _marka;
        model = _model;
        rok_produkcji = _rok_produkcji;
    }
    
    void Wyswietl() {
        cout << marka << " " << " z " << rok_produkcji << endl;
    }
    
};

class Samochod : Pojazd {
    protected:
    int liczba_drzwi;
    
    public:
    Samochod() : Pojazd() {}
    Samochod(string _marka, string _model, int _rok_produkcji, int _liczba_drzwi) : Pojazd(_marka, _model, _rok_produkcji) {
        liczba_drzwi = _liczba_drzwi;
    }
    
    void Wyswietl() {
        cout << marka << " " << model << " z " << rok_produkcji << ", " << liczba_drzwi << "-drzwiowy" << endl;
    }
    
};

class Rower : Pojazd {
    protected:
    int liczba_przerzutek;
    
    public:
    Rower() : Pojazd() {}
    Rower(string _marka, string _model, int _rok_produkcji, int _liczba_przerzutek) : Pojazd(_marka, _model, _rok_produkcji) {
        liczba_przerzutek = _liczba_przerzutek;
    }
    
    void Wyswietl() {
        cout << marka << " " << model << " z " << rok_produkcji << ", o " << liczba_przerzutek << " przerzutkach" << endl;
    }
};



int main()
{
    string a, b;
    int c, d;
    cin >> a >> b >> c >> d;
    Samochod(a,b,c,d).Wyswietl();
    cin >> a >> b >> c >> d;
    Rower(a,b,c,d).Wyswietl();
    
    return 0;
}