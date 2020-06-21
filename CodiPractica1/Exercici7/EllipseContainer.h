/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 22 de febrero de 2019, 13:11
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H
#include <vector>
#include "Ellipse.h"

class EllipseContainer {
public:
    EllipseContainer(vector<Ellipse*> v); // Constructor amb parametres 
    EllipseContainer(void);               // Constructor per defecte
    virtual ~EllipseContainer();          // Destructor de la classe
    
    void addEllipse(Ellipse *e);          // Metodes de la clase amb visibilitat 
    float getAreas();                     // publica
     
private:
    Ellipse *e;                           // Atributs de la classe
    vector<Ellipse*> v;
   

};

#endif /* ELLIPSECONTAINER_H */

