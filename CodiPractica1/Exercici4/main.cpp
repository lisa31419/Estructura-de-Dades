/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: María Isabel González Sánchez
 *
 * Created on 21 de febrero de 2019, 18:39
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Ellipse.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    char tipus;
    int comptadorC = 0, comptadorE = 0;
    float r1, r2, area;
    Ellipse e;
    std::vector<string> arr_options {" 1.Sortir", " 2.Afegir figura", " 3.Glosari de figures"};
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
                cout << "\nEntra les dades de la teva figura ( tipus[C o E] data1 data2[buit si el tipus es C] ): " << endl;
                cin >> tipus;
                if (tipus == 'C'){
                    cin >> r1;
                    try{
                        if( r1 <= 0.0){
                            throw std::invalid_argument("Atenció: aquest valor no és acceptat");
                        }
                        e.setArea(r1,r1);
                        area = e.getArea();
                        cout << "L'area d'aquest cercle es de: " << area << endl;
                        cout << '\n';
                        comptadorC++;
                    }
                    catch(std::invalid_argument& e ) {
                    cout << e.what() << endl;
                    cout << "S’ha produït una excepció." << endl;
                    cout << '\n';
                    }
                }
                else if(tipus == 'E'){
                    cin >> r1 >> r2;
                    try{
                        if( r1 <= 0.0 || r2 <= 0.0){
                            throw std::invalid_argument("Atenció: aquest valor no és acceptat");
                        }
                        e.setArea(r1,r2);
                        area = e.getArea();
                        cout << "L'area d'aquesta el·lipse es de: " << area << endl;
                        cout << '\n';
                        comptadorE++;
                    }
                    catch(std::invalid_argument& e ) {
                        cout << e.what() << endl;
                        cout << "S’ha produït una excepció." << endl;
                        cout << '\n';
                    }
                }
                else{
                    cout << "Invalid sintax. " << endl;
                }
                
                break;
            case 3:
                cout << "Tens " << comptadorC << " cercles i " << comptadorE << " el·lipses." << endl;
                break;
                        
            default:
                cout << "****** FI *******" << endl;
                break;  
        }
    }while(num != 0);
  

    return 0;
}

