//
// Created by david on 5/8/2021.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Fraction.h"
using namespace std;
Fraction::Fraction() {}
Fraction::Fraction(int numerator, int denominator) {
    try {
        numer = numerator;
        if(denominator==0){throw "cant divide by zero";}
        else denom=denominator;
    } catch (const char* e) {
    cout<<"cant divide by zero"<<endl<<"assigning denominator with value = 1"<<endl;
    denominator =1;
    }
}

string Fraction::split(string Fraction){
    int start = Fraction.find("/") +1 ;

    string newFraction;
    newFraction =Fraction.substr(start);

    return newFraction;
}
Fraction::Fraction(string Fraction) {

   stringstream test(Fraction);
   stringstream test2(split(Fraction));

   int numerator=0;
   int denominator = 0;
   test>>numerator;
   test2>>denominator;

    try {
        numer = numerator;
        if(denominator==0){throw "cant divide by zero";}
        else denom=denominator;
    } catch (const char* e) {
        cout<<"cant divide by zero"<<endl<<"assigning denominator with value = 1"<<endl;
        denominator =1;
    }

}
void Fraction::setNumer(int numerator) { numer=numerator;}
void Fraction::setNumer(string numerator) {}
void Fraction::setDenom(int denominator) { denom=denominator;}
void Fraction::setDenom(string denom) {}
int Fraction::getNumer() {return numer;}
int Fraction::getDenom() {return denom;}

void Fraction::print() {
    reduce(numer,denom);
    cout << numer << "/" << denom << endl;}
void Fraction:: printUnreduced(){
    cout << numer << "/" << denom << endl;
}
int Fraction::gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
void  Fraction::reduce(int num, int den)
{
    // Finding gcd of both terms
    int common_factor = gcd(num,den );

    // Converting both terms into simpler
    // terms by dividing them by common factor
    denom = den / common_factor;
    numer = num / common_factor;
}
double Fraction::toDouble() const {
    return (double)numer/(double)denom;
}

Fraction Fraction::operator+(const Fraction &obj) {
    Fraction sum;

    int num3 = (numer*obj.denom) + (obj.numer*denom);
    int den3 =  denom*obj.denom;
    sum.setNumer(num3);
    sum.setDenom(den3);
    return sum;
}
Fraction Fraction::operator-(const Fraction &obj) {
    Fraction sub;

    int num3 = (numer*obj.denom) - (obj.numer*denom);
    int den3 =  denom*obj.denom;
    sub.setNumer(num3);
    sub.setDenom(den3);
    return  sub;
}
Fraction Fraction::operator*(const Fraction &obj) {
    Fraction multi;

    int num3 = numer*obj.numer;
    int den3 = denom*obj.denom;
    multi.setNumer(num3);
    multi.setDenom(den3);
    return multi;
}
Fraction Fraction::operator/(const Fraction &obj) {
    Fraction div;

    int num3 = numer*obj.denom;
    int den3 = denom*obj.numer;
    div.setNumer(num3);
    div.setDenom(den3);
    return div;
}
bool Fraction::operator==(const Fraction &obj) {
    return toDouble()== obj.toDouble();
}
bool Fraction::operator<(const Fraction &obj) {
    return toDouble()<obj.toDouble();
}
bool Fraction::operator>(const Fraction &obj) {
    return toDouble()>obj.toDouble();
}
bool Fraction::operator<=(const Fraction &obj) {
    return toDouble()<=obj.toDouble();
}
bool Fraction::operator>=(const Fraction &obj) {
    return toDouble()>=obj.toDouble();
}
ostream& operator<<(ostream& out, Fraction& f){
    f.reduce(f.numer,f.denom);

    out<<f.numer<<"/"<<f.denom<<endl;
    return out;
}
istream & operator>>(istream& in , Fraction& f){
    cout<<"enter your Fraction fully(a/b):";
    in>>f.fracStr;
    stringstream test(f.fracStr);
    stringstream test2(f.split(f.fracStr));

    int numerator=0;
    int denominator = 0;
    test>>numerator;
    test2>>denominator;

    try {
        f.numer = numerator;
        if(denominator==0){throw "cant divide by zero";}
        else f.denom=denominator;
    } catch (const char* e) {
        cout<<"cant divide by zero"<<endl<<"assigning denominator with value = 1"<<endl;
        denominator =1;
    }
    return in;
}
Fraction::~Fraction() {}