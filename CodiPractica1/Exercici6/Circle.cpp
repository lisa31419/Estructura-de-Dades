/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: Maria Isabel Gonzalez Sanchez
 * 
 * Created on 21 de febrero de 2019, 22:55
 */

#include "Circle.h"
#include "Ellipse.h"
#include <stdexcept>
#include <iostream>

using namespace std;


Circle::Circle(float r1):Ellipse(r1, r2) {
    this->r1 = r1;
    std::cout << "Soc el constructor de Circle/Ellipse" << '\n';
}

Circle::Circle(void){
    r1 = 0;
    std::cout << "Soc el constructor de Circle/Ellipse" << '\n';
}

Circle::~Circle() {
    std::cout << "Soc el constructor de Circle" << '\n';
}

void Circle::setArea(float r1){
    Ellipse::setArea(r1, r1);
  
}
float Circle::getArea(){
    return Ellipse::getArea();
}