/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: María Isabel González Sánchez
 *
 * Created on 19 de febrero de 2019, 10:45
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Circle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    int comptador = 1;
    double radi,area;
    Circle c;
    std::vector<string> arr_options {" 1.Sortir", " 2.Introduir cercle"};
    cout << "******* INICI *******" << endl;
    cout <<"Hola, que vols fer?"<<endl;
    
    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }  
        cin >> num;
        switch(num){
            case 1:
                num = 0;
                cout << "****** FI *******" << endl;
                break;
            case 2:
                try{
                    cout << '\n';
                    cout << "Cercle numero " << comptador << endl;
                    cout << "Radi?" << endl;
                    cin >> radi;
                    if( radi <= 0.0){
                        throw std::invalid_argument("Atenció: aquest valor no és acceptat");
                    }
                    c.setArea(radi);
                    area = c.getArea();
                    cout << "L'area d'aquest cercle es de: " << area << endl;
                    cout << '\n';
                    comptador++;
                }
                catch(std::invalid_argument& e ) {
                    cout << e.what() << endl;
                    cout << "S’ha produït una excepció" << endl;
                }
                
                break;
            default:
                cout << "****** FI *******" << endl;
                
                break;  
        }
    }while(num != 0);
  
    return 0;
}


