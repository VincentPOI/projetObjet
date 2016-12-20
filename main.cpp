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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    list<Article*> listArticle;
    listArticle.push_front(new FauteuilRoulant("0001FR","bite","moule",45, 46, 47, 48));
    Location location("18/12/2016", "NA", 0, listArticle);
    location.setDateFin("NA");
    location.calculMontant();
    location.calculMontant();
    int menu;
    Magasin magasin;
    do
    {
        cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Creer un Article"<<endl;
        cout<<"2. Afficher Tout les Articles"<<endl;
        cout<<"3. Afficher les articles disponibles"<<endl;
        cout<<"4. Afficher les locations en cours"<<endl;
        cout<<"5. Enregistrer un Client "<<endl;
        cout<<"6. afficher recette"<<endl;
        cout<<"7. "<<endl;
        cout<<"8. "<<endl;
        cout<<"9. "<<endl;
        cout<<"10."<<endl;
        cout<<"11."<<endl;
        cout<<"12."<<endl;
        cout<<"0. "<<endl<<endl;
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;
 
        switch(menu)
        {
            case 0 : break;
 
            case 1 : magasin.ajouterArticle();
            magasin.majStock();          
            break;
 
            case 2 : magasin.afficherArticles(cout,false);
            break;
 
            case 3 :magasin.loadStock();
            break;
 
            case 4 : ;
            break;
 
            case 5 : magasin.enregistrerClient();
            break;
 
            case 6 : ;
            break;
 
            case 7 : ;
            break;
 
            case 8 : ;
            break;
 
            case 9 : ;
            break;
 
            case 10 : ;
            break;
 
            case 11 : ;
            break;
 
            case 12 : ;
 
            break;
        }
 
    }while (menu!=0);
}

