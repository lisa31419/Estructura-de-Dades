/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 26 de abril de 2019, 18:19
 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <string>

using namespace std;

class Mountain {
public:
    // CONSTRUCTOR I DESTRUCTOR
    Mountain(int mountainID, string name, int height);
    Mountain();
    virtual ~Mountain();
    
    // FUNCIONS CONSULTORES
    const int getMountainID() const;
    const string getName() const;
    const int getHeight() const;
    
    // FUNCIONS MODIFICADORES
    void setMountainID(int newID);
    void setName(string newName);
    void setHeight(int newHeight);
    
    // IMPRIMIR
    string toString();
    
private:
    int mountainID;
    int altura;
    string name;
};

#endif /* MOUNTAIN_H */

