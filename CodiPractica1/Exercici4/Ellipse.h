/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: María Isabel González Sánchez
 *
 * Created on 21 de febrero de 2019, 18:54
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    Ellipse(float r1, float r2);
    Ellipse(void);
    virtual ~Ellipse(void);
    void setArea(float r1,float r2);
    float getArea();
    
private:
    float area,r1,r2;
};


#endif /* ELLIPSE_H */

