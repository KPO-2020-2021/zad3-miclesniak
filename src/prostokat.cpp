#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hh"
#include "prostokat.hh"

#define PI 3.14159265359
#define ILOSC_BOKOW 4

using namespace std;

/**
 * @brief Construct a new Prostokat:: Prostokat object
 * 
 * @param a Vector z którego tworzymy wierzchołek
 * @param b Vector z którego tworzymy wierzchołek
 * @param c Vector z którego tworzymy wierzchołek
 * @param d Vector z którego tworzymy wierzchołek
 */
Prostokat::Prostokat(Vector a, Vector b, Vector c, Vector d) : _wierzcholek{a, b, c, d} {}


/**
 * @brief Funkcja przesunięcia prostokąta o zadany wektor 
 * 
 * @param a Wektor przesuniecia
 */
void Prostokat::move(Vector const a) 
{
  if (a[0] != 0 && a[1] != 0)
  {
    for (int i = 0; i < ILOSC_BOKOW; ++i)
    {
      _wierzcholek[i] = _wierzcholek[i] + a;
    }
  }
}

/**
 * @brief Funkcja obrotu prostokąta o zadany kąt 
 * 
 * @param alfa Kąt obrotu
 */
void Prostokat::rotate(double const alfa)
{
  if (alfa != 0)
  {
    double alfa_rad = alfa * PI / 180;
    double tmp[2][2] = {{std::cos(alfa_rad), -std::sin(alfa_rad)}, {std::sin(alfa_rad), std::cos(alfa_rad)}};
    Matrix Macierz_R(tmp);
    for (int i = 0; i < ILOSC_BOKOW; ++i)
    {
      _wierzcholek[i] = Macierz_R * _wierzcholek[i];
    }
  }
}

/**
 * @brief Funkcja zapisu współrzędnych wierzchołków prostokąta do strumienia 
 * 
 * @param StrmWy Strumień na który zapisujemy
 */
void Prostokat::Zapis_do_Str(std::ostream &StrmWy) const
{
  for (Vector ElemTab : _wierzcholek)
  {
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << ElemTab << endl;
  }
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << _wierzcholek[0] << endl;
}

/**
 * @brief Funkcja zapisu współrzechnych wierzchołków prostokąta do pliku
 * 
 * @param sNazwaPliku Nazwa Pliku
 */
void Prostokat::Zapis_do_pliku(const char *sNazwaPliku) const
{
  std::ofstream Strm;

  Strm.open(sNazwaPliku);
  if (!Strm.is_open())
  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
              << ":(  nie powiodla sie." << std::endl;
  }
  Zapis_do_Str(Strm);
  Strm.close();
}

/**
 * @brief Funkcja oblicza długości boków prostokąta, porównuje je i wyswietla czy sa rowne
 * 
 */
void Prostokat::Compare() 
{
  Vector bok[ILOSC_BOKOW];
  double dlugosc[4];
  for (int i = 0; i < ILOSC_BOKOW; ++i)
  {
    if (i == 0)
    {
      bok[i] = _wierzcholek[i] - _wierzcholek[i + 3];
    }
    else
    {
      bok[i] = _wierzcholek[i] - _wierzcholek[i - 1];
    }
  }
  for (int i = 0; i < ILOSC_BOKOW; ++i)
  {
    dlugosc[i] = sqrt(bok[i][0] * bok[i][0] + bok[i][1] * bok[i][1]);
  }
  if (dlugosc[0] == dlugosc[2])
  {
    cout << "Krotsze  przeciwległe boki są sobie równe" << endl;
  }
  else
  {
    cout << "Krotsze  przeciwległe boki różnią się od siebie" << endl;
  }
  if (dlugosc[1] == dlugosc[3])
  {
    cout << "Dłuzsze przeciwległe boki są sobie równe" << endl;
  }
  else
  {
    cout << "Dłuzsze przeciwległe boki różnią się od siebie" << endl;
  }
  cout << std::setw(16) << std::fixed << std::setprecision(15) << dlugosc[0] << endl;
  cout << std::setw(16) << std::fixed << std::setprecision(15) << dlugosc[1] << endl;
  cout << std::setw(16) << std::fixed << std::setprecision(15) << dlugosc[2] << endl;
  cout << std::setw(16) << std::fixed << std::setprecision(15) << dlugosc[3] << endl;
}

/**
 * @brief Funkcja Przeciazenia Wyświetlania dla Prostokata
 * 
 * @param out Strumien Wyjsciowy
 * @param tmp Obiekt z którego wyswietlamy informacje
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &out, const Prostokat &tmp)
{
  for (int i = 0; i < 4; ++i)
  {
    out << std::setw(16) << std::fixed << std::setprecision(10) << tmp[i] << endl;
  }
  return out;
}