#pragma once

#include "size.hh"
#include <iostream>

/**
 * @brief Modeluje pojecie obiektu Vector 
 * 
 */
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    bool operator == (const Vector &V) const;

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);

