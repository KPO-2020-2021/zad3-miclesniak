#pragma once

#include <iostream>
#include <iomanip>
#include "vector.hh"
class Prostokat
{
  private:
    Vector _wierzcholek[4];

  public:
    Prostokat();
    Prostokat(Vector a, Vector b, Vector c, Vector d);
    void move(Vector x);
    void rotate(double alfa);
    void Zapis_do_Str(std::ostream& StrmWy); // Czy musze dawac std przed ostream?? 
    void Zapis_do_pliku(const char *sNazwaPliku);
};

