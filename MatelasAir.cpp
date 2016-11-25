/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatelasAir.cpp
 * Author: hadrien
 * 
 * Created on 18 novembre 2016, 16:49
 */

#include "MatelasAir.h"
#include <string>


MatelasAir::MatelasAir() : Article() {
    this->poidsMaximumSupporte = 0;
    this->dimensionMatelas = "NA";
    this->tempsGonflage = 0;
}

MatelasAir::MatelasAir(string refArticle, string marqueArticle, string modeleArticle, double prixJourArticle, int nbStockarticle, int poidsMaximumeSupporte, string dimensionMatelas, double tempsGonflage) : Article(refArticle,marqueArticle,modeleArticle,prixJourArticle,nbStockarticle) {
    this->poidsMaximumSupporte = poidsMaximumeSupporte;
    this->dimensionMatelas = dimensionMatelas;
    this->tempsGonflage = tempsGonflage;
}

void MatelasAir::setPoidsMaximumSupporte(int poidsMaximumSupporte){
    this->poidsMaximumSupporte = poidsMaximumSupporte;
}

int MatelasAir::getPoidsMaximumSupprote() {
    return this->poidsMaximumSupporte;
}

void MatelasAir::setDimensionMatelas(string dimensionMatelas){
    this->dimensionMatelas = dimensionMatelas;
}

string MatelasAir::getDimensionMatelas(){
    return this->dimensionMatelas;
}

void MatelasAir::setTempsGonflage(double tempsGonflage){
    this->tempsGonflage = tempsGonflage;
}

double MatelasAir::getTempsGonflage(){
    return this->tempsGonflage;
}


MatelasAir::~MatelasAir() {
}

