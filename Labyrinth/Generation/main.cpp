#include <ctime>
#include <iostream>
#include "generation.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    generation G;
    G.generer();
    system("PAUSE");
    return EXIT_SUCCESS;
}
