/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FauteuilRoulant.h
 * Author: hadrien
 *
 * Created on 18 novembre 2016, 14:43
 */

#ifndef FAUTEUILROULANT_H
#define FAUTEUILROULANT_H
#include "Article.h"
#include <string>
using namespace std;

class FauteuilRoulant : public Article {    
public:
    FauteuilRoulant();
    FauteuilRoulant(string, string, string, double, int, double, double);
    virtual ~FauteuilRoulant();
    void affiche();
    void setLargeurAssise(double);
    double getLargeurAssise();
    void setPoidsFauteuil(double);
    double getPoidsFauteuil();
private:
    double largeurAssise;
    double poidsFauteuil;
    

};

#endif /* FAUTEUILROULANT_H */

