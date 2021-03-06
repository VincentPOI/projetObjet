/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FauteuilRoulant.cpp
 * Author: hadrien
 * 
 * Created on 18 novembre 2016, 14:43
 */

#include "FauteuilRoulant.h"

FauteuilRoulant::FauteuilRoulant():Article() {
    this->largeurAssise=0;
    this->poidsFauteuil=0;            
}

FauteuilRoulant::FauteuilRoulant(string refArticle,string marqueArticle,string modeleArticle, double prixJourArticle,int nbStockarticle, double largeurAssise, double poidsFauteuil):Article(refArticle,marqueArticle,modeleArticle,prixJourArticle,nbStockarticle) {
    this->largeurAssise=largeurAssise;
    this->poidsFauteuil=poidsFauteuil;
}

FauteuilRoulant::~FauteuilRoulant() {
}

void FauteuilRoulant::affiche(ostream& ostr){
    Article::affiche(ostr);
    ostr<<"Largeur de l'assise : "<<this->largeurAssise<<"\n";
    ostr<<"Poids du fauteuil : "<<this->poidsFauteuil<<"\n";
}

void FauteuilRoulant::setLargeurAssise(double largeurAssise){
    this->largeurAssise=largeurAssise;
}

double FauteuilRoulant::getLargeurAssise(){
    return this->largeurAssise;
}

void FauteuilRoulant::setPoidsFauteuil(double poidsFauteuil){
    this->poidsFauteuil=poidsFauteuil;
}

double FauteuilRoulant::getPoidsFauteuil(){
    return this->poidsFauteuil;
}
