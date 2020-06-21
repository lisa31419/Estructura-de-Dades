/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: María Isabel González Sánchez
 *
 * Created on 19 de febrero de 2019, 11:52
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    
public:
    void setArea(double radi);
    double getArea();
    Circle(double radi);
    Circle(void);
    ~Circle(void);
    
private:
    double radi;
    double area;

};

#endif /* CIRCLE_H */

