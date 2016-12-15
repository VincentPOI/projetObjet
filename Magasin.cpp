/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Magasin.cpp
 * Author: vincent
 * 
 * Created on 25 novembre 2016, 14:19
 */
#include <iostream>
#include <fstream>
#include "Magasin.h"
#include "FauteuilRoulant.h"
#include "MatelasAir.h"
#include "SouleveMalade.h"
#include "MaterielLit.h"
#include "tri.h"
using namespace std;

Magasin::Magasin() {

}

Magasin::Magasin(list<Article*> listeArticle, list<Client> listeClients) {
    this->listeArticle = listeArticle;
    this->listeClients = listeClients;
}

void Magasin::ajouterArticle() {
    string typeArticle = "NA";
    string ref;
    string marque;
    string modele;
    double prix;
    int stock;
    cout << "Nouvel article: ";
    while (typeArticle.compare("FR") != 0 && typeArticle.compare("MR") != 0 && typeArticle.compare("SM") != 0 && typeArticle.compare("ML") != 0 && typeArticle.compare("R") != 0) {
        cout << "type d'article?(Fauteuil roulant : FR, Matelas air : MR, Souleve Malade : SM, Materiel lit : ML, retour:R)-> ";
        cin >> typeArticle;
    }

    if (typeArticle == "R") {
        return;
    }
    cout << "Reférence?(0000AZ)";
    cin >> ref;
    cout << "Marque?";
    cin >> marque;
    cout << "modele?";
    cin >> modele;
    cout << "Prix a la location, journalier?";
    cin >> prix;
    cout << "Nombre de cet article en stock?";
    cin >> stock;

    if (typeArticle == "FR") {
        double largeur;
        double poids;
        cout << "largeur de l'assise du fauteuil roulant?";
        cin >> largeur;
        cout << "poids du fauteuil roulant?";
        cin >> poids;
        this->listeArticle.push_front(new FauteuilRoulant(ref, marque, modele, prix, stock, largeur, poids));
    } else if (typeArticle == "MR") {
        string dimension;
        int pmax;
        double tpsgonfl;
        cout << "dimension du matela?";
        cin >> dimension;
        cout << "poids maximum supporté?";
        cin >> pmax;
        cout << "temps de gonflage?";
        cin >> tpsgonfl;
        this->listeArticle.push_front(new MatelasAir(ref, marque, modele, prix, stock, pmax, dimension, tpsgonfl));
    } else if (typeArticle == "SM") {
        int caplevage;
        int degrepivot;
        cout << "capacité de levage?";
        cin >> caplevage;
        cout << "degre pivot fleau?";
        cin >> degrepivot;
        this->listeArticle.push_front(new SouleveMalade(ref, marque, modele, prix, stock, caplevage, degrepivot));
    } else if (typeArticle == "ML") {
        double pmax;
        string dimension;
        bool typemat;
        cout << "Lit médicalisé / table d'alité (1/0)?";
        cin >> typemat;
        cout << "poids maximum supporté?";
        cin >> pmax;
        cout << "dimensions?";
        cin >> dimension;
        this->listeArticle.push_front(new MaterielLit(ref, marque, modele, prix, stock, pmax, dimension, typemat));
    }
}

void Magasin::afficherArticles(ostream& ostr, bool maj) {
    if (!maj) {
        string tri;
        cout << "Afficher dans quel ordre? :";
        cout << "Reférence : REF, Marque : MAR, Modèle : MOD, Prix par jours : PR, Retour : R -> ";
        cin >> tri;

        if (tri == "R") {
            return;
        } else if (tri == "MAR") {
            listeArticle.sort(triMarque());
        } else if (tri == "MOD") {
            listeArticle.sort(triModele());
        } else if (tri == "PR") {
            listeArticle.sort(triPrixJour());
        } else {
            listeArticle.sort();
        }
    }
    for (list<Article*>::iterator it = this->listeArticle.begin(); it != this->listeArticle.end(); it++) {
        (*it)->affiche(ostr);
    }
}

void Magasin::majStock() {
    ofstream fichier("Stock.txt", ios::out | ios::trunc);

    if (fichier) {
        this->afficherArticles(fichier, true);
        fichier.close();

    } else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Magasin::loadStock() {
    ifstream fichier("Stock.txt", ios::in);

    if (fichier) {
        string ligne;
        string typeArticle;
        FauteuilRoulant fauteuil;
        MatelasAir matelasAir;
        MaterielLit matelatLit;
        while (getline(fichier, ligne)) {
            if (ligne.find("*") != ligne.npos) {
                ligne = ligne.substr(ligne.find(":")+2);              
                ligne = ligne.replace(ligne.end()-16,ligne.end(),"");
                
                cout << ligne << endl;
            } else {
                ligne = ligne.substr(ligne.find(":")+2);
                cout << ligne << endl;
            }
        }
        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Magasin::jeterArticle() {

}

Magasin::~Magasin() {
}

void Magasin::afficheListeLocations(Client client) {

}

void Magasin::calculMontantRecettes(string periode) {

}

void Magasin::enregistrerLocation(Client client) {

}

void Magasin::restitutionArticle(Client client) {

}

void Magasin::setListeArticle(list<Article*> listeArticle) {
    this->listeArticle = listeArticle;
}

list<Article*> Magasin::getListeArticle() const {
    return listeArticle;
}

void Magasin::setListeClients(list<Client> listeClients) {
    this->listeClients = listeClients;
}

list<Client> Magasin::getListeClients() const {
    return listeClients;
}

void Magasin::afficheArticlesDisponibles() {

}


