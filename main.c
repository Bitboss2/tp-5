#include <stdio.h>
#include "tp5.h"
#include <windows.h>
#include <locale.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
    int choix = 0;
    do {
        affichermenu();
        choix = choixUtilisateur();
        switch (choix)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:
            printf("Au revoir");
            break;
        default:
            printf("Choix invalide");
            break;
        }
    } while (choix != 3); 
    return 0;
}