/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 * 
 * Created on 17 de mayo de 2019, 11:20
 */

#include "Mountain.h"

// CONSTRUCTORS I DESTRUCTOR

// Constructor amb parametres 
Mountain::Mountain(int ID,string nom, int h){
    this->mountainID = ID;
    this->name = nom;
    this->altura = h;
}

// Constructor 
Mountain::Mountain() {
    
}

// Destructor
Mountain::~Mountain(){
    
}
    

// FUNCIONS CONSULTORES

//  Metode per saber l'identificacio d'una Mountain
const int Mountain::getMountainID() const { 
    return this->mountainID;
}

// Metode per saber el nom d'una Mountain
const string Mountain::getName() const {
    return this->name;
}

// Metode per saber l'alcada d'una Mountain
const int Mountain::getHeight() const {
    return this->altura;
}
    

// FUNCIONS MODIFICADORES

// Metode per canviar l'identificacio d'una Mountain
void Mountain::setMountainID(int newID){
    this->mountainID = newID;
}

// Metode per canviar el nom d'una Mountain
void Mountain::setName(string newName){
    this->name = newName;
}

// Metode per canviar l'alcada d'una Mountain
void Mountain::setHeight(int newHeight){
    this->altura = newHeight;
}
    

// IMPRIMIR

string Mountain::toString(){
    string missatge = "Mountain " + this->name + ":" + '\n';
    missatge += " -> ID: " + this->mountainID + '\n';
    missatge += " -> Height: " + this->altura + '\n';
    return missatge;
}

