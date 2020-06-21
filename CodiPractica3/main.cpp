/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 26 de abril de 2019, 18:18
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include "NodeTree.h"
#include "BSTMountainFinder.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int opcio, id, num;
    int comptador = 0;
    string text = " ";
    std::fstream fi("cercaMuntanyes.txt");
    
    cout << "******** INICI ********" << endl;
    
    vector<string> menu = { " 1. Inserir un fitxer",
                            " 2. Mostrar arbre",
                            " 3. Cercar muntanyes",
                            " 4. Profunditat de l'arbre", 
                            " 5. Sortir" };
    
    BSTMountainFinder *arbreFinder = new BSTMountainFinder();
    do{
        cout << "******** MENU ********" << endl;
        for(vector<string>::const_iterator it = menu.begin(); it != menu.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';  
        }
        
        cout << "Opcio: ";
        cin >> opcio;
        cout << '\n';
        
        switch(opcio){
            case 1:   
                // Inserir un fitxer
                try{
                    if(arbreFinder->getArbre() == NULL){
                        throw std::invalid_argument("EXCEPTION: Estructura no creada.");
                    }
                     
                    cout << "Quin fitxer vols?" << endl;
                    cout << " 1) Llista petita" << endl;
                    cout << " 2) Llista gran " << endl;
                    cin >> num;

                    if (num == 1) {
                        arbreFinder->appendMountains("Mountain_small");
                        cout << "Fitxer inserit." << endl;
                    } else if (num == 2 ) {
                        arbreFinder->appendMountains("Mountain_list.txt");
                        cout << "Fitxer inserit." << endl;

                    } else {
                        cout << "Opcio incorrecta." << endl;
                    }
                    cout << '\n';
                } catch(std::invalid_argument& e){
                    cout << e.what() << endl;
                    cout << '\n';
                }
                break;
                
            case 2:
                // Mostrar l'arbre de forma creixent
                try{
                    if(arbreFinder->getArbre()->isEmpty()){
                        throw std::invalid_argument("EXCEPTION: Arbre buit.");
                    }
                    cout << "  A R B R E " << endl;
                    arbreFinder->showMountains();
                    
                    cout << '\n';
                } catch(std::invalid_argument e){
                    cout << e.what() << endl;
                    cout << '\n';
                }
                break;
                
            case 3:
                // Cercador de muntanyes
                
                if (fi.is_open()) {
                    while (getline(fi, text)) {
                        
                        id = std::stoi(text);
                        arbreFinder->showMountain(id);
                        if (arbreFinder->searchMountain(id)) {
                            comptador += 1;
                            
                        } else {
                            cout << "No existeix una muntanya amb l'ID " << id << "." << endl;
                        }       
                    }
                    fi.close();
                    cout << "Total de muntanyes trobades: " << comptador << endl;
                } else {
                    cout << "Fitxer incorrecte." << endl;
                }
                
                break;
                
            case 4:
                // Profunditat de l'arbre
                cout << "Profunditat de l'arbre: ";
                arbreFinder->profunditat();
                cout << '\n';
                
                break;
                
            case 5:
                //Sortir
                cout << "******* FI *********" << endl;
                break;
           
            default:
                opcio = 5;
                cout << "******* FI *********" << endl;
                
                break;
      
        }
        
    } while( opcio != 5);
    
    return 0;
}

