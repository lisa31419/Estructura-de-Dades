/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeHeap.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 17 de mayo de 2019, 10:54
 */

#ifndef NODEHEAP_H
#define NODEHEAP_H

#include <vector>
#include <string>

using namespace std;

template <class Type>
class NodeHeap {
public:
    // Constructor y destructor
    NodeHeap(int key, const Type& data);
    virtual ~NodeHeap();
    
    // Metodes consultors
    const int& getKey() const;
    const vector<Type> getValues() const;
    
    
    // Metode modificador
    void setValue(const Type& value);
    
    // Imprimir
    void toString() const;
    
private:
    int key;
    Type value;
    vector<Type> values;
    
};

// Constructor
template <class Type>
NodeHeap<Type>::NodeHeap(int key, const Type& data) {
    this->key = key;
    this->value = data;
    setValue(data);
    
}

// Destructor
template <class Type>
NodeHeap<Type>::~NodeHeap() {
    
}


// METODES CONSULTORS

/*
 * Metode que retorna la key/clau d'una entry
 * @return key
 */
template <class Type>
const int& NodeHeap<Type>::getKey() const {
    return this->key;
    
}

/*
 * Metode que retorna un vector con entrys 
 */
template <class Type>
const vector<Type> NodeHeap<Type>::getValues() const {
    return this->values;
    
}



// METODE MODIFICADOR

/*
 * Metode que canvia el value d'una entry al estar repetida la seva clau
 */
template <class Type>
void NodeHeap<Type>::setValue(const Type& value) {
    values.push_back(value);
    
}



// IMPRIMIR

/*
 * Metode per imprimir per pantalla
 */
template <class Type>
void NodeHeap<Type>::toString() const {
    cout << "***************" << endl;
    cout << "-> Mountain " << this->key << endl;
    cout << "-> Values: ";
    for(vector<string>::const_iterator it = this->values.begin(); it != this->values.end(); ++it){
        cout << *it;
        cout << '\n';
    }
    
    
}

#endif /* NODEHEAP_H */

