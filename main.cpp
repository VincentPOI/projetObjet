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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Article robert = new Article("AZ1235","asus","rog", 15.6, 10 );
    MaterielLit bidule = new MaterielLit()
    robert.affiche();
    
    return 0;
}

