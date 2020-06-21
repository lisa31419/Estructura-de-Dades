/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMountainFinder.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 * 
 * Created on 17 de mayo de 2019, 10:55
 */


#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include "Mountain.h"
#include "MaxHeap.h"
#include "HeapMountainFinder.h"

using namespace std;

// CONSTRUCTORS I DESTRUCTOR

/* Constructor per defecte */
HeapMountainFinder::HeapMountainFinder() {
    this->heap = new MaxHeap<Mountain>();
}

/* Constrcutor copia */
HeapMountainFinder::HeapMountainFinder(const HeapMountainFinder& orig) {
    
}

/* Destructor */
HeapMountainFinder::~HeapMountainFinder() {
    
}


// CONSULTORS

/* Metode per trobar una muntaya de l'arbre mitjançant l'ID (versio del search de BST)
 * @param int mountainID
 * @return NodeHeap<Mountain>*
 */
NodeHeap<Mountain>* HeapMountainFinder::findMountain(int mountainID) {
    NodeHeap<Mountain>* aux = nullptr;
    bool trobat = false;

    if (heap->search(mountainID) != nullptr) {
        trobat = true;
        aux = heap->search(mountainID);
    } 

    return aux; 
    
}

/*
 * Metode per saber si una muntanya hi es a l'arbre (versio del search de BST)
 * @param int mountainID
 * @return True, False
 */ 
bool HeapMountainFinder::searchMountain(int mountainID) {
    NodeHeap<Mountain>* aux = nullptr;
    bool trobat = false;

    if ( heap->search(mountainID) != nullptr) {
        trobat = true;
    } 

    return trobat; 
    
}

/*
 *  Metode per mostrar per pantalla una muntanya 
 * @param int mountainID
 */
void HeapMountainFinder::showMountain(int mountainID) { 
    cout << "Mountain " << mountainID << ": " << endl;
    cout << " -> Name: " << findMountain(mountainID)->getValues().at(0).getName() << endl;
    cout << " -> Height: " << findMountain(mountainID)->getValues().at(0).getHeight() << endl;
    cout << '\n';  
    
}

// Metodes per mostrar per pantalla totes les muntanyes en ordre creixent
void HeapMountainFinder::showMountains() {
    int comptador = 0;
    int pos = heap->max();
    bool stop = false;
    
    showInOrder(&pos, &comptador, &stop);   
    
}

/*
 * Metode auxiliar de showMountains()
 * @param int* posicio, int* comptador, bool* stop
 */
void HeapMountainFinder::showInOrder(int* pos, int* comptador, bool* stop) {
    /* Atributs */
    int resposta,id, altura;
    string name;
 
    if (*comptador == 40) {
        
        cout << "Vols continuar mostrant les muntanyes?" << endl;
        cout << " 1) Si" << endl;
        cout << " 2) No" << endl;
        cin >> resposta;
        
        if(resposta == 1) {
            *comptador = 0;
            
        } else if (resposta == 2) {
            *stop = true;
            *comptador = -1;
            
            cout <<  "*********  E N D  ********" << endl;
            
        } else {
            cout << " Resposta incorrecta." << endl;           
            cout <<  "*********  E N D  ********" << endl;
            
            *stop = true;
            *comptador = -1;
            
        }

    } 
    
    if (!*stop ) {
        
        NodeHeap<Mountain>* p = heap->search((*pos));
        
        if (*pos != 0) {
            
            id = p->getKey();
            name = p->getValues().at(0).getName();
            altura = p->getValues().at(0).getHeight();
            
            cout << "*******************" << endl;
            toString(id, name, altura);
            cout << "*******************" << endl;
            
            (*comptador) += 1;
            (*pos) -= 1;
            
            return showInOrder(pos, comptador, stop);
             
        } else {
            *stop = true;
            
        }
         
    }    

}

// Metode que mostra la profunditat del Heap
void HeapMountainFinder::profunditat() {
    int numNodes = heap->size();
    int i = 0;
    
    while (pow(2,i) < numNodes) {
        i += 1;
    }
    
    cout << " -> Profunditat: " << i << endl;
    
}

// Metode que retorna l'arbre
MaxHeap<Mountain>* HeapMountainFinder::getHeap() {
    return this->heap;
    
}

/* Metode per imprimir per pantalla
 * @param int mountainID, string name, int height
 */
void HeapMountainFinder::toString(int id, std::string nom, int altura) {
    cout << "Mountain " << id << endl;
    cout << " -> Name: " << nom << endl;
    cout << " -> Height: " << altura << endl;
    cout << "\n";
    
}


// MODIFICADORS

/* Metode per treure l'informacio de les muntanyes d'un fitxer 
 * @param string filename
 */ 
void HeapMountainFinder::appendMountains(const string filename){
    /* Atributs */
    int mountainID, altura;
    string name;
    string text = " ";
    string aux;
    
    fstream file(filename);
    
    // Comprobem que el fitxer esta obert
    if (file.is_open()) {
        // Per cada fila...
        while (getline(file, text)) {
            
            aux = text;
            // Conseguim l'ID de la muntanya
            mountainID = stoi(text.substr(0, text.find(":")));
            text = text.substr(text.find(":") + 2, text.length());           
            
            // Ara el nom
            name = text.substr(0, text.find(":"));
            text = text.substr(text.find(":") + 2, text.length());
           
            // I per ultim l'alçada de la muntanya
            altura = stoi(text);
            
            // Insertem la muntanya
            insertMountain(mountainID, name, altura);
               
        }
        
        file.close();
        
    } else {
        cout << "Fitxer incorrecte" << endl;
        
    }   
    
}

/* Metode per crear e inserir muntanyes a l'arbre
 * @param int mountainID, string name, int height
 */ 
void HeapMountainFinder::insertMountain(int mountainID, const std::string name, int height) {
    Mountain *m = new Mountain(mountainID,name,height);
    heap->insert(mountainID, *m);
    
}



