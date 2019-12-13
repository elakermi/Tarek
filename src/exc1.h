#include <gtk/gtk.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char l[20]; char p[20]; 
typedef struct
{
char jour[10];
char moi[10];
char annee[10];
}date1;
typedef struct
{int intjour;
int intmoi;
int intannee;
}intdate1;

/*typedef struct {
	char usernames1[20];	
	char passwords1[20];	
	char nom[30];	
	char prenom[30];
	char prenom2[30];
	char contact[10];
	char CIN[10];
	char sexe;
	date1 date_nais;
	date1 *d_nais;
	char email[100];
	
} age;*/
typedef struct
{

char id[30];
char villedepart[30];
char villearrive[30];
char jourexcu[30];
char heure[30];
char promo[30];
/*char voyageur[30];*/
char prix[30];
int jour;
int moi;
int annee;
}excursion;
typedef struct
{

char id1[20];
char villedepart1[20];
char villearrive1[20];
char jourexcu1[20];
char heure1[20];
char promo[20];
int jour1;
int moi1;
int annee1;
}excursion2;


void ajouterss1(excursion e);
void afficherss1(GtkWidget *pListView);
/*int valid_mail(char x[]);*/
/*int verifier_agent();
void ajout_information(age ag);
void affiche_information(age *ag);
/*void affichemed(age *ag);
void affichediet(age *ag);*/
/*int verifi(age *ag,char user1[], char user2[]);*/
void reserver_exc(excursion2 e2, char ide[20]);
 void ajoutexc(GtkWidget *pListView);
void suprimerss1(char id[],char villedepart[],char villearrive[],char jourexcu[], char heure [],char promo[]);
void modifierexcursion(char id[],char villedepart[],char villearrive[],char jourexcu[], char heure [],char promo[],char id1[],char villedepart1[],char villearrive1[],char jourexcu1[], char heure1 [],char promo1[]);
/*void suprimer_hormed(char heure []);
void suprimer_hordiet( char heure []);*/
