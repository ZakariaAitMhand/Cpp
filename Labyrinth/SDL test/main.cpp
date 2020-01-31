#include <cstdlib>
#include <iostream>
#include<string.h>
#include "personnage.h"
#include "labyrinthe.h"
#include <ctime>

using namespace std;

int main ( int argc, char* argv[] ) {
    srand(time(0));                   
    labyrinthe labyrinthe;
    labyrinthe.menu();
    return EXIT_SUCCESS;
}
