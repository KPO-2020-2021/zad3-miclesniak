#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
/**
 * @brief Modeluje pojecie obiektu Matrix 
 * 
 */
class Matrix
{

private:
  double value[SIZE][SIZE]; // Wartosci macierzy

public:
  Matrix(double[SIZE][SIZE]); // Konstruktor klasy

  Matrix(); // Konstruktor klasy

  bool operator == (Matrix const tmp) const;

  void ElminacjaGaussa();

  void Oblwyznacznik() const;

  Vector operator*(Vector const tmp); // Operator mnożenia przez wektor

  Matrix operator+(Matrix const tmp);

  double &operator()(unsigned int const row, unsigned int const column);

  const double &operator()(unsigned int const row, unsigned int const column) const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

