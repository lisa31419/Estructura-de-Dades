/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 26 de abril de 2019, 18:19
 */

#ifndef BSTMOUNTAINFINDER_H
#define BSTMOUNTAINFINDER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Mountain.h"

using namespace std;

class BSTMountainFinder {
public:
    BSTMountainFinder();
    BSTMountainFinder(const BSTMountainFinder& orig);
    virtual ~BSTMountainFinder();
    
    // Consultors
    void showMountain(const int mountainID);
    void showMountains();
    void showInOrder(NodeTree<Mountain>* p);
    NodeTree<Mountain>* findMountain(const int mountainID);
    bool searchMountain(int mountainID);
    void profunditat();
    BST<Mountain>* getArbre();
    void toString(int id, std::string nom, int altura);
    
    // Modificadors
    void appendMountains(const std::string filename);
    void insertMountain(const int mountainID, const string name, const int height);

private:
    BST<Mountain>* arbre; 

};

#endif /* BSTMOUNTAINFINDER_H */

