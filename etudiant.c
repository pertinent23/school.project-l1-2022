#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"

ETUD New(void)
{
	return (ETUD)malloc(sizeof(ETUDIANT));
}
void Saisir(FILE *Fic,ETUD Etud)
{
	fprintf(Fic, "%d ; %s ; %s ; %d ; %s ; %s ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f \n",Etud->NCIN,Etud->Nom,Etud->Prenom,Etud->Age,Etud->Filiere,Etud->Niveau,Etud->Cotisation[0],Etud->Cotisation[1],Etud->Cotisation[2],Etud->Cotisation[3],Etud->Cotisation[4] );
}
void Lire(ETUD Etud,FILE *Fic)
{
	fscanf(Fic, "%d ; %s ; %s ; %d ; %s ; %s ; %f ; %f ; %f ; %f ; %f \n",&Etud->NCIN,Etud->Nom,Etud->Prenom,&Etud->Age,Etud->Filiere,Etud->Niveau,&Etud->Cotisation[0],&Etud->Cotisation[1],&Etud->Cotisation[2],&Etud->Cotisation[3],&Etud->Cotisation[4] );
}
void Collect(ETUD Etud)
{

	printf("NCIN : ");
	scanf("%d",&Etud->NCIN);
	printf("Nom : ");
	scanf("%s",Etud->Nom);
	printf("Prenom : ");
	scanf("%s",Etud->Prenom);
	printf("Age : ");
	scanf("%d",&Etud->Age);
	printf("Filiere : ");
	scanf("%s",Etud->Filiere);
	printf("Niveau : ");
	scanf("%s",Etud->Niveau);
	int i = 0;
	for (i; i < 5; ++i)
	{
		printf("Cotisation %d : ",i+1);
		scanf("%f",&Etud->Cotisation[i]);
	}
}
