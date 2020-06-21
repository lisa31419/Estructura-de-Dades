/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: isa31
 * 
 * Created on 22 de febrero de 2019, 13:11
 */

#include "EllipseContainer.h"
#include "Circle.h"
#include "Ellipse.h"
#include <iostream>
#include <vector>

using namespace std;

EllipseContainer::EllipseContainer(vector<Ellipse*> vtemp) {
    this->v = vtemp;
}

EllipseContainer::EllipseContainer(void) {
    
}

EllipseContainer::~EllipseContainer() {
    std::cout << "Soc el destructor de EllipseContainer" << '\n';
    for(int i = 0; i < this->v.size(); i++){
        if(dynamic_cast<Circle*>(v[i])){
            delete (Circle*)(v[i]);
        }     
    }
}

void EllipseContainer::addEllipse(Ellipse *e){
    if(this->v.size() < 10){
        this->v.push_back(e);
    }
    else{
        cout << "Maxim de figures assolit." << endl;
    }
}

float EllipseContainer::getAreas(){
    float areaFinal = 0.0;
    for(int i = 0; i < this->v.size(); i++){
        areaFinal += v[i]->getArea();
    }
    return areaFinal;
}