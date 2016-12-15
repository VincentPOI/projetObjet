/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaterielLit.h
 * Author: vincent
 *
 * Created on 18 novembre 2016, 13:52
 */

#ifndef MATERIELLIT_H
#define MATERIELLIT_H
#include <string>

#include "Article.h"
using namespace std ;

class MaterielLit : public Article {
public:
    MaterielLit();
    MaterielLit(string, string, string, double, int, double, string, bool);
    void affiche(ostream& ostr);
    virtual ~MaterielLit();
    void setDimensionLit(string dimensionLit);
    string getDimensionLit() const;
    void setPoidsMaxAdmissible(double poidsMaxAdmissible);
    double getPoidsMaxAdmissible() const;
    void setTypeMateriel(bool typeMateriel);
    bool isTypeMateriel() const;
protected:
    double poidsMaxAdmissible;
    string dimensionLit;
    bool typeMateriel;  
};

#endif /* MATERIELLIT_H */

