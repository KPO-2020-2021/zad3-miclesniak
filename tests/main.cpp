#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"
#include "../include/matrix.hh"
#include "../include/prostokat.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Test Konstruktora Bezparametrycznego Wektora")
{
    Vector tmp;
    tmp = Vector();
    double x = 0;
    CHECK(tmp[0] == x);
    CHECK(tmp[1] == x);
}

TEST_CASE("Test Konstruktora Parametrycznego Wektora"){
    Vector tmp;
    double ttmp[] = {10,20};
    tmp = Vector(ttmp);
    double x = 10,y = 20;
    CHECK(tmp[0] == x);
    CHECK(tmp[1] == y);
}

TEST_CASE("Test porownania wektorów")
{
    double tmp1[] = {15,10};
    Vector V1 = Vector(tmp1);
    Vector V2 = Vector(tmp1);
    CHECK_EQ(V1 == V2,true);
}

TEST_CASE("Test porownania 2 wektorów")
{
    double tmp1[] = {15,10} ,tmp2[] = {10,13};
    Vector V1 = Vector(tmp1);
    Vector V2 = Vector(tmp2);
    CHECK_EQ( V1 == V2,false );
}

TEST_CASE("Test dodawania wektorów"){
    double tmp1[] = {10,20};
    double tmp2[] = {3.5 , 7.89};
    Vector V1 = Vector(tmp1);
    Vector V2 = Vector(tmp2);
    Vector V3;
    V3 = V1 + V2;
    double wynik[] = {13.5 ,27.89};
    Vector V4 = Vector(wynik);
    
    CHECK( V3 == V4);
}

TEST_CASE("Test odejmowania wektorów"){
    double tmp1[] = {15,23},tmp2[] = {3.5 , 7.89};
    Vector V1 = Vector(tmp1);
    Vector V2 = Vector(tmp2);
    // Vector V3;
    // V3 = 
    double wynik[] = {11.5 , 15.11};
    Vector V4 = Vector(wynik);
    
    CHECK_EQ(V1 - V2, V4);
}

TEST_CASE("Test wypisywania Wektora")
{
    std::stringstream os;
    Vector tmp;
    double tab[] = {1,2};
    tmp = Vector(tab);
    os << tmp;
    CHECK_EQ("1 2 ",os.str());
}

TEST_CASE("Test wczytywania Wektora")
{
    std::stringstream is;
    double tab[] = {3,3};
    Vector V1,V2;
    V2 = Vector(tab);
    is << "3 3 ";
    is >> V1;
    CHECK(V1 == V2);
}

TEST_CASE("Test operatora [] dla Wektora")
{
 Vector V1;
 double tab[] = {5,7};
 V1 = Vector(tab);
 CHECK_EQ(V1[0],5);
 CHECK_EQ(V1[1],7);
}

TEST_CASE("Test konstruktora Macierzy"){
Matrix tmp;
tmp = Matrix();
CHECK(tmp(0,1) == 0);
CHECK(tmp(1,0) == 0);
CHECK(tmp(1,1) == 0);
CHECK(tmp(0,0) == 0);
}

TEST_CASE("Test konstruktora parametrycznego Macierzy"){
Matrix tmp;
double tab[2][2] = {{10.3 , 5} , {3.5, 7.1}};
tmp = Matrix(tab);
CHECK(tmp(0,1) == 5);
CHECK(tmp(1,0) == 3.5);
CHECK(tmp(1,1) == 7.1);
CHECK(tmp(0,0) == 10.3);
}

TEST_CASE("Test przeciazenia porownania dla Macierzy"){
    Matrix M1, M2;
    double tmp1[2][2] = {{10.123,20.89},{29.999,40.654}};
    double tmp2[2][2] = {{10.123,20.89},{29.999,40.654}};
    M1 = Matrix(tmp1);
    M2 = Matrix(tmp2);
    

    CHECK_EQ(M1 == M2, true);
}

TEST_CASE("Test przeciazenia porownania dla Macierzy 2"){
    Matrix M1, M2;
    double tmp1[2][2] = {{11,23},{29.99,40.654}};
    double tmp2[2][2] = {{14,28},{40.13,42.43}};
    M1 = Matrix(tmp1);
    M2 = Matrix(tmp2);
    

    CHECK_EQ(M1 == M2, false);
}

TEST_CASE("Test przeciazenia mnozenia Macierzy razy Wektor"){
    Matrix M1;
    Vector V1;
    double tmp1[] = {10,20};
    V1 = Vector(tmp1);
    double tmp2[2][2] = {{10,20},{30,40}};
    double tmp3[] = {500,1100};
    Vector wynik;
    Vector prawidlowy_wynik;
    prawidlowy_wynik = Vector(tmp3);
    M1 = Matrix(tmp2);

    wynik = M1 * V1;
    CHECK(wynik == prawidlowy_wynik);
}



TEST_CASE("Test przeciazenia dodawania macierzy"){
    Matrix M1, M2, WM3,PWM3;
    double tmp1[2][2] = {{10,20},{30,40}};
    double tmp2[2][2] = {{500,1100},{120,340}};
    double tmp3[2][2] = {{510,1120},{150,380}};
    M1 = Matrix(tmp1);
    M2 = Matrix(tmp2);
    PWM3 = Matrix(tmp3);
    
    WM3 = M1 + M2;

    CHECK(WM3 == PWM3);
}

TEST_CASE("Przeciazenie () dla Macierzy"){
    Matrix M1;
    double tmp[2][2] = {{3.1,5.9},{2.75,20}};
    M1 = Matrix(tmp);
    
    CHECK(M1(0,0) == 3.1);
    CHECK(M1(1,0) == 2.75);
}

TEST_CASE("Przeciazenie wypisywania dla Macierzy"){
    std::stringstream os; 
    Matrix M1;
    double tmp[2][2] = {{15,22},{3,11}};
    M1 = Matrix(tmp);
    os<<M1;
    CHECK_EQ("| 15 | | 22 | | 3 | | 11 | ",os.str());
}

TEST_CASE("Przeciazenie wczytywania dla Macierzy"){
    std::stringstream is;
    Matrix M1,M2;
    double tmp[2][2] = {{10.22,21},{399,107.123}};
    M2 = Matrix(tmp);
    // is << "| 10.22 | | 21 | | 399 | | 107.123 | ";
    is << "10.22 21 399 107.123 ";
    is >> M1;

    CHECK(M1 == M2);
}

TEST_CASE("Test konstruktora parametrycznego Prostokata"){
    
    double tmp1[] = {1,1},tmp2[] = {2,2},tmp3[] = {3,3}, tmp4[] = {4,4};
    Vector v1,v2,v3,v4;
    v1 = Vector(tmp1);
        v2 = Vector(tmp2);
            v3 = Vector(tmp3);
                v4 = Vector(tmp4);
    Prostokat P1 = Prostokat(v1,v2,v3,v4);
    CHECK(P1[0] == v1);
    CHECK(P1[1] == v2);
    CHECK(P1[2] == v3);
    CHECK(P1[3] == v4);
}


TEST_CASE("Test metody obrotu prostokąta o 90 stopni"){
    
    double tmp1[] = {-2,1},tmp2[] = {2,1},tmp3[] = {2,-1}, tmp4[] = {-2,-1};
    Vector v1,v2,v3,v4,v5,v6,v7,v8;
    v1 = Vector(tmp1);
        v2 = Vector(tmp2);
            v3 = Vector(tmp3);
                v4 = Vector(tmp4);
    Prostokat P1 = Prostokat(v1,v2,v3,v4);
    P1.rotate(90);
    double tmp5[] = {-1,-2},tmp6[] = {-1,2},tmp7[] = {1,2}, tmp8[] = {1,-2};
    v5 = Vector(tmp5);
        v6 = Vector(tmp6);
            v7 = Vector(tmp7);
                v8 = Vector(tmp8);
    CHECK_EQ(P1[0] == v5,true);
    CHECK(P1[1] == v6);
    CHECK(P1[2] == v7);
    CHECK(P1[3] == v8);
}

TEST_CASE("Test metody obrotu prostokąta o -270 stopni"){
    
    double tmp1[] = {-2,1},tmp2[] = {2,1},tmp3[] = {2,-1}, tmp4[] = {-2,-1};
    Vector v1,v2,v3,v4,v5,v6,v7,v8;
    v1 = Vector(tmp1);
        v2 = Vector(tmp2);
            v3 = Vector(tmp3);
                v4 = Vector(tmp4);
    Prostokat P1 = Prostokat(v1,v2,v3,v4);
    P1.rotate(-270);
    double tmp5[] = {-1,-2},tmp6[] = {-1,2},tmp7[] = {1,2}, tmp8[] = {1,-2};
    v5 = Vector(tmp5);
        v6 = Vector(tmp6);
            v7 = Vector(tmp7);
                v8 = Vector(tmp8);
    CHECK(P1[0] == v5);
    CHECK(P1[1] == v6);
    CHECK(P1[2] == v7);
    CHECK(P1[3] == v8);
}

TEST_CASE("Test wypisywania prostokata"){
    std::stringstream os;
    double tmp1[] = {-2,1},tmp2[] = {2,1},tmp3[] = {2,-1}, tmp4[] = {-2,-1};
    Vector v1,v2,v3,v4;
    v1 = Vector(tmp1);
        v2 = Vector(tmp2);
            v3 = Vector(tmp3);
                v4 = Vector(tmp4);
    Prostokat P1 = Prostokat(v1,v2,v3,v4);
    os << P1;
    CHECK_EQ("    -2.0000000000 1.0000000000\n    2.0000000000 1.0000000000\n    2.0000000000 -1.0000000000\n   -2.0000000000 -1.0000000000\n" ,os.str());
}

TEST_CASE("Test translacji"){
    double tmp1[] = {-5,2},tmp2[] = {5,2},tmp3[] = {5,-2}, tmp4[] = {-5,-2};
    Vector v1,v2,v3,v4,v5,v6,v7,v8;
    v1 = Vector(tmp1);
        v2 = Vector(tmp2);
            v3 = Vector(tmp3);
                v4 = Vector(tmp4);
    Prostokat P1 = Prostokat(v1,v2,v3,v4);
    double tmp5[] = {5,22},tmp6[] = {15,22},tmp7[] = {15,18}, tmp8[] = {5,18};
    v5 = Vector(tmp5);
        v6 = Vector(tmp6);
            v7 = Vector(tmp7);
                v8 = Vector(tmp8);

    double tmpp[] = {10,20};
    Vector V1 = Vector(tmpp);
    P1.move(V1);
    CHECK(P1[0] == v5);
    CHECK(P1[1] == v6);
    CHECK(P1[2] == v7);
    CHECK(P1[3] == v8);
}