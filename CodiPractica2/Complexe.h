/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Complexe.h
 * Author: mariasalamo
 *
 * Created on 24 de febrero de 2016, 11:44
 */

// includes are not needed here
//#include <cstdlib>
//#include <iostream>
//using namespace std; 

#ifndef COMPLEXE_H
#define COMPLEXE_H

template <class T>
class Complexe{
    private: 
        
        T v_real;
        T v_imaginari;
    public:
        Complexe<T>(T r=0, T i=0);
        T real() const; 
        T imaginari() const;
        
            
};

template <class T>
Complexe<T>::Complexe(T r , T i) : v_real(r), v_imaginari(i)
{
    
}

template <class T>
T Complexe<T>::real() const
{
    return v_real;
}

template <class T>
T Complexe<T>::imaginari() const
{
    return v_imaginari; 
}

#endif /* COMPLEXE_H */

