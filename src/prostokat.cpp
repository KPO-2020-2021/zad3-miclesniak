#include <iostream>
#include <cmath>
#include <fstream>
#include "matrix.hh"
#include "prostokat.hh"
#define PI 3.14159265359

using namespace std;

Prostokat::Prostokat(Vector a, Vector b, Vector c, Vector d) : _wierzcholek{a, b, c, d} {}

void Prostokat::move(Vector a)
{
  if (a[0] != 0 && a[1] != 0)
  {
    for (int i = 0; i < 4; ++i)
    {
      _wierzcholek[i] = _wierzcholek[i] + a;
    }
  }
}

void Prostokat::rotate(double alfa)
{
  if (alfa != 0)
  {
    double alfa_rad = alfa * PI / 180;
    double tmp[2][2] = {{std::cos(alfa_rad), -std::sin(alfa_rad)}, {std::sin(alfa_rad), std::cos(alfa_rad)}};
    Matrix Macierz_R(tmp);
    for (int i = 0; i < 4; ++i)
    {
      _wierzcholek[i] = Macierz_R *_wierzcholek[i];
    }
  }
}
void Prostokat::Zapis_do_Str(std::ostream &StrmWy)
{
  for (Vector ElemTab : _wierzcholek)
  {
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << ElemTab << endl;
  }
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << _wierzcholek[0] << endl;
}

void Prostokat::Zapis_do_pliku(const char *sNazwaPliku)
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
