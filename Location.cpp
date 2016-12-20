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
#include <list>

Location::Location() {
    this->dateDebut = "NA";
    this->montantFacture = 0;
}

Location::~Location() {

}

Location::Location(string dateDebut, int nbJours, double montantFacture, list<Article*> articlesLoues) {
    this->dateDebut = dateDebut;
    this->nbJours = nbJours;
    this->montantFacture = montantFacture;
    this->articlesLoues = articlesLoues;
}

Location::Location(string dateDebut, int nbJours, list<Article*> articlesLoues) {
    this->dateDebut = dateDebut;
    this->nbJours = nbJours;
    this->montantFacture = this->calculMontant();
    this->articlesLoues = articlesLoues;
}

void Location::setDateDebut(string dateDebut) {
    this->dateDebut = dateDebut;
}

string Location::getDateDebut() {
    return this->dateDebut;
}

void Location::setMontantFacture(double montantFacture) {
    this->montantFacture = montantFacture;
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
    cout << "Date de début de la location: " << this->dateDebut << endl;
    cout << "Montant de la facture à ce jour: " << this->montantFacture << endl;
    for (list<Article*>::iterator it = this->articlesLoues.begin(); it != this->articlesLoues.end(); it++) {
        (*it)->affiche(cout);
    }
}

double Location::calculMontant() {
    double montantArticle;
    double montantLocation = 0;
    for (list<Article*>::iterator it = this->articlesLoues.begin(); it != this->articlesLoues.end(); it++) {
        montantArticle = 0;
        montantArticle = (*it)->getPrixJourArticle() * this->nbJours;
        montantLocation = montantArticle + montantLocation;
    }
    return montantLocation;
}
