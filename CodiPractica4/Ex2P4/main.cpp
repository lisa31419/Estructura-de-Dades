/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: isa31
 *
 * Created on 17 de mayo de 2019, 10:53
 */

/*
 *  TAULA EXERCICI 3
 * ---------------------------------------------------------------------------------------
 *                          |        PRIMER INTENT         |        SEGON INTENT          |
 * ---------------------------------------------------------------------------------------
 *  Inserció Fitxer SMALL   | 16 clicks and 0.016 seconds  | 0 clicks and 0.000 seconds   |
 * ---------------------------------------------------------------------------------------
 *  Inserció Fitxer LLARG   | 31 clicks and 0.031 seconds  | 18 clicks and 0.018 seconds  |
 * ---------------------------------------------------------------------------------------
 *  Cerca Fitxer SMALL      | 218 clicks and 0.218 seconds | 202 clicks and 0.202 seconds |
 * ---------------------------------------------------------------------------------------
 *  Cerca Fitxer LLARG      | 859 clicks and 0.859 seconds | 609 clicks and 0.609 seconds |
 * ---------------------------------------------------------------------------------------
 * 
 * Cost computacional d'inserir:  O(1) en el millor de los casos (el heap es buit), O(n) en el pitjor (hem de trobar la posicio corresponent)
 * Cost computacional de cercar:  O(1) si la entry que necessitem es la primera, O(n) si hem de recorre tot el vector per trobar la entry
 * 
 */


#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>
#include "MaxHeap.h"
#include "NodeHeap.h"
#include "HeapMountainFinder.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Atributs
    int opcio, id, num;
    int comptador = 0;
    string text = " ";
    clock_t time;
    
    fstream cerca("cercaMuntanyes.txt");
    
    // Heap Mountain Finder
    HeapMountainFinder* heap = new HeapMountainFinder();
    
    cout << "******** INICI ********" << endl;
    
    vector<string> menu = { " 1. Inserir un fitxer ",
                            " 2. Mostrar heap",
                            " 3. Cercar ",
                            " 4. Profunditat", 
                            " 5. Sortir" };
    
    
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
                // Inserir un fitxer al heap
                try {
                    
                    if (heap->getHeap()->size() == -1){
                        throw std::invalid_argument("EXCEPTION: Estructura no creada.");
                    }
                    
                    time = clock(); 
                    cout << "Quin fitxer vols?" << endl;
                    cout << " 1) Llista petita" << endl;
                    cout << " 2) Llista gran " << endl;
                    cin >> num;

                    if (num == 1) {
                        
                        heap->appendMountains("Mountain_small_list.txt");
                        
                    } else if (num == 2 ) {
                        heap->appendMountains("Mountain_list.txt");   

                    } else {
                        cout << "Opcio incorrecta." << endl;
                    }
                    
                    time = clock() - time;
                    cout << "Fitxer inserit." << endl;
                    cout<<"It took " << time << " clicks and " << (float)time/CLOCKS_PER_SEC << " seconds " << endl;
                    cout << '\n';
                    
                } catch(std::invalid_argument& e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 2:
                // Mostrar el heap en ordre decreixent de Keys
                try {
                    
                    if (heap->getHeap()->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    cout << "  H E A P  " << endl;
                    heap->showMountains();
                    cout << '\n';
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 3:
                // Cercador de muntanyes
                time = clock();
                if (cerca.is_open()) {
                    
                    while (getline(cerca, text)) {
                        
                        id = stoi(text);
                        
                        if (heap->searchMountain(id) != false) {
                            comptador += 1;
                            heap->showMountain(id);
                            cout << '\n';

                        } else {
                            cout << "No existeix una muntanya amb l'ID " << id << "." << endl;
                            cout << '\n';
                            
                        }  
                        
                    }
                    
                    cerca.close();
                    
                    cout << "Total de muntanyes trobades: " << comptador << endl;
                    time = clock() - time;
                    cout<<"It took " << time << " clicks and " << (float)time/CLOCKS_PER_SEC << " seconds " << endl;

                } else {
                    cout << "EXCEPTION: Fitxer incorrecte." << endl;
                    
                }
                    
                break;
                
            case 4:
                // Profunditat del heap
                try {
                    
                    if(heap->getHeap()->isEmpty()){
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    heap->profunditat();
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
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
    
    delete heap;
    
    return 0;
    
}

