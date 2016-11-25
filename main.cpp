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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Article robert("AZ1235","asus","rog", 15.6, 10 );
    MaterielLit bidule;
    FauteuilRoulant gerard("AA0000","ferreari","viper",15.6,10,200,200);
    gerard.affiche();
    bidule.affiche();
    robert.affiche();
    
    return 0;
}

