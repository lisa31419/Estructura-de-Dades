/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 * 
 * Created on 21 de febrero de 2019, 22:45
 */

#include "Ellipse.h"
#include <iostream>

using namespace std;

Ellipse::Ellipse(float r1, float r2) {
    this->r1 = r1;
    this->r2 = r2;
    std::cout << "Soc el constructor d'Ellipse" << '\n';
}

Ellipse::Ellipse(void) {
    r1 = 0;
    r2 = 0;
    std::cout << "Soc el constructor d'Ellipse" << '\n';

}

Ellipse::~Ellipse() {
    std::cout << "Soc el destructor d'Ellipse" << '\n';
}

void Ellipse::setArea(float r1, float r2){
    area = r1*r2*3.14f;
  
}
float Ellipse::getArea(){
    return area;
}