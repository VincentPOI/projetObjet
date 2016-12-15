/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tri.h
 * Author: vincent
 *
 * Created on 13 décembre 2016, 15:02
 */

#ifndef TRI_H
#define TRI_H
#include "Article.h"

struct triMarque {
    bool operator()(const Article* const & a, const Article* const & b) {
        if(a->getMarqueArticle() < b->getMarqueArticle())
            return true;
        else
            return false;
    }
};
struct triModele {
    bool operator()(const Article* const & a, const Article* const & b) {
        if(a->getModeleArticle() < b->getModeleArticle())
            return true;
        else
            return false;
    }
};
struct triPrixJour {
    bool operator()(const Article* const & a, const Article* const & b) {
        if(a->getPrixJourArticle() < b->getPrixJourArticle())
            return true;
        else
            return false;
    }
};

#endif /* TRI_H */

