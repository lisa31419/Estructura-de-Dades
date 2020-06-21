/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: María Isabel González Sánchez
 * 
 * Created on 19 de febrero de 2019, 11:52
 */

#include "Circle.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

Circle::Circle(double radio){
    this->radi = radio;    
}

Circle::Circle(void) {
    radi = radi;
}

Circle::~Circle(void) {
    
}

void Circle::setArea(double radi){
    area = radi*radi*3.14;
  
}
double Circle::getArea(){
    return area;
}

