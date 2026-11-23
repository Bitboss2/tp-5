#include <stdio.h>
#include "tp5.h"

void affichermenu()
{
    printf("=========================\n");
    printf("  Suivi de consommation\n");
    printf("=========================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvegarder et quitter\n");
}

int choixUtilisateur()
{
    int choix;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void afficheresume(Consommation p)
{
    char bonbon;
    char legume;
    char fruit;
    if (hummeurBonbons(p.bonbons) == 0)
        bonbon = '😇';
    else if (hummeurBonbons(p.bonbons)== 1)
        bonbon = '🙂';
    else if (hummeurBonbons(p.bonbons)== 2)
        bonbon = '😕';
    else 
        bonbon = '👿';
    
    if (hummeurLegumes(p.bonbons) == 0)
        bonbon = '😭';
    else if (hummeurLegumes(p.bonbons)== 1)
        bonbon = '🙂';
    else 
        bonbon = '😎';

    if (hummeurFruits(p.bonbons) == 0)
        bonbon = '😢';
    else if (hummeurFruits(p.bonbons)== 1)
        bonbon = '🙂';
    else 
        bonbon = '😄';
    printf("==========Resume du jour==========\n");
    printf("Eau       :   %d  💧\n", p.eau);
    printf("Cafe      :   %d  ☕\n", p.cafe);
    printf("Bonbons   :   %d  🍬 %c\n", p.bonbons, bonbon);
    printf("Gateau    :   %d  🍰\n", p.gateau);
    printf("Legumes   :   %d  🍆 %c\n", p.legumes, legume);
    printf("Fruits    :   %d  🍎 %c\n", p.fruits, fruit);
    printf("Proteines :   %d  🍖\n", p.proteines);
    printf("==================================\n");
}

int hummeurBonbons(int p)
{
    int code;
    if (p < 4)
        return 0;
    else if (p < 8) 
        return 1;
    else if (p < 13) 
        return 2;
    else return 3;
    return code;
}

int hummeurLegumes(int p)
{
    int code;
    if (p < 1)
        return 0;
    else if (p < 3) 
        return 1;
    else 
        return 2;
    return code;
}

int hummeurFruits(int p)
{
    int code;
    if (p < 1)
        return 0;
    else if (p < 3) 
        return 1;
    else 
        return 2;
    return code;
}