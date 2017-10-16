#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

typedef vector <swag> Dane;
vector <swag> wczytaj (const string& nazwa_pliku)
{
    vector<swag> dane;
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
        swag nowa_probka(liczba1, liczba2);
        dane.push_back(nowa_probka);

    }
    plik.close();
    return dane;
}

void wyswietl (const vector<swag>& dane)
{
    for (int i = 0; i < dane.size(); ++i)
        {
            cout << dane[i].t << ", " << dane[i].x << endl;
        }
}
void zapisz (const vector<swag>& dane, const string& nazwa_pliku)
{
    ofstream plik;
    plik.open(nazwa_pliku.c_str(), ios::out);
    for (int i = 0; i < dane.size(); ++i)
        {
            plik << dane[i].t << ", " << dane[i].x << endl;
        }
    plik.close();
}
double srednia (const vector<swag>& dane)
{
    double m = 0.0;
    for (int i = 0; i < dane.size(); ++i)
        {
            m += dane[i].t;
        }
    if (dane.size() > 0)
        {
            m = m / dane.size();
        }
    return m;
}
double minimum(const vector <swag>& dane)
{
    double _min = 10000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].t < _min)
                _min = dane[i].t;
        }
    return _min;
}
double maksimum(const vector <swag>& dane)
{
    double _max = -1000000;
    for ( int i=0; i<dane.size(); i++)
        {
            if (dane[i].t > _max)
                _max = dane[i].t;
        }
    return _max;
}
double calka(const vector <swag>& dane)
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
