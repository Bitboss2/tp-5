#ifndef CONSOMMATION
#define CONSOMMAION

void affichermenu();
int choixUtilisateur();

typedef struct Consommation {
    int eau;
    int cafe;
    int bonbons;
    int gateau;
    int legumes;
    int fruits;
    int proteines;
}Consommation;

#endif