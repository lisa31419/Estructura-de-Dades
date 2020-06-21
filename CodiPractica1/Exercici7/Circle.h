/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 22 de febrero de 2019, 13:08
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Ellipse.h"
#include <iostream>

using namespace std;

class Circle: public Ellipse{
public:
    Circle(float r1); //Contructor de Circle/Ellipse amb parametres
    Circle(void);     // Constructor per defecte de Circle/Ellipse
    virtual ~Circle();// Destructor de Cicle
    
    void setArea(float r1); // Metodes de la classe Circle heredats de Ellipse 
    float getArea();
    
private:
    float r1, area;        // Atributs de la classe Circle

};

#endif /* CIRCLE_H */

