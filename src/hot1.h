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
}date;
typedef struct
{int intjour;
int intmoi;
int intannee;
}intdate;

typedef struct {
	char usernames1[20];	
	char passwords1[20];	
	char nom[30];	
	char prenom[30];
	char prenom2[30];
	char contact[10];
	char CIN[10];
	char sexe;
	date date_nais;
	date *d_nais;
	char email[100];
	
} age;
typedef struct
{

char id[30];
char nom[30];
char pays[30];
char ville[30];
char etoiles[30];
char promo[30];
int jour;
int moi;
int annee;
int jourFin;
int moiFin;
int anneeFin;
}hotel;
typedef struct
{

char id1[20];
char nom1[20];
char pays1[20];
char ville1[20];
char etoiles1[20];
char promo[20];
int jour1;
int moi1;
int annee1;
}hotel2;


void ajouterss(hotel h);
void afficherss(GtkWidget *pListView);
/*int valid_mail(char x[]);
int verifier_agent();
void ajout_information(age ag);
void affiche_information(age *ag);

int verifi(age *ag,char user1[], char user2[]);*/

 void ajouthot(GtkWidget *pListView);
void suprimerss(char id[],char nom[],char pays[],char ville[], char etoiles []);
void modifierhotel(char id[],char nom[],char pays[],char ville[], char etoiles [],char promo[],char id1[],char nom1[],char pays1[],char ville1[], char etoiles1 [],char promo1[]);
/*void suprimer_hormed(char heure []);
void suprimer_hordiet( char heure []);*/
