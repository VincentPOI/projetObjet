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

#include "Magasin.h"
#include "FauteuilRoulant.h"
#include "MatelasAir.h"

Magasin::Magasin() {

}

Magasin::Magasin(list<Article> listeArticle, list<Client> listeClients) {
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
        cout << "type d'article?(Fauteuil roulant : FR, Matelas air : MR, Souleve Malade : SM, Materiel lit : ML, retour:R)";
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
    cout << "Prix a la location, journalier?(Fauteuil roulant : FR, Matelas air : MR, Souleve Malade : SM, Materiel lit : ML, retour:R)";
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
        FauteuilRoulant fauteuil(ref, marque, modele, prix, stock, largeur, poids);
        this->listeArticle.push_front(fauteuil);


    } else if (typeArticle == "MR") {
        string dimension;
        int pmax;
        double tpsgonfl;
        cout << "dimension du matela?";
        cin >> dimension;
        cout << "poids maximumspporté?";
        cin >> pmax;
        cout << "temps de gonflage?";
        cin >> tpsgonfl;
        MatelasAir matelas(ref,marque,modele,prix,stock,pmax,dimension,tpsgonfl);
        this->listeArticle.push_front(matelas);
    } else if (typeArticle == "SM") {

    } else if (typeArticle == "ML") {

    }
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

void Magasin::setListeArticle(list<Article> listeArticle) {
    this->listeArticle = listeArticle;
}

list<Article> Magasin::getListeArticle() const {
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


