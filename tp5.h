#ifndef CONSOMMATION
#define CONSOMMAION

typedef struct Consommation {
    int eau;
    int cafe;
    int bonbons;
    int gateau;
    int legumes;
    int fruits;
    int proteines;
}Consommation;

typedef struct {
    int eau;
    int legume;
    int fruit;
    int proteine;
} Objectif;

void affichermenu();
int choixUtilisateur();
void afficheresume(Consommation p);
Consommation intialiser();
Consommation ajouterConsommation(Consommation p);
<<<<<<< HEAD
void afficher_barre (int b, int a);
=======
void afficherObjectifScore(Consommation p, Objectif v);
>>>>>>> 4e3175472d09847f9718203d97d12b36128bc612
#endif