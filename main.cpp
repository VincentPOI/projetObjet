/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vincent
 *
 * Created on 18 décembre 2016, 09:53
 */

#include <cstdlib>

#include "Article.h"
#include "MaterielLit.h"
#include "FauteuilRoulant.h"
#include "Location.h"
#include "Magasin.h"
#include "MatelasAir.h"
#include "SouleveMalade.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    Article robert("AZ1235","asus","rog", 15.6, 10 );
    list<Article> listeArticle;
    listeArticle.push_back(robert);
    MaterielLit bidule; 
    FauteuilRoulant gerard("AA0000","ferreari","viper",15.6,10,200,200);
    Location pc("26/11/16", 16.2);
    pc.ajoutArticle(robert);
    pc.afficheListeArticle();
    gerard.affiche();
    bidule.affiche();
    robert.affiche();
    
    return 0;
}

