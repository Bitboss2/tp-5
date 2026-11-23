#include <stdio.h>
#include "tp5.h"


void affichermenu()
{
    printf("=========================\n");
    printf("  Suivi de consommation\n");
    printf("=========================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Afficher les objectifs et le score\n");
    printf("4. Sauvegarder et quitter\n");
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
    printf("Eau       :   %d  💧\n", p.eau);
    printf("Cafe      :   %d  ☕\n", p.cafe);
    if (hummeurBonbons(p.bonbons) == 0)
        printf("Bonbons   :   %d  🍬 😇\n", p.bonbons);
    else if (hummeurBonbons(p.bonbons)== 1)
        printf("Bonbons   :   %d  🍬 🙂\n", p.bonbons);
    else if (hummeurBonbons(p.bonbons)== 2)
        printf("Bonbons   :   %d  🍬 😕\n", p.bonbons);
    else    
        printf("Bonbons   :   %d  🍬 👿\n", p.bonbons);
    printf("Gateau    :   %d  🍰\n", p.gateau); 
    if (hummeurLegumes(p.legumes) == 0)
        printf("Legumes   :   %d  🍆 😭\n", p.legumes);
    else if (hummeurLegumes(p.legumes)== 1)
        printf("Legumes   :   %d  🍆 🙂\n", p.legumes);
    else 
        printf("Legumes   :   %d  🍆 😎\n", p.legumes);
    
    if (hummeurFruits(p.fruits) == 0)
        printf("Fruits    :   %d  🍎 😢\n", p.fruits);
    else if (hummeurFruits(p.fruits)== 1)
        printf("Fruits    :   %d  🍎 🙂\n", p.fruits);
    else 
        printf("Fruits    :   %d  🍎 😄\n", p.fruits);
    
    printf("Proteines :   %d  🍖\n", p.proteines);
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

int calculerScoreSante(Consommation p, Objectif v)
{
    int score = 50;
    if (p.eau > v.eau)
        score += 10;
    if (p.legumes > v.legume)
        score += 10;
    if (p.fruits > v.fruit)
        score += 10;
    if (p.proteines > v.proteine)
        score += 10;
    if (p.bonbons > 5)
    {
        if (p.bonbons - 5 > 15) {
            score -= 15;
        } else {
            score = score - p.bonbons - 5;
        }
    }
    if (p.cafe > 3)
    {
        int temp = p.cafe - 3;
        if (temp > 10) {
            score -= 20;
        } else {
            score += temp*2;
        }
    }
    if (score > 100) score = 100;
    if (score < 0) score = 0;
    return score;
}

void afficherObjectifScore(Consommation p, Objectif v)
{
    if (p.eau < v.eau)
        printf("Eau       :   %d  ❌\n", v.eau);
    else
        printf("Eau       :   %d  ✅\n", v.eau);
    printf("Cafe      :   _ (pas d'objectif)\n");
    printf("Bonbons   :   _ (pas d'objectif)\n");
    printf("Gateau    :   _ (pas d'objectif)\n");
    if (p.legumes < v.legume)
        printf("Legumes   :   %d  ❌\n", v.legume);
    else
        printf("Legumes   :   %d  ✅\n", v.legume);
    
    if (p.fruits < v.fruit)
        printf("Fruit     :   %d  ❌\n", v.fruit);
    else
        printf("Fruit     :   %d  ✅\n", v.fruit);

    if (p.fruits < v.fruit)
        printf("Proteines :   %d  ❌\n", v.proteine);
    else
        printf("Proteines :   %d  ✅\n", v.proteine);
    int g = calculerScoreSante(p, v);
    printf("Score sante du jour : %d / 100", g);
}