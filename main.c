#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"
#include "fonction.h"

int main(void)
{
	int Launche = 1;
	int Choix;

	while(Launche)
	{
		printf(" 1.Ajouter \n 2.Modifier \n 3.Supprimer \n 4.Afficher \n 5.Solvable \n 6.Insolvable \n 7.Statistiques \n 8.Supprimer \n 9.Recherche \n 10.Quitter\n");
		printf("Entrez Votre Choix :");
		scanf("%d",&Choix);
		
		switch(Choix)
		{
			case 1:
				Ajouter();
				break;
			case 2:
				Modifier();
				break;
			case 3:
				//Supprimer();
				break;
			case 4:
				affiche();
				break;
			case 5:
				solvable();
				break;
			case 6:
				insolvable();
				break;
			case 7:
				statistiques();
				break;
			case 8:
				Suppression();
				break;
			case 9:
				//recherche();
				break;
			case 0:
				break;
			default:
				printf("Entrez une Option !!\n");
				break;
		}		
	}

	return 0;
}
