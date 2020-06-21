/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: isa31
 *
 * Created on 24 de febrero de 2019, 12:27
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Ellipse.h"
#include <iostream>

using namespace std;

class Circle: public Ellipse{
public:
    Circle(float r1);
    Circle(void);
    virtual ~Circle();
    void setArea(float r1);
    float getArea();
    
private:
    float r1, area;

};

#endif /* CIRCLE_H */


