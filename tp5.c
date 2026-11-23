#include <stdio.h>
#include "tp5.h"

void affichermenu()
{
    printf("=========================\n");
    printf("  Suivi de consommation\n");
    printf("=========================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvergarder et quitter\n");
}

int choixUtilisateur()
{
    int choix;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}