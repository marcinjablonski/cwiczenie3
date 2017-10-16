#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct Probka
{
    double t,x;
    Probka();
    Probka(double t2, double x2)
    {
        t = t2;
        x = x2;
    }
};

typedef vector <Probka> Dane;



vector <Probka> wczytaj (const string& nazwa_pliku)
{
    vector<Probka> dane;
    ifstream plik;
    plik.open(nazwa_pliku.c_str(), ios::in);
    string linia;
    while (getline (plik, linia))
    {
        stringstream ss (linia);
        double liczba1, liczba2;
        ss >> liczba1;
        ss.ignore();
        ss >> liczba2;
        Probka nowa_probka(liczba1, liczba2);
        dane.push_back(nowa_probka);

    }
    plik.close();
    return dane;
}

void wyswietl (const vector<Probka>& dane)
{
    for (int i = 0; i < dane.size(); ++i)
        {
            cout << dane[i].t << ", " << dane[i].x << endl;
        }
}
void zapisz (const vector<Probka>& dane, const string& nazwa_pliku)
{
    ofstream plik;
    plik.open(nazwa_pliku.c_str(), ios::out);
    for (int i = 0; i < dane.size(); ++i)
        {
            plik << dane[i].t << ", " << dane[i].x << endl;
        }
    plik.close();
}
double srednia (const vector<Probka>& dane)
{
    double m = 0.0;
    for (int i = 0; i < dane.size(); ++i)
        {
            m += dane[i].x;
        }
    if (dane.size() > 0)
        {
            m = m / dane.size();
        }
    return m;
}
double minimum(const vector <Probka>& dane)
{
    double _min = 10000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].x < _min)
                _min = dane[i].x;
        }
    return _min;
}
double maksimum(const vector <Probka>& dane)
{
    double _max = -1000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].x > _max)
            _max = dane[i].x;
        }
    return _max;
}
double calka(const vector <Probka>& dane)
{
    double calka = 0, dt = 0, dpole = 0;
    for (int i=1; i < dane.size()-1; i++)
        {
            dt = dane[i+1].t - dane[i].t;
            dpole = (dane[i].x + dane[i+1].x) * dt / 2;
            calka = calka + dpole;
        }
    return calka;
}

int main ()
{
    string o_nazwa, z_nazwa;
    cout << "Podaj plik odczytowy: "; cin >> o_nazwa;
    cout << "Podaj plik zapisowy: "; cin >> z_nazwa;
    wyswietl (wczytaj(o_nazwa));
    cout << "Srednia wartosc t: " << srednia (wczytaj(o_nazwa)) <<  endl;
    cout << "Min: " << minimum (wczytaj(o_nazwa)) << endl << "Max: " << maksimum(wczytaj(o_nazwa)) << endl;
    zapisz (wczytaj (o_nazwa), z_nazwa);
    cout << "Calka: " << calka(wczytaj(o_nazwa));
}
