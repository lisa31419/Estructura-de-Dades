/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: María Isabel GOnzález Sánchez
 *
 * Created on 18 de febrero de 2019, 12:30
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string nom;
    int num;
    string arr_options[] = {"Sortir", "Benvinguda"};
    cout << "Hola, com et dius?" << endl;
    cin >> nom;
    cout <<"Hola, " << nom << ", que vols fer? " << endl;
    
    do{
        for(int i = 1; i < 3; i++){
            cout << ' ' << i << ". "<< arr_options[i]  << endl;
        }       
        cin >> num;
        switch(num){
            case 1:
                num = 0;
                cout << "Adeu!" << endl;
                break;
            case 2:
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << nom << endl;
                break;
            default:
                break;  
        }
    }while(num != 0);

    return 0;
}

