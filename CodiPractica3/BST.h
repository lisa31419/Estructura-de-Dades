/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 26 de abril de 2019, 18:19
 */

#ifndef BST_H
#define BST_H

#include <stdexcept>
#include <iostream>
#include "BSTMountainFinder.h"
#include "NodeTree.h"

using namespace std;

template <class Type>
class BST {
public:
    //Constructor i destructor
    BST();
    BST(const BST& orig);
    virtual ~BST();
    void deleteTree(NodeTree<Type>* p) const;
    
    // Consultors
    int size() const;
    int height() const;
    bool isEmpty() const;
    NodeTree<Type>* root() const;
    
    bool search(const Type& element);
    void showInorder() const;
    void showPreorder() const;
    void showPostorder() const;
    void showLeafNodes() const;
    
    
    
    // Modificadors
    void insert(const Type& element, int id);
    
    
    
private:
    int size(NodeTree<Type>* p) const;
    int height(NodeTree<Type>* p) const;
    void showPreorder(NodeTree<Type>* p) const;
    void showPostorder(NodeTree<Type>* p) const;
    void showInorder(NodeTree<Type>* p) const;
    void showLeafNodes(NodeTree<Type>* p) const;
    
    NodeTree<Type>* pRoot;
    NodeTree<Type>* aux;
    

};


// CONSTRUCTORS
/* Constructor per defecte */
template <class Type>
BST<Type>::BST(){
    this->pRoot = 0;
    this->aux = 0;
    
    
}

/* Constructor copia */
template <class Type>
BST<Type>::BST(const BST& orig){
    this->pRoot = orig->root();
}

// DESTRUCTOR
template <class Type> 
BST<Type>::~BST(){
    deleteTree(pRoot);
    
}

template <class Type>
void BST<Type>::deleteTree(NodeTree<Type>* p) const {
    if(p == NULL) return;
    
    deleteTree(p->left());
    deleteTree(p->right());
    
    cout << "Eliminant node: " << p << endl;
    delete p;
}

// CONSULTORS

// Size de l'arbre
template <class Type>
int BST<Type>::size() const {
    if (pRoot == 0) {
        return 0;
    } 
    else {
        return size(this->pRoot);
    }
}

template <class Type>
int BST<Type>::size(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        return 1;
    }
    else if (p->right() != 0) {
        return size(p->right()) + 1;
    } 
    else if (p->left() != 0) {
        return size(p->left()) + 1;
    } 
    else{
        return size(p->right()) + size(p->left()) + 1;
    }
}


// Altura de l'arbre
template <class Type>
int BST<Type>::height() const {
    if (pRoot == 0){
        return 0;
    } 
    else {
        return height(this->pRoot);
    }
    
}

template <class Type>
int BST<Type>::height(NodeTree<Type>* p) const {
    if (p->isExternal()) {
        return 0;
    }
    else if (p->right() == 0) {
        return height(p->left()) + 1;
    }
    else if (p->left() == 0) {
        return height(p->right()) + 1;
    }
    else {
        return max(height(p->right()), height(p->left()))+ 1;
    }
    
}


// Retorna True si l'arbre es buit, False altrament 
template <class Type>
bool BST<Type>::isEmpty() const {
    return size() == 0;
}

// Retorna l'adreça de l'arrel
template <class Type>
NodeTree<Type>* BST<Type>::root() const {
    if (isEmpty()) {
        throw new invalid_argument("Arbre buit.");
    }
    else {
        return this->pRoot;
    }
   
}

// Retorna True si la muntanya hi es a l'arbre, False altrament
template <class Type>
bool BST<Type>::search(const Type& node){
    bool trobat = false;
    bool endGame = false;
    NodeTree<Type>* aux = this->pRoot;
    
    while(!trobat && !endGame){
        // Si les muntanyes coincideixen
        if (aux->getValue() == node){
            trobat = true;
        }
        // Si el node es mayor que el elemento a comparar
        else if (aux->getValue() < node) {
            if (aux->right() != 0){
                endGame = true;
            }
            else {
                aux = aux->right();
            }
        }
        // Si el node es menor que el elemento a comparar
        else {
            if (aux->left() != 0) {
                endGame = true;
            }
            else {
                aux = aux->left();
            }
        }
    }
    return trobat;
}

// Imprimeix per pantalla els NodeTree en IN-ORDRE
template <class Type>
void BST<Type>::showInorder() const{
    if(isEmpty()){
        throw new invalid_argument("Arbre buit.");
    }
    else {
        this->showInorder(this->pRoot);
    }
    
}

template <class Type>
void BST<Type>::showInorder(NodeTree<Type>* p) const{
    if (!p->isExternal() && p->left() != 0) {
        showInorder(p->left());
    }
    
    cout << p->getKey() << " " ;
    
    if (!p->isExternal() && p->right() != 0) {
       showInorder(p->right());
    }
    
}

// Imprimeix per pantalla els NodeTree en PRE-ORDRE
template <class Type>
void BST<Type>::showPreorder() const{
    if(isEmpty()){
        throw new invalid_argument("Arbre buit.");
    }
    else {
        this->showPreorder(this->pRoot);
    }
    
}

template <class Type>
void BST<Type>::showPreorder(NodeTree<Type>* p) const{
    cout << p->getKey() << " " ;
    if (!p->isExternal()) {
        if (p->left() != 0) {
            showPreorder(p->left());
        }
        if (p->right() != 0){
            showPreorder(p->right());
        }
    }
    
}

// Imprimeix per pantalla els NodeTree en POST-ORDRE
template <class Type>
void BST<Type>::showPostorder() const{
    if(isEmpty()){
        throw new invalid_argument("Arbre buit.");
    }
    else {
        this->showPostorder(this->pRoot);
    }
    
}

template <class Type>
void BST<Type>::showPostorder(NodeTree<Type>* p) const{
    if (!p->isExternal()) {
        if (p->left() != 0) {
            showPostorder(p->left());
        }
        if (p->right() != 0) {
            showPostorder(p->right());
        }
    }
    
    cout << p->getKey() << " " ;
}

// Imprimeix per pantalla les dades dels NodeTree fulla
template <class Type>
void BST<Type>::showLeafNodes() const{
    if(isEmpty()){
        throw new invalid_argument("Arbre buit.");
    }
    else {
        this->showLeafNodes(this->pRoot);
    }
    
}

template <class Type>
void BST<Type>::showLeafNodes(NodeTree<Type>* p) const{
    if (p->isExternal()) {
        cout << p->getKey() << " " ;
    }
    else {
        if (p->left() != 0) {
            showLeafNodes(p->left());
        }
        if (p->right() != 0) {
            showLeafNodes(p->right());
        }
    }
    
}


// Metode per inserir element a l'arbre
template <class Type>
void BST<Type>::insert(const Type& element,int id){
    bool inserted = false;
    
    if (isEmpty()) {
        this->pRoot = new NodeTree<Type>(element, 1);
        pRoot->setValue(element);
        pRoot->setKey(id);
    }
    
    else {
        NodeTree<Type>* aux2 = this->pRoot;
        NodeTree<Type>* newNode;
        while (!inserted && aux2->getKey() != id) { 
            // Mentre l'element no hi es a dins de l'arbre
            
            // Si l'ID de l'element es major que l'element de l'auxiliar
            if (aux2->getKey() < id) {
                if (aux2->right() == 0) {
                    newNode = new NodeTree<Type>(element, 1);
                    newNode->setKey(id);
                    newNode->setValue(element);
                    aux2->setRight(newNode);
                    newNode->setParent(aux2);
                    aux2 = newNode;
                    inserted = true;
                }
                else {
                    aux2 = aux2->right();
                }
            }

            // Si l'element es menor que l'element de l'auxiliar
            else {
                if (aux2->left() == 0) {
                    newNode = new NodeTree<Type>(element,1);
                    newNode->setKey(id);
                    newNode->setValue(element);
                    aux2->setLeft(newNode);
                    newNode->setParent(aux2);
                    aux2 = newNode;
                    inserted = true;
                }
                else {
                    aux2 = aux2->left();
                }
            }
            
        }
        
    }
    
}


#endif /* BST_H */

