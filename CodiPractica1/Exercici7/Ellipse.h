/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: María Isabel González Sánchez
 *
 * Created on 22 de febrero de 2019, 0:09
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <iostream>

using namespace std;

class Ellipse{
public:
    Ellipse(float r1, float r2);     // Constructor amb parametres de Ellipse
    Ellipse(void);                   // Constructor per defecte de Ellipse
    virtual ~Ellipse();              // Destructor de Ellipse
    
    virtual void setArea(float r1,float r2); // Metodes de la classe Ellipse amb
    virtual float getArea();                 // virtual que modificarem a la clase
                                             // derivada Circle
    
protected:
    float r1, r2, area;              // Atributs de la classe Ellipse

};

#endif /* ELLIPSE_H */

