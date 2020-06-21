/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaxHeap.h
 * Author: Maria Isabel Gonzalez Sanchez
 *
 * Created on 15 de mayo de 2019, 0:11
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <math.h> 
#include "NodeHeap.h"

template <class Type>
class MaxHeap {
public:
    // Constructor i destructor
    MaxHeap();
    virtual ~MaxHeap();
    
    // Metodes consultors
    const int size() const;
    const bool isEmpty() const;
    const int& max() const;
    const vector<Type> maxValues() const;
    const NodeHeap<Type>* search(int& key) const;
    
    // Metodes modificadors
    void insert(const int& key, const Type& val);
    void removeMax();
    
    // Imprimir
    void printHeap();
    
private:
    vector<NodeHeap<Type>*> vectorNodes;
    void upHeap();
    void downHeap();
    void swap (int pos1, int pos2);
    
};

// Constructor
template <class Type>
MaxHeap<Type>::MaxHeap(){
    
}

// Destructor
template <class Type> 
MaxHeap<Type>::~MaxHeap() {
    for (int i = vectorNodes.size() - 1; i >= 0; i--) {
        if(vectorNodes[i] != 0){
            cout << "Entry amb clau " << vectorNodes[i]->getKey() << " eliminada." << endl;
            
        }
        
    }
    vectorNodes.clear();
     
}


// METODES CONSULTORS

/*
 * Metode que retorna el nombre de nodes que hi ha en el Heap
 * @return int 
 */
template <class Type> 
const int MaxHeap<Type>::size() const {
    return this->vectorNodes.size();
    
}

/*
 * Metode que retorna cert si el Heap està buit, fals en cas contrari
 * @return True/False 
 */
template <class Type> 
const bool MaxHeap<Type>::isEmpty() const {
    return size() == 0;
    
}

/**
 * Metode que retorna la clau màxima del Heap
 * @return int
 */
template <class Type>
const int& MaxHeap<Type>::max() const {
    if (isEmpty()) {
        cout << "Heap buit" << endl;
    } else {
        return vectorNodes[0]->getKey();
    }
    
}

/**
 * Metode que retorna els valors de la clau màxima del Heap
 * @return vector
 */
template <class Type>
const vector<Type> MaxHeap<Type>::maxValues() const {
    if (isEmpty()) {
        cout << "Heap buit" << endl;
    } else {
       
        return vectorNodes[0]->getValues();
    }
    
}

/*
 * Metode que busca la clau donada al Heap i retorna el vector de valors associat
 *@return vector
 */
template<class Type>
const NodeHeap<Type>* MaxHeap<Type>::search(int& key) const {
    bool trobat = false;
    int i = 0;
    
    while (!trobat && i < vectorNodes.size()) {
        if (vectorNodes.at(i)->getKey() == key) {
            trobat = true;
        }
        i += 1;
    }
    
    if (!trobat){
        return nullptr;
        
    } else {
        return vectorNodes.at(i-1);
    }
}



// METODES MODIFICADORS

/**
 * Metode que afegeix un nou element al Heap. Aquesta funció rep la clau i el valor/s d’aquesta clau.
 * @param key, first, second
 */
template <class Type> 
void MaxHeap<Type>::insert(const int& key, const Type& val) {
    if (isEmpty()) {
        // Si no hi han entries
        NodeHeap<Type>* aux = new NodeHeap<Type>(key);
        vectorNodes.push_back(aux);
        vectorNodes[0]->setValue(val);
        
    } else {
        // Si ja hi han entries comprobem si existeix alguna amb la mateixa clau
        bool trobat = false;
        int i = 0;
        
        while (!trobat && i < vectorNodes.size()) {
            if (vectorNodes.at(i)->getKey() == key) {
                trobat = true;
            }

            i += 1;
        }
        
        if (!trobat) {
            // Si no trobem alguna coincidencia creem un NodeHeap amb la entry (key,val)
            NodeHeap<Type>* aux2 = new NodeHeap<Type>(key);
            vectorNodes.push_back(aux2);
            vectorNodes[vectorNodes.size()-1]->setValue(val);
            // Reestructurem el heap
            upHeap();
        } else {
            // Si existeix una entry amb la mateixa clau, nomes canviem el value pel value pasat per parametre
            vectorNodes[i-1]->setValue(val);
        }
        
    }
   
}

/**
 * Metode que resestructura el heap des de abaix cap a dalt
 */
template<class Type>
void MaxHeap<Type>::upHeap() {
    bool trobat = false;
    int pos = vectorNodes.size() - 1;
    
    while(pos != 0 && !trobat) {
        // Si la clau del pare es menor que la clau del fill, els intercambien
        if(pos%2 == 0 && vectorNodes[(pos - 2)/2]->getKey() < vectorNodes[pos]->getKey()) {
            swap (pos, (pos-2)/2);
            pos = (pos-2)/2;
        }
        else if( pos%2 != 0 && vectorNodes[(pos - 1)/2]->getKey() < vectorNodes[pos]->getKey()){
            swap (pos,(pos-1)/2);
            pos = (pos-1)/2;
        }
        else {
            trobat = true;
        }
        
    }
}

/**
 * Intercanviem els nodes de posicio
 */
template <class Type>
void MaxHeap<Type>::swap(int pos1, int pos2) {
    NodeHeap<Type>* aux = vectorNodes[pos1];
    vectorNodes[pos1] = vectorNodes[pos2];
    vectorNodes[pos2] = aux;
    
}



/**
 * Metode que elimina el node màxim del Heap
 */
template <class Type> 
void MaxHeap<Type>::removeMax() {
    if(isEmpty()){
        cout << "Heap buit" << endl;
        
    } else {

        vectorNodes[0] = vectorNodes.back();
        vectorNodes.pop_back();
        
        // Reestructurem el heap 
        downHeap(); 
        
    }
    
}

/**
 * Metode que reestructura el heap de
 */
template <class Type>
void MaxHeap<Type>::downHeap() {
    int pos = 0;
    bool trobat = false;
    
    while (pos < vectorNodes.size() && !trobat) {
        // Si arribem al final de l'array, parem
        if (2*pos + 2 >= vectorNodes.size() && 2*pos + 1 >= vectorNodes.size()) {
            trobat = true;
            
        } else if (2*pos + 2 >= vectorNodes.size()) {
            // Posicions senars quan les parells arriban al final de l'array
            // Si la clau del fill es mayor que la del pare, els intercanviem
            if (vectorNodes[pos]->getKey() < vectorNodes[2*pos + 1]->getKey()) {
                swap(pos, 2*pos+1);
                pos = 2*pos + 1;
            } else {
                trobat = true;
            }
            
        } else if (2*pos + 1 >= vectorNodes.size()) {
            // Posicions parells quan les senars arriban al final de l'array
            // Si la clau del fill es mayor que la del pare, els intercanviem
            if (vectorNodes[pos]->getKey() < vectorNodes[2*pos + 2]->getKey()) {
                swap(pos, 2*pos+2);
                pos = 2*pos + 2;
            } else {
                trobat = true;
            }
            
        } else {
            // Si estem al principi o la meitat de l'arry, comprovem tant les posicions senars com parells
            if (vectorNodes[2*pos + 2]->getKey() < vectorNodes[2*pos + 1]->getKey()) {
                if (vectorNodes[pos]->getKey() < vectorNodes[2*pos + 1]->getKey()) {
                    swap(pos, 2*pos+1);
                    pos = 2*pos + 1;
                } else {
                    trobat = true;
                }
                
            } else {
                if (vectorNodes[pos]->getKey() < vectorNodes[2*pos + 2]->getKey()) {
                    swap(pos, 2*pos+2);
                    pos = 2*pos + 2;
                } else {
                    trobat = true;
                }
                
            }
            
        }
        
    }
    
}


// IMPRIMIR

/**
 * Imprimeix per consola tot el Heap
 */
template <class Type>
void MaxHeap<Type>::printHeap() {
    NodeHeap<Type>* aux;
    int i = 0;
    for (typename vector<NodeHeap<Type>*>::iterator it = vectorNodes.begin() ; it != vectorNodes.end(); ++it) {
        aux = *it;
        aux->toString(); 
        i += 1;
    }
    
}


#endif /* MAXHEAP_H */

