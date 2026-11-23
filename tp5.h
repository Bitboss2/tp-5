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

void affichermenu();
int choixUtilisateur();
void afficheresume(Consommation p);
#endif