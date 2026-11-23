#include <stdio.h>
#include "tp5.h"
#include <windows.h>
#include <locale.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
    Consommation consommer;
    consommer = intialiser();
    int choix = 0;
    Objectif gigachad = {8, 5, 3, 2};
    do {
        affichermenu();
        choix = choixUtilisateur();
        switch (choix)
        {
        case 1:
            consommer = ajouterConsommation(consommer);
            break;
        case 2:
            afficheresume(consommer);
            break;
        case 3 :
            afficherObjectifScore(consommer, gigachad);
            break;
        case 4:
            printf("Au revoir");
            break;
        default:
            printf("Choix invalide");
            break;
        }
    } while (choix != 3); 
    return 0;
}