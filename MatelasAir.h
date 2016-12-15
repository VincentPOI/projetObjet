/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatelasAir.h
 * Author: hadrien
 *
 * Created on 18 novembre 2016, 16:49
 */

#ifndef MATELASAIR_H
#define MATELASAIR_H
#include "Article.h"
#include<iostream>
#include <string>
using namespace std ;

class MatelasAir : public Article {
public:
    MatelasAir();
    MatelasAir(string, string, string, double, int, int, string, double);
    void affiche(ostream& ostr);
    virtual ~MatelasAir();
    void setPoidsMaximumSupporte(int poidsMaximumSupporte);
    int getPoidsMaximumSupprote();
    void setDimensionMatelas(string dimensionMatelas);
    string getDimensionMatelas();
    void setTempsGonflage(double tempsGonflage);
    double getTempsGonflage();
private:
    int poidsMaximumSupporte;
    string dimensionMatelas;
    double tempsGonflage;
};

#endif /* MATELASAIR_H */

