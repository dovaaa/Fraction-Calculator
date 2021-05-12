#include <iostream>
#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;
FractionCalculator calc;


void Menu() {
    string menu = "Welcome to FCI Fraction Calculator\n"
                  "----------------------------------------\n"
                  "1- Perform Fraction Addition\n"
                  "2- Perform Fraction Subtraction\n"
                  "3- Perform Fraction Multiplication\n"
                  "4- Exit\n";
    cout<<menu;
}
bool input(){
    int choice;
    cin>>choice;
    if(choice == 4) exit(0);
    Fraction inp;
    cin>>inp;
    switch (choice) {
        case 1:
            if(calc.value){
                calc.Ans = calc.Ans + inp;
            }
            else{
                calc.Ans = inp;
                cin>>inp;
                calc.Ans = calc.Ans + inp;
                calc.value = true;
            }
            return true;
        case 2:
            if(calc.value){
                calc.Ans = calc.Ans - inp;
            }
            else{
                calc.Ans = inp;
                cin>>inp;
                calc.Ans = calc.Ans - inp;
                calc.value = true;
            }
            return true;
        case 3:
            if(calc.value){
                calc.Ans = calc.Ans * inp;
            }
            else{
                calc.Ans = inp;
                cin>>inp;
                calc.Ans = calc.Ans * inp;
                calc.value = true;
            }
            return true;
        case 4:
            break;
        default:
            cout<<"wrong input\n";
            return false;
    }
}

int main() {

   Fraction inp;
   while (true){
       Menu();
        if (input()){
            cout<<calc.Ans;
        }

   }



    return 0;
}
