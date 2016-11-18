/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaterielLit.cpp
 * Author: vincent
 * 
 * Created on 18 novembre 2016, 13:52
 */

#include "MaterielLit.h"

MaterielLit::MaterielLit():Article() {
    this->dimensionLit = "NA";
    this->poidsMaxAdmissible = NULL;
}

int MaterielLit::affiche() {
    Article::affiche();
    cout<<"Dimension du materiel de lit : "<<this->dimensionLit<<endl;
    cout<<"Poids maximum du materiel : "<<this->poidsMaxAdmissible<<endl;
    
}


MaterielLit::MaterielLit(string refArticle,string marqueArticle,string modeleArticle, double prixJourArticle,int nbStockarticle ,double poidsMaxAdmissible, string dimensionLit): Article(refArticle,marqueArticle,modeleArticle,prixJourArticle,nbStockarticle){
    this->dimensionLit = dimensionLit;
    this->poidsMaxAdmissible = poidsMaxAdmissible;
}


MaterielLit::~MaterielLit() {
}

void MaterielLit::setDimensionLit(string dimensionLit) {
    this->dimensionLit = dimensionLit;
}

string MaterielLit::getDimensionLit() const {
    return dimensionLit;
}

void MaterielLit::setPoidsMaxAdmissible(double poidsMaxAdmissible) {
    this->poidsMaxAdmissible = poidsMaxAdmissible;
}

double MaterielLit::getPoidsMaxAdmissible() const {
    return poidsMaxAdmissible;
}

