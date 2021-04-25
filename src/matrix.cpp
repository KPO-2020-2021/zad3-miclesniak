#include <iostream>
#include "matrix.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      value[i][j] = 0;
    }
  }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      value[i][j] = tmp[i][j];
    }
  }
}
/**
 * @brief Funkcja porownania Macierzy
 * 
 * @param tmp - Macierz do ktorej porownujemy
 * @return true - Macierze sa takie same
 * @return false - Macierze roznia sie od siebie
 */
bool Matrix::operator==(Matrix const tmp) const
{
  if (value[0][0] == tmp(0, 0) && value[0][1] == tmp(0, 1) && value[1][0] == tmp(1, 0) && value[1][1] == tmp(1, 1))
    return true;
  else
    return false;
}
/**
 * @brief Funkcja obliczania wyznacznika Macierzy
 * 
 */
void Matrix::Oblwyznacznik() const{
double wyznacznik=0;

for(int i=0;i<SIZE;++i){
  if(i==0){
    wyznacznik = value[i][i] * 1;
  }
  else
    wyznacznik *= value[i][i];
}
std::cout<<"Wyznacznik macierzy jest równy: "<<wyznacznik<<std::endl;
}
/**
 * @brief Funkcja przeksztalcania Macierzy za pomoca elminacji Gaussa
 * 
 */
void Matrix::ElminacjaGaussa()
{
  double ratio;
  for (int i = 0; i <= SIZE - 2; i++)
  {
    if (value[i][i] == 0.0)
    {
      std::cout << "Mathematical Error!";
      exit(0);
    }
    for (int j = i+1; j <= SIZE - 1; j++)
    {
      ratio = value[j][i] / value[i][i];

      for (int k = 0; k <= SIZE; k++)
      {
        value[j][k] = value[j][k] - ratio * value[i][k];
      }
    }
  }
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator*(Vector const tmp)
{
  Vector result;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result[i] += value[i][j] * tmp[j];
    }
  }
  return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int const row, unsigned int const column)
{

  if (row >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
  }

  if (column >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
  }

  return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator()(unsigned int const row, unsigned int const column) const
{

  if (row >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
  }

  if (column >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
  }

  return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator+(Matrix const tmp)
{
  Matrix result;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result(i, j) = this->value[i][j] + tmp(i, j);
    }
  }
  return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat)
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      in >> mat(i, j);
    }
  }
  return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
    }
    std::cout << std::endl;
  }
  return out;
}
