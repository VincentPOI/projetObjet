/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vincent
 *
 * Created on 18 décembre 2016, 09:53
 */

#include <cstdlib>

#include "Article.h"
#include "FauteuilRoulant.h"
#include "MaterielLit.h"
#include "Magasin.h"
#include <list>
#include <typeinfo>
#include<string>
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int menu;
    Magasin magasin;
    do {
        cout << endl << " ----------------------- MENU -----------------------" << endl << endl;
        cout << "1. Creer un Article" << endl;
        cout << "2. Afficher Tout les Articles" << endl;
        cout << "3. charger les articles" << endl;
        cout << "4. Afficher Un client et ses locations" << endl;
        cout << "5. Enregistrer un Client" << endl;
        cout << "6. Enregistrer une location" << endl;
        cout << "7. remise de matériel" << endl;
        cout << "8. Afficher le montant gagné sur une période" << endl;
        cout << "0. Exit" << endl;
        cout << "Choix : ";
        cin>>menu;
        cout << endl;

        switch (menu) {
            case 0: break;

            case 1: magasin.ajouterArticle();
                magasin.majStock();
                break;

            case 2: magasin.afficherArticles(cout, false);
                break;

            case 3:magasin.loadStock();
                break;

            case 4: magasin.afficherClient();
                break;

            case 5:magasin.enregistrerClient();
                break;

            case 6:magasin.enregistrerLocation();
                break;

            case 7:magasin.rendreLocation();
                break;

            case 8:magasin.afficherRevenuPeriode();
                break;
        }

    } while (menu != 0);
}

