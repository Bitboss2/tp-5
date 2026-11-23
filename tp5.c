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

void afficheresume(Consommation p)
{
    printf("==========Resume du jour==========\n");
    printf("Eau       :   %d  💧", p.eau);
    afficher_barre(10, p.eau);
    printf("Cafe      :   %d  ☕", p.cafe);
    afficher_barre(10, p.cafe);
    if (hummeurBonbons(p.bonbons) == 0){
        printf("Bonbons   :   %d  🍬 😇", p.bonbons);
        afficher_barre(10, p.bonbons);}
    else if (hummeurBonbons(p.bonbons)== 1){
        printf("Bonbons   :   %d  🍬 🙂", p.bonbons);
        afficher_barre(10, p.bonbons);}
    else if (hummeurBonbons(p.bonbons)== 2){
        printf("Bonbons   :   %d  🍬 😕", p.bonbons);
        afficher_barre(10, p.bonbons);}
    else{    
        printf("Bonbons   :   %d  🍬 👿", p.bonbons);
        afficher_barre(10, p.bonbons);
    }
    printf("Gateau    :   %d  🍰", p.gateau);
    afficher_barre(10, p.gateau); 
    if (hummeurLegumes(p.legumes) == 0){
        printf("Legumes   :   %d  🍆 😭", p.legumes);
        afficher_barre(10, p.legumes);
    }
    else if (hummeurLegumes(p.legumes)== 1){
        printf("Legumes   :   %d  🍆 🙂", p.legumes);
        afficher_barre(10, p.legumes);}
    else{
        printf("Legumes   :   %d  🍆 😎", p.legumes);
        afficher_barre(10, p.legumes);}
    
    if (hummeurFruits(p.fruits) == 0){
        printf("Fruits    :   %d  🍎 😢", p.fruits);
        afficher_barre(10, p.fruits);}
    else if (hummeurFruits(p.fruits)== 1){
        printf("Fruits    :   %d  🍎 🙂", p.fruits);
        afficher_barre(10, p.fruits);}
    else {
        printf("Fruits    :   %d  🍎 😄", p.fruits);
        afficher_barre(10, p.fruits);}
    
    printf("Proteines :   %d  🍖", p.proteines);
    afficher_barre(10, p.proteines);
    printf("==================================\n");
}


Consommation intialiser(){
    Consommation p;
    p.eau = 0;
    p.cafe =0;
    p.bonbons = 0;
    p.gateau = 0;
    p.legumes = 0;
    p.fruits = 0;
    p.proteines = 0;
    return p;
}

Consommation ajouterConsommation(Consommation p){
    int choix = 0;
    int quantite = 0;
    printf("Quelle catégorie souhaitez-vous modifier ? \n");
    printf("\n");
    printf("1) Eau 💧 \n");
    printf("2) Cafe ☕ \n");
    printf("3) Bonbons 🍬 \n");
    printf("4) gateau \n");
    printf("5) legumes \n");
    printf("6)Fruits \n");
    printf("7)Proteines \n");
    
    while((choix > 7) || (choix < 1)){
        printf("Votre choix : ");
        scanf("%d", &choix);
        if(choix <= 0){
            printf("choix invalide veuillez réessayer \n");
        }
        else if(choix > 7){
            printf("choix invalide veuillez réessayer \n");
        }

    }

    while(quantite <=  0){
        printf("Votre choix : ");
        scanf("%d", &quantite);
        if(quantite <= 0){
            printf("choix invalide veuillez réessayer \n");
        }

    }

    switch(choix){
        case 1 :
        p.eau += quantite;
        break;
        case 2 :
        p.cafe += quantite;
        break;
        case 3 : 
        p.bonbons += quantite;
        break;
        case 4 :
        p.gateau += quantite;
        break;
        case 5 : 
        p.legumes += quantite;
        break;
        case 6 : 
        p.fruits += quantite;
        break;
        case 7 :
        p.proteines += quantite;
        break;
    }

    printf("consommation mise à jour \n");
    return p;

}


void afficher_barre (int b, int a){
    int max = b;
    int val = a;

    if(max <= 0){
        max += 1;
    }

    if(val > max){
        val = max;
    }

    int casespleines = (val * 10)/max;

    printf("  ");

    for(int i =0; i<max ; i++){
        if(i < casespleines ){
            printf("█");
        }
        else if(i>= casespleines)
        {printf("░");}
    }
    printf("\n");
}