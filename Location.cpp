/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Location.cpp
 * Author: hadrien
 * 
 * Created on 25 novembre 2016, 14:39
 */

#include "Location.h"


Location::Location() {
    this->dateDebut="NA";
    this->montantFacture=0;
}

Location::Location(string dateDebut, double montantFacture) {
    this->dateDebut=dateDebut;
    this->montantFacture=montantFacture; 
}

void Location::setDateDebut(string dateDebut) {
    this->dateDebut=dateDebut;
}

string Location::getDateDebut() {
    return this->dateDebut;
}

void Location::setMontantFacture(double montantFacture) {
    this->montantFacture=montantFacture;
}

double Location::getMontantFacture() {
    return this->montantFacture;
}

void Location::affiche() {
    cout<<">Date de début de la location: "<<this->dateDebut<<endl;
    cout<<"Montant de la facture à ce jour: "<<this->montantFacture<<endl;
}

double Location::calculMontant() {
    //A FAIRE
}

void Location::setListeArticle(list<Article> listeArticle) {
    this->listeArticle=listeArticle;
}

list<Article> Location::getListeArticle() {
    return this->listeArticle;
}

void Location::ajoutArticle(const Article &a) {
    bool dejaPresent=false;
    if(this->listeArticle.empty()){
        cout<<"Liste d'article vide, ajout de l'article"<<endl;
        this->listeArticle.push_front(a);
    } else {
        for (list<Article>::iterator it = this->listeArticle.begin(); it!=this->listeArticle.end(); it++){
            if (*it == a){
                cout<<"Article déjà présent"<<endl;
                dejaPresent=true;
                break;
            }
        }
        if(!dejaPresent){
            this->listeArticle.push_front(a);
        }
    }
}

void Location::afficheListeArticle() {
    for (list<Article>::iterator it = this->listeArticle.begin(); it!=this->listeArticle.end(); it++){
        cout<<"Nom de l'article: "<<endl;
        it->affiche();
    }
}


Location::~Location() {
}

