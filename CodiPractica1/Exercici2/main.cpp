/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Maria Isabel González Sánchez
 *
 * Created on 19 de febrero de 2019, 10:24
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string nom;
    int num;
    std::vector<string> arr_options {"1. Sortir", "2. Benvinguda","3. Redefinir nom"};
    cout << "Hola, com et dius?" << endl;
    cin >> nom;
    cout <<"Hola, "<< nom <<", que vols fer?"<<endl;

    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
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
            case 3:
                cout << "Nou nom: " << endl;
                cin >> nom;
                cout << "Hola, " << nom << ", que vols fer?" << endl;
                break;
            default:
                break;  
        }
    }while(num != 0);

    return 0;
}

