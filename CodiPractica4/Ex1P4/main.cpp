/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 15 de mayo de 2019, 0:06
 */


#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "MaxHeap.h"
#include "NodeHeap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Atributs
    int opcio, clau, element;
    string valor;
    
    // Heap
    MaxHeap<string>* heap = new MaxHeap<string>();
    
    cout << "******** INICI ********" << endl;
    
    vector<string> menu = { " 1. Inserir una entry ",
                            " 2. Mostrar clau màxima",
                            " 3. Mostrar valors màxims", 
                            " 4. Buscar ",
                            " 5. Imprimir", 
                            " 6. Eliminar maxim del heap", 
                            " 7. Eliminar heap",
                            " 8. Sortir" };
    
    
    do {
        
        cout << "******** MENU ********" << endl;
        for(vector<string>::const_iterator it = menu.begin(); it != menu.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';  
        }
        
        cout << "Opcio: ";
        cin >> opcio;
        cout << '\n';
        
        switch(opcio) {
            
            case 1:   
                // Inserir una entry al heap
                try {
                    if (heap == NULL) {
                        throw std::invalid_argument("EXCEPTION: Estructura no creada.");
                    }
                    
                    cout << "Inserta a la entry amb clau ";
                    cin >> clau;
                    cout << "i valor ";
                    cin >> valor;
                    heap->insert(clau, valor);
                    cout << '\n';
                    
                } catch(std::invalid_argument& e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 2:
                // Mostrar clau maxima
                try {
                    if (heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    cout << "-> Clau maxima = ";
                    cout << heap->max() << endl;
                    cout << '\n';
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 3:
                // Mostrar valors de la clau maxima
                try {
                    if (heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    cout << "-> Valors de la clau ";
                    heap->max();
                    cout << ": ";
                    
                    for(vector<string>::const_iterator it = heap->maxValues().begin(); it != heap->maxValues().end(); ++it){
                        cout << *it;
                        cout << '\n';
                    }
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 4:
                // Cercar una entry
                try {
                    if (heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    cout << "Quina clau vols buscar? " << endl;
                    cin >> clau;
                    cout << '\n';
                    
                    if (heap->search(clau) != nullptr) {
                       heap->search(clau)->toString();
                       cout << "*************************" << endl;
                       cout << '\n';
                       
                    } else {
                        cout << "Entry not found. Try another one." << endl;
                        cout << '\n';
                        
                    }
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 5:
                // Imprimir
                try {
                    if (heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap buit.");
                    }
                    
                    cout << "    H E A P   " << endl;
                    heap->printHeap();
                    cout << "*************************" << endl;
                    cout << '\n';
                    
                } catch(std::invalid_argument e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 6:
                // Eliminar maxim del heap
                try {
                    if (heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap totalment eliminat previament o no creat.");
                    }
                    
                    element = heap->max();
                    
                    cout << "Destruïnt maxim del Heap" << endl;
                    heap->removeMax();
                    cout << '\n';
                    
                    cout << "Element eliminat: " << element << endl;
                    cout << '\n';
                    
                } catch(std::invalid_argument& e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 7:
                // Eliminar heap
                try {
                    if(heap->isEmpty()) {
                        throw std::invalid_argument("EXCEPTION: Heap eliminat previament o no creat.");
                    }
                    
                    cout << "Destruïnt  Heap" << endl;
                    cout << '\n';
                    heap->~MaxHeap();
                    cout << '\n';
                    
                    cout << "Heap eliminat." << endl;
                    cout << '\n';
                    
                } catch(std::invalid_argument& e) {
                    cout << e.what() << endl;
                    cout << '\n';
                }
                
                break;
                
            case 8:
                //Sortir
                cout << "******* FI *********" << endl;
                break;
             
            default:
                opcio = 8;
                cout << "******* FI *********" << endl;
                
                break;
      
        }
        
    } while( opcio != 8);
    
    
    return 0;
    
}


