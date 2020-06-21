/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 26 de abril de 2019, 18:19
 */

#ifndef NODETREE_H
#define NODETREE_H

template <class Type>
class NodeTree {
public:
    NodeTree(const Type& data,int altura);
    NodeTree(const NodeTree& orig);
    virtual ~NodeTree();
    
    // CONSTRUCTORS
    NodeTree<Type>* right();
    NodeTree<Type>* left();
    NodeTree<Type>* parent();
    bool hasRight();
    bool hasleft();
    bool isRoot();
    bool isExternal();
    // Type& getElement() const;
    int getKey() const;       
    Type getValue() const;   
    
    // MODIFICADORS
    //void setElement(const Type& Data);
    void setRight(NodeTree<Type>* newRight);
    void setLeft(NodeTree<Type>* newLeft);
    void setParent(NodeTree<Type>* newParent);
    void setKey(int newKey);
    void setValue(const Type& newValue);
    
private:
    NodeTree<Type>* pParent;
    NodeTree<Type>* pLeft;
    NodeTree<Type>* pRight;
    int altura;
    int key;
    Type value;

};

/* CONSTRUCTORS I DESTRUCTOR */

// constructor amb parametres  
template <class Type>
NodeTree<Type>::NodeTree(const Type& data, int h){
    this->value = data;
    this->pLeft = 0;
    this->pRight = 0;
    this->altura = h;
}

// constructor copia
template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig){
    this->value = orig.value;
    this->pLeft = orig.pLeft;
    this->pRight = orig.pRight;
    this->altura = orig.altura;
}

// destructor
template <class Type>
NodeTree<Type>::~NodeTree(){
    
}

//  Metode per saber e node a la dreta d'un NodeTree
template <class Type> 
NodeTree<Type>* NodeTree<Type>::right(){
    return this->pRight;
}

// Metode per saber el node a l'esquerra d'un NodeTree
template <class Type>
NodeTree<Type>* NodeTree<Type>::left(){
    return this->pLeft;
}

// Metode per saber el pare d'un NodeTree
template <class Type>
NodeTree<Type>* NodeTree<Type>::parent(){
    return this->pParent;
}

// Metode per saber si un NodeTree tiene un node fill dret
template <class Type>
bool NodeTree<Type>::hasRight(){
    return this->right != 0;
}

// Metode per saber si un NodeTree tiene un node fill esquerra
template <class Type>
bool NodeTree<Type>::hasleft(){
    return this->left != 0;
}

// Metode per saber si un NodeTree es l'arrel
template <class Type>
bool NodeTree<Type>::isRoot(){
    return this->parent() == 0;
}

// Metode per saber si un NodeTree es node fulla (no te fills)
template <class Type>
bool NodeTree<Type>::isExternal(){
    return this->left() == 0 && this->right() == 0;
}

/*
// Metode per saber l'element d'un NodeTree
template <class Type>
const Type& NodeTree<Type>::getElement() const{
    return this->element;
}*/

// Metode per saber la clau d'un NodeTree
template <class Type>
int NodeTree<Type>::getKey() const {
    return this->key;
}

// Metode per saber el valor d'un NodeTree
template <class Type>
Type NodeTree<Type>::getValue() const {
    return this->value;
}


// MODIFICADORS


/*
// Metode per modificar l'element d'un NodeTree
template <class Type>
void NodeTree<Type>::setElement(const Type& data){
    this->element = data;
}*/

// Metode per establir un NodeTree com a fill dret d'un altre NodeTree
template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    this->pRight = newRight;
}

// Metode per establir un NodeTree com a fill esquerra d'un altre NodeTree
template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    this->pLeft = newLeft;
}

// Metode per establir un NodeTree com a pare d'un altre NodeTree
template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    this->pParent = newParent;
}

// Metode per canviar la clau d'un NodeTree
template <class Type>
void NodeTree<Type>::setKey(int newKey){
    this->key = newKey;
}

// Metode per canviar el valor d'un NodeTree
template <class Type>
void NodeTree<Type>::setValue(const Type& newValue){
    this->value = newValue;
}


#endif /* NODETREE_H */

