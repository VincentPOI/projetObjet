/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SouleveMalade.h
 * Author: vincent
 *
 * Created on 18 novembre 2016, 14:52
 */

#ifndef SOULEVEMALADE_H
#define SOULEVEMALADE_H

#include "Article.h"


class SouleveMalade: public Article{
public:
    SouleveMalade();
    SouleveMalade(int,int);
    affiche();
    virtual ~SouleveMalade();
private:
    

};

#endif /* SOULEVEMALADE_H */

