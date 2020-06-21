/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMountainFinder.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 17 de mayo de 2019, 10:55
 */

#ifndef HEAPMOUNTAINFINDER_H
#define HEAPMOUNTAINFINDER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "MaxHeap.h"
#include "Mountain.h"

using namespace std;

class HeapMountainFinder {
public:
    // Constructors i destructor
    HeapMountainFinder();
    HeapMountainFinder(const HeapMountainFinder& orig);
    virtual ~HeapMountainFinder();
    
    // Consultors
    bool searchMountain(int mountainID);
    void profunditat();
    NodeHeap<Mountain>* findMountain(const int mountainID);
    MaxHeap<Mountain>* getHeap();
    
    // Imprimir
    void showMountain(const int mountainID);
    void showMountains();
    void showInOrder(int* pos, int* comptador, bool* stop);
    void toString(int id, std::string nom, int altura);
    
    // Modificadors
    void appendMountains(const std::string filename);
    void insertMountain(const int mountainID, const string name, const int height);

private:
    MaxHeap<Mountain>* heap; 
    
};
#endif /* HEAPMOUNTAINFINDER_H */

