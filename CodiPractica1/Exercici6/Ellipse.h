/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 21 de febrero de 2019, 22:45
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <iostream>

using namespace std;

class Ellipse{
public:
    Ellipse(float r1, float r2);
    Ellipse(void);
    virtual ~Ellipse();
    virtual void setArea(float r1,float r2);
    virtual float getArea();
    
protected:
    float r1, r2, area;

};

#endif /* ELLIPSE_H */

