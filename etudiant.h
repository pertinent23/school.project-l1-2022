#ifndef __ETUDIANT__H__
#define __ETUDIANT__H__

#define Max 10

typedef struct ETUDIANT
{
	int NCIN;
	char Nom[Max];
	char Prenom[Max];
	int Age;
	char Filiere[5];
	char Niveau[2];
	float Cotisation[5];

}ETUDIANT,*ETUD;

ETUD New(void);
void Saisir(FILE*,ETUD);
void Lire(ETUD,FILE*);
void Collect(ETUD);

#endif