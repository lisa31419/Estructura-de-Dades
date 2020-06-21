/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 22 de febrero de 2019, 0:09
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "Ellipse.h"
#include "EllipseContainer.h"

using namespace std;

/*
 * 
 */
void llegirFitxer(int &comptadorE, int &comptadorC){
    ifstream fitxer("figures.txt"); 
    char tipus;
    float r1, r2, area;
    while (!fitxer.eof()) { 
        fitxer >> tipus; 
        fitxer >> r1; 
        switch(tipus) {
            case 'C':
            {
                Ellipse e;
                e.setArea(r1, r1);
                area = e.getArea();
                cout << "L'area d'aquest cercle es de " << area << endl;
                comptadorC++;
                break;
            }
            case 'E': 
            {
                fitxer >> r2;
                Ellipse e;
                e.setArea(r1, r2);
                area = e.getArea();
                cout << "L'area d'aquesta el·lipse es de " << area << endl;
                comptadorE++;
                break;
            }
            
        }
    }
    fitxer.close();
}


int main(int argc, char** argv) {
    char tipus;
    float r1, r2, area;
    int num, comptadorC = 0, comptadorE = 0;
    Ellipse e;
    EllipseContainer elip;
    std::vector<EllipseContainer> v[10];
    std::vector<string> arr_options {" 1.Sortir", " 2.Afegir figura", " 3.Glosari de figures",
                                     " 4.Llegir fitxer", " 5.Area total"};
    
    cout << "******* INICI *******" << endl;
    
    do{
        cout << "Hola, que vols fer?" << endl;
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
                cin >> tipus >> r1;
                switch(tipus){
                    case 'C':
                        try{
                            if( r1 <= 0.0){
                                throw std::invalid_argument("Atenció: aquest valor no és acceptat");
                            }
                            Ellipse(r1,r1);
                            e.setArea(r1,r1);
                            area = e.getArea();
                            cout << "L'area d'aquest cercle es de: " << area << endl;
                            cout << '\n';
                            Ellipse *e = new Ellipse(r1, r1);
                            elip.addEllipse(e);
                            comptadorC++;
                        }
                        catch(std::invalid_argument& e ) {
                            cout << e.what() << endl;
                            cout << "S’ha produït una excepció." << endl;
                            cout << '\n';
                        }
                        break;  
                
                    case 'E':
                        cin >> r2;
                        try{
                            if( r1 <= 0.0 || r2 <= 0.0){
                               throw std::invalid_argument("Atenció: aquest valor no és acceptat");
                            }
                            Ellipse e(r1,r2);
                            e.setArea(r1,r2);
                            area = e.getArea();
                            cout << "L'area d'aquesta el·lipse es de: " << area << endl;
                            cout << '\n';
                            elip.addEllipse(&e);
                            comptadorE++;
                        }
                        catch(std::invalid_argument& e ) {
                            cout << e.what() << endl;
                            cout << "S’ha produït una excepció." << endl;
                            cout << '\n';
                        }
                        break; 
                        
                    default:
                        break;
                }
                break;
                
            case 3:
                cout << "Tens " << comptadorC << " cercles i " << comptadorE << " el·lipses." << endl;
                break;
                
            case 4:
                llegirFitxer(comptadorC, comptadorE);
                break; 
                
            case 5:
                cout << elip.getAreas() << endl;
                break;
            default:
                num = 0;
                cout << "****** FI *******" << endl;
                break;  
            }
            
        
    }while(num != 0);
      
    return 0;
}




/* A) Pasar una serie de atributos y metodos comunes de una clase base a una clase
 *    hija para poder implementarlos junto con los propios de la clase hija.
 * B) El área sería igual para todas las clases hija y no abria ninguna diferencia
 *    entre las distintas figuras.
 * C) Porque, al heredan de las clases base, primero imcicalizamos los constructores
 *    y destructores de las clases hija y a continuacion, los de la clase base.
 * D) No, por eso usamos un virtual.
 * E) En los comentarios.
 * F) 1, porque le decimos que aumente en unn unidad el contador de cada tipo de figura
 *    para que pueda recorrerlas.
 */

