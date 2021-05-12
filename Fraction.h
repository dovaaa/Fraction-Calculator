//
// Created by david on 5/8/2021.
//

#ifndef PROBLEM_2_ASSIGNMENT_1_FRACTION_H
#define PROBLEM_2_ASSIGNMENT_1_FRACTION_H

using namespace std;


class Fraction {
private: int numer,denom;
    string fracStr;

public:
     // a/b = numerator/denominator
    Fraction();

    Fraction(int numerator, int denominator);
    Fraction(string Fraction);
    void setNumer(int a);
    void setNumer(string numer);
    void setDenom(int b);
    void setDenom(string denom);
    int  getNumer();
    int  getDenom();

    string split(string Fraction);
    void print();
    void printUnreduced();
    int gcd(int a, int b);
    void reduce(int den,int num);
    double toDouble() const;
    Fraction operator + (Fraction const &obj);
    Fraction operator - (Fraction const &obj);
    Fraction operator * (Fraction const &obj);
    Fraction operator / (Fraction const &obj);
    bool operator == (Fraction const &obj);
    bool operator < (Fraction const  &obj);
    bool operator > (Fraction const  &obj);
    bool operator <= (Fraction const  &obj);
    bool operator >= (Fraction const  &obj);
    friend ostream & operator << (ostream &out,  Fraction &f);
    friend istream & operator >> (istream &in,  Fraction &f);
    ~Fraction();
};


#endif //PROBLEM_2_ASSIGNMENT_1_FRACTION_H
