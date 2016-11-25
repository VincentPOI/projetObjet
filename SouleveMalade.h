/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SouleveMalade.h
 * Author: hadrien
 *
 * Created on 18 novembre 2016, 15:23
 */

#ifndef SOULEVEMALADE_H
#define SOULEVEMALADE_H
#include "Article.h"
#include <string>
using namespace std;

class SouleveMalade : public Article {
public:
    SouleveMalade();
    SouleveMalade(string, string, string, double, int, int, int);
    virtual ~SouleveMalade();
    void affiche();
    void setCapaciteLevage(int);
    int getCapaciteLevage();
    void setDegrePivotFleau(int);
    int getDegrePivotFleau();
private:
    int capaciteLevage;
    int degrePivotFleau;
};

#endif /* SOULEVEMALADE_H */

