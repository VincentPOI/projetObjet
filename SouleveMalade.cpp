/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SouleveMalade.cpp
 * Author: hadrien
 * 
 * Created on 18 novembre 2016, 15:23
 */

#include <valarray>

#include "SouleveMalade.h"

SouleveMalade::SouleveMalade():Article() {
    this->capaciteLevage=0;
    this->degrePivotFleau=0;
}

SouleveMalade::SouleveMalade(string refArticle,string marqueArticle,string modeleArticle, double prixJourArticle,int nbStockarticle, int capaciteLevage, int degrePivotFleau):Article(refArticle,marqueArticle,modeleArticle,prixJourArticle,nbStockarticle) {
    this->capaciteLevage=capaciteLevage;
    this->degrePivotFleau=degrePivotFleau;
}

SouleveMalade::~SouleveMalade() {
}

void SouleveMalade::affiche(ostream& ostr){
    Article::affiche(ostr);
    ostr<<"Capacité de levage du fauteuil: "<<this->capaciteLevage<<"\n";
    ostr<<"Degré de pivot du fléau: "<<this->degrePivotFleau<<"\n";
}

void SouleveMalade::setCapaciteLevage(int capaciteLevage){
    this->capaciteLevage=capaciteLevage;
}

int SouleveMalade::getCapaciteLevage(){
    return this->capaciteLevage;
}

void SouleveMalade::setDegrePivotFleau(int degrePivotFleau){
    this->degrePivotFleau=degrePivotFleau;
}

int SouleveMalade::getDegrePivotFleau(){
    return this->degrePivotFleau;
}