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
    this->enCours=false;
}

Location::Location(string dateDebut, double montantFacture, bool enCours, list<Article*> articlesLoues) {
    this->dateDebut=dateDebut;
    this->montantFacture=montantFacture; 
    this->enCours=true;
    this->articlesLoues=articlesLoues;
}

void Location::setDateDebut(string dateDebut) {
    this->dateDebut=dateDebut;
}

string Location::getDateDebut() {
    return this->dateDebut;
}

void Location::setEnCours(bool enCours) {
    this->enCours = enCours;
}

bool Location::getEnCours() {
    return this->enCours;
}


void Location::setMontantFacture(double montantFacture) {
    this->montantFacture=montantFacture;
}

double Location::getMontantFacture() {
    return this->montantFacture;
}

void Location::setArticlesLouees(list<Article*> articlesLouees) {
    this->articlesLoues = articlesLouees;
}

list<Article*> Location::getArticlesLouees() const {
    return articlesLoues;
}

void Location::affiche() {
    cout<<">Date de début de la location: "<<this->dateDebut<<endl;
    cout<<"Montant de la facture à ce jour: "<<this->montantFacture<<endl;
}

double Location::calculMontant() {
//    char toujoursEnCours;
//    if(this->dateFin.compare("NA")!=0){
//        cout<<"Location toujours en cours ? (O/N)")<<endl;
//        cin>>toujoursEnCours;
//        if(toujoursEnCours=='O'){
//            cout<<""<<endl;
//            
//        }
//        
//        
//    }
}


Location::~Location() {
}

