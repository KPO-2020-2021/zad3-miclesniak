// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

int main()
{
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D

  PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                              // rysunku prostokata

  //-------------------------------------------------------
  //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
  //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
  //  na dwa sposoby:
  //   1. Rysowane jako linia ciagl o grubosci 2 piksele
  //
  Lacze.DodajNazwePliku("prostokat.dat", PzG::RR_Ciagly, 2);
  //
  //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
  //      których połowa długości boku wynosi 2.
  //
  Lacze.DodajNazwePliku("prostokat.dat", PzG::RR_Punktowy, 2);
  //
  //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
  //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
  //  jako wspolrzedne punktow podajemy tylko x,y.
  //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  double p1[] = {200.0, 100.0};   //Prawy Górny Wierzchołek
  double p2[] = {200.0, -100.0};  //Prawy Dolny Wierzchołek
  double p3[] = {-200.0, -100.0}; //Lewy Dolny Wierzchołek
  double p4[] = {-200.0, 100.0};  //Lewy Górny wirzchołek
  Vector V1 = Vector(p1);
  Vector V2 = Vector(p2);
  Vector V3 = Vector(p3);
  Vector V4 = Vector(p4);
  Prostokat P1 = Prostokat(V1, V2, V3, V4);

  char x;
  std::cout << "o - obrót o zadany kąt" << std::endl;
  std::cout << "p - przesunięcie prostokąta o zadany wektor" << std::endl;
  std::cout << "w - wyswietl współrzędne wierzchołków" << std::endl;
  std::cout << "m - wyświetl menu" << std::endl;
  std::cout << "n - narysuj prostokat" <<std::endl;
  std::cout << "k - koniec działania programu" << std::endl;
  std::cout << "Twój wybór? (m - menu) --> ";
  std::cin >> x;
  while (x != 'k')
  {
    switch (x)
    {
    case 'o':
    {
      std::cout << "Podaj wartosc kata obrotu w stopniach:";
      int kat;
      std::cin >> kat;
      std::cout << "Ile razy operacja obrotu ma być powtórzona?";
      int il;
      std::cin >> il;
      for (int i = 0; i < il; ++i)
      {
        P1.rotate(kat);
      }
      P1.Compare();
    }
    break;

    case 'p':
    {
      double tab[2];
      std::cout << "Wprowadz współrzedne wetkora(Wartosc x i y): ";
      std::cin >> tab[0] >> tab[1];
      Vector Wektor_Przesuniecia = Vector(tab);
      P1.move(Wektor_Przesuniecia);
    }
    break;

    case 'w':
      std::cout<<P1;
      break;

    case 'm':
    {
      std::cout << "o - obrót o zadany kąt" << std::endl;
      std::cout << "p - przesunięcie prostokąta o zadany wektor" << std::endl;
      std::cout << "w - wyswietl współrzędne wierzchołków" << std::endl;
      std::cout << "m - wyświetl menu" << std::endl;
      std::cout << "n - narysuj prostokat" <<std::endl;
      std::cout << "k - koniec działania programu" << std::endl;
    }
    break;

    case 'n':
    {
    P1.Zapis_do_pliku("prostokat.dat");
    Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
    }
    break;

    default:
      std::cout << "Niepoprawna opcja!" << std::endl;
      break;
    }
    std::cout << "Twój wybór? (m - menu) --> ";
    std::cin >> x;
  }
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//Test Metody liczenia Wyznacznika i Elminacji Gaussa //
// | | | | | | | | | | | | | | | | | | | | | | | | | |//
// v v v v v v v v v v v v v v v v v v v v v v v v v v//
// double tmp[2][2] = {{10.22,21},{399,107.123}};
// Matrix M2 = Matrix(tmp);
// M2.Oblwyznacznik();
// std::cout<<M2;
// M2.ElminacjaGaussa();
// M2.Oblwyznacznik();
// std::cout<<M2;}


// Z bazy projektu-wydmuszki Boiler Plate C++:
// Bring in the dummy class from the example source,
// just to show that it is accessible from main.cpp.
Dummy d = Dummy();
return d.doSomething() ? 0 : -1;
}
