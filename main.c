#include <stdio.h>
#include "tp5.h"

int main()
{
    int choix = 0;
    do {
        affichermenu;
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    } while (choix != 3); 
    return 0;
}