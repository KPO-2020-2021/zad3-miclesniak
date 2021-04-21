#pragma once

#include <iostream>
#include <iomanip>
#include "vector.hh"
/**
 * @brief Modeluje pojecie obiektu Prostokat ktory składa sie z 4 wierzcholkow typu Vector
 * 
 */
class Prostokat
{
  private:
    Vector _wierzcholek[4];

  public:
    Vector operator[](const int i) const{
      return _wierzcholek[i];
    }
    Vector operator[](const int i){
      return _wierzcholek[i];
    }
    Prostokat();
    Prostokat(Vector a, Vector b, Vector c, Vector d);
    void move(Vector const x) ;
    void rotate(double const alfa);
    void Zapis_do_Str(std::ostream&  StrmWy) const; // Czy musze dawac std przed ostream?? 
    void Zapis_do_pliku(const char *const sNazwaPliku) const;
    void Compare();
};
std::ostream &operator << (std::ostream &out, Prostokat const &tmp);

