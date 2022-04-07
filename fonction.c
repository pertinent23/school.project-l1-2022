#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"

#define MaxEtud 1000
#define Lien "etudiant.txt"

void Ajouter(void)
{
	FILE *Fic=fopen(Lien,"r");
	ETUDIANT Nouveau;

	Collect(&Nouveau);

	if(Fic != NULL)
	{
		ETUDIANT Etud;
		int Trouvre = 0;
		while(!feof(Fic) && !Trouvre)
		{
			Lire(&Etud,Fic);
			if(Etud.NCIN == Nouveau.NCIN)
				Trouvre = 1;
		}
		fclose(Fic);
		if(!Trouvre)
		{
			Fic = fopen(Lien,"a");
			Saisir(Fic,&Nouveau);
			fclose(Fic);
		}
		else
			printf(">>> Etudiant deja enregistre !\n");
	}
	else
	{
		Fic = fopen(Lien,"w");
		Saisir(Fic,&Nouveau);
		fclose(Fic);
	}
	return;
}
void Modifier(void)
{
	FILE *Fic = fopen(Lien,"r");
	int NCIN;
	printf(">>> Entrez NCIN :");
	scanf("%d",&NCIN);
	if(Fic != NULL)
	{
		ETUD Tab[MaxEtud];
		int N = 0;
		int Trouvre=-1;
		while(!feof(Fic))
		{
			Tab[N] = New();
			Lire(Tab[N],Fic);
			if (NCIN==Tab[N]->NCIN)
				Trouvre=N;
			N++;
		}
		
		if(Trouvre !=-1)
		{
			Collect(Tab[N]);
			fclose(Fic);
			Fic=fopen(Lien,"w");
			while(N>=0)
			{
				Saisir(Fic,Tab[N]);
				free(Tab[N]);
				N--;
			}
			fclose(Fic);
		}
		else 
			printf(">>> Etudiant inexistant\n");
	}
	printf(">>> Etudiant inexistant\n");
	return;	

}
void Supprimer(int NCIN)
{
	FILE *Fic = fopen(Lien,"r");
	if(Fic != NULL)
	{
		ETUD Tab[MaxEtud];
		int N = 0;
		int Trouvre=-1;
		while(!feof(Fic))
		{
			Tab[N] = New();
			Lire(Tab[N],Fic);
			N++;
		}
		fclose(Fic);
		Fic=fopen(Lien,"w");
		while(N>=0)
		{
			if(NCIN !=Tab[N]->NCIN)
				Saisir(Fic,Tab[N]);
			free(Tab[N]);
			N--;
		}
		fclose(Fic);
	}
	return;
}
void affiche(void)
{
	FILE *Fic = fopen(Lien,"r");
	if(Fic != NULL)
	{
		ETUDIANT Etud;
		int N = 0;
		float Total = 0;

		while(!feof(Fic))
		{
			Lire(&Etud,Fic);
			printf(">>> %d %s %s \n",Etud.NCIN,Etud.Nom,Etud.Prenom);
			Total += Etud.Cotisation[0]+Etud.Cotisation[1]+Etud.Cotisation[2]+Etud.Cotisation[3]+Etud.Cotisation[4];
			N++;
		}
		fclose(Fic);
		printf("Total Cotisation :%.2f",Total);
	}
	return;
}
void solvable(void)
{
	FILE *Fic = fopen(Lien,"r");
	ETUDIANT Etud;
	if(Fic != NULL)
	{
		FILE *Fic1 = fopen("etat.txt","w");
		float Total = 0;
		while(!feof(Fic))
		{
			Lire(&Etud,Fic);
			Total += Etud.Cotisation[0]+Etud.Cotisation[1]+Etud.Cotisation[2]+Etud.Cotisation[3]+Etud.Cotisation[4];
			printf(">>> %d %s %s %.2f\n",Etud.NCIN,Etud.Nom,Etud.Prenom,Total);
			fprintf(Fic1,"%d %s %s %.2f\n",Etud.NCIN,Etud.Nom,Etud.Prenom,Total);
		}
		fclose(Fic1);
		fclose(Fic);
	}
}
void insolvable(void)
{
	FILE *Fic = fopen(Lien,"r");
	if(Fic != NULL)
	{
		FILE *Fic1 = fopen("mauvais.txt","w");
		ETUDIANT Etud;
		float Total;
		while(!feof(Fic))
		{
			Lire(&Etud,Fic);
			Total = Etud.Cotisation[0]+Etud.Cotisation[1]+Etud.Cotisation[2]+Etud.Cotisation[3]+Etud.Cotisation[4];
			if(Etud.Cotisation[0] == 0 || Etud.Cotisation[1] == 0 || Etud.Cotisation[2] == 0 || Etud.Cotisation[3] == 0 || Etud.Cotisation[4] == 0)
			{
				fprintf(Fic1,"%d %s %s %.2f\n",Etud.NCIN,Etud.Nom,Etud.Prenom,Total);
			}
		}
		fclose(Fic1);
		fclose(Fic);
	}
}
void statistiques(void)
{

}
void Suppression(void)
{

}

void recherche(int NCIN)
{

}