/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: María Isabel González Sánchez
 * 
 * Created on 21 de febrero de 2019, 19:56
 */

#include "Ellipse.h"

Ellipse::Ellipse(float r1, float r2) {
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(void) {
    r1 = r1;
    r2 = r2;
}

Ellipse::~Ellipse(void) {
}

void Ellipse::setArea(float radiPetit, float radiGran){
    area = radiPetit*radiGran*3.14f;
  
}
float Ellipse::getArea(){
    return area;
}
