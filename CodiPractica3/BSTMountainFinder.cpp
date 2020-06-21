/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 * 
 * Created on 26 de abril de 2019, 18:19
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include "BSTMountainFinder.h"
#include "Mountain.h"
#include "BST.h"


using namespace std;

// CONSTRUCTORS I DESTRUCTOR

/* Constructor per defecte */
BSTMountainFinder::BSTMountainFinder() {
    this->arbre = new BST<Mountain>();
}

/* Constrcutor copia */
BSTMountainFinder::BSTMountainFinder(const BSTMountainFinder& orig) {
    
}

/* Destructor */
BSTMountainFinder::~BSTMountainFinder() {
    
}


// CONSULTORS

// Metode per trobar una muntaya de l'arbre mitjançant l'ID (versio del search de BST)
NodeTree<Mountain>* BSTMountainFinder::findMountain(int mountainID){
    bool trobat = false;
    bool endGame = false;
    NodeTree<Mountain>* aux = arbre->root();

    while(!trobat && !endGame){
        // Si les muntanyes coincideixen
        if (aux->getKey() == mountainID){
            trobat = true;
            
        }
        // Si la mountainID es mayor que el elemento a comparar
        else if (aux->getKey() < mountainID) {
            if (aux->isExternal()){
                endGame = true;
            }
            else {
                aux = aux->right();
            }
        }
        // Si el node es menor que el elemento a comparar
        else {
            if (aux->isExternal()) {
                endGame = true;
            }
            else {
                aux = aux->left();
            }
        }
    }
    return aux;
    
}

// Metode per saber si una muntanya hi es a l'arbre (versio del search de BST)
bool BSTMountainFinder::searchMountain(int mountainID){
    bool trobat = false;
    bool endGame = false;
    NodeTree<Mountain>* aux = arbre->root();

    while(!trobat && !endGame){
        // Si les muntanyes coincideixen
        if (aux->getKey() == mountainID){
            trobat = true;
            return trobat;
            
        } else if (aux->getKey() < mountainID) {
            // Si la mountainID es mayor que el elemento a comparar
            if (aux->isExternal()){
                endGame = true;
            }
            else {
                aux = aux->right();
            }
        } else { 
            // Si el node es menor que el elemento a comparar
            if (aux->isExternal()) {
                endGame = true;
            }
            else {
                aux = aux->left();
            }
        }
    }
    
}

// Metode per mostrar per pantalla una muntanya 
void BSTMountainFinder::showMountain(int mountainID){
    cout << "Mountain " << mountainID << ":" << endl;
    cout << "  Name: ";
    cout << findMountain(mountainID)->getValue().getName() << endl;
    cout << "  Height: ";
    cout << findMountain(mountainID)->getValue().getHeight() << endl; 

    
}

// Metodes per mostrar per pantalla totes les muntanyes en ordre creixent
void BSTMountainFinder::showMountains(){
    showInOrder(arbre->root());   
}

void BSTMountainFinder::showInOrder(NodeTree<Mountain>* p) {
    int resposta,id, altura;
    string name;
    
    if (!p->isExternal() && p->left() != 0) {
        showInOrder(p->left());
    }
    
    id = p->getValue().getMountainID();
    name = p->getValue().getName();
    altura = p->getValue().getHeight();
    toString(id, name, altura);
    
    if (!p->isExternal() && p->right() != 0) {
        showInOrder(p->right());
    }
    
}

// Metode per saber la profunditat d'un arbre
void BSTMountainFinder::profunditat() {
    cout << arbre->height() << endl;
}

// Metode que retorna l'arbre
BST<Mountain>* BSTMountainFinder::getArbre() {
    return this->arbre;
}

// Metode per imprimir per pantalla
void BSTMountainFinder::toString(int id, std::string nom, int altura) {
    cout << "Mountain " << id << endl;
    cout << " Name: " << nom << endl;
    cout << " Height: " << altura << endl;
    cout << "\n";
}


// MODIFICADORS

// Metode per treure l'informacio de les muntanyes d'un fitxer 
void BSTMountainFinder::appendMountains(const string filename){
    int mountainID, altura;
    string name, text;
    string aux;
    
    ifstream file(filename);
    // Comprobem que el fitxer esta obert
    if (file.is_open()) {
        while (getline(file, text)) {
            aux = text;
            // Conseguim l'ID de la muntanya
            mountainID = stoi(text.substr(0, text.find(":")));
            text = text.substr(text.find(":") + 2, text.length());           
            
            // Ara el nom
            name = text.substr(0, text.find(":"));
            text = text.substr(text.find(":") + 2, text.length());
            
            // I per ultim l'alçada de la muntanya
            //altura = stoi(text.substr(0, text.find(":")));
            altura = stoi(text);
            
            // Insertem la muntanya
            insertMountain(mountainID, name, altura);
               
        }
        file.close();
    } else {
        cout << "Fitxer incorrecte" << endl;
    }      
}

// Metode per crear e inserir muntanyes a l'arbre
void BSTMountainFinder::insertMountain(int mountainID, const std::string name, int height) {
    Mountain m;
    m.setMountainID(mountainID);
    m.setName(name);
    m.setHeight(height);
    arbre->insert(m, mountainID);
}

