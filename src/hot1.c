#include <gtk/gtk.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hot1.h"



//**************************************************************************************************************************


/*int valid_mail(char x[])
    {
   int count=0;
int countp=0;
int i,j;
int t,t2;
int k=0;
for(i=0 ; i<strlen(x) ; i++)
{
    if(x[i]=='@')
    {
        count++;
        t=i;
    }
}
if(count==1)
{
    for(j=0; j<t ; j++)
    {
        if(!(x[j]=='_' || x[j]=='.' || isalpha(x[j]) || isdigit(x[j])))
        {
            k=-1;
            break;
        }
    }
    if(k==0)
    {
        for(i=0; i>t ; i++)
        {
            if(x[i]=='.')
            {
      t2=i;
                countp++;
            }
        }
  if(countp==1)
        {
            for(i=0; i<t2 && i>t2; i++)
   {
                if(!(isalpha(x[i])))
   {
                    k=-1;
 break;
                }
                else
                {
                    k=1;
                }
            }
            if(k==1)
            {
  if(x[t2+3]!='\0')
                {
                    k=-1;
      }
            }
        }
        else
        {
            k=-1;
     }
   }
}
else
{
    k=-1;
}
return k;

}
//*************************************************************************************************************************
int controle_saisie_numero(char x[15])
{
int b=0;int a=0;
a=digital(x);
if (a==0)
{return 0;}
else {
b=atoi(x);
if((b>9999999)&&(b<=99999999))
{return 1;}
else {return 0;}
}
}
//********************************************************************************************************************

int digital(char x[15])
{
int res=0;
int i,a;
a=strlen(x);
for(i=0;i<=a;i++)
  {
    if (isdigit(x[i])!=0)
    {
      res=res+1;
    }
  }
  if(res==a)
      {return 1;}
    else {return 0;}

}
//*****************************************************************************************************************************
int verifier_agent()
{
	FILE* infoagent=NULL;
age *ag;


	infoagent=fopen("infoagent.txt", "a+");
	    if (infoagent != NULL)
{
if ((fscanf(infoagent,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",ag->nom, ag->prenom,ag->CIN,ag->contact,ag->date_nais.jour,ag->date_nais.moi,ag->date_nais.annee,ag->sexe,ag->email))==EOF)
return 1;
else
return -1;
}
}
//*****************************************************************************************************************************************
void ajout_information(age ag)
{
	FILE* infoagent=NULL;



	infoagent=fopen("infoagent.txt", "a+");
	    if (infoagent != NULL)
{
fprintf(infoagent,"%s %s %s %s %s %s %s %s %s\n",ag.nom, ag.prenom,ag.CIN,ag.contact,ag.date_nais.jour,ag.date_nais.moi,ag.date_nais.annee,ag.sexe,ag.email);

}
  fclose(infoagent);

}

//********************************************************************************************************************************************
void affiche_information (age *ag)
{
		FILE* infoagent=NULL;




	infoagent=fopen("infoagent.txt", "r");
	    if (infoagent != NULL)
            {while(fscanf(infoagent,"%s %s %s %s %s %s %s %s %s", ag->nom, ag->prenom,ag->CIN,ag->contact,ag->date_nais.jour,ag->date_nais.moi,ag->date_nais.annee,ag->sexe,ag->email)!=EOF){


fscanf(infoagent,"%s %s %s %s %s %s %s %s %s",ag->nom, ag->prenom,ag->CIN,ag->contact,ag->date_nais.jour,ag->date_nais.moi,ag->date_nais.annee,ag->sexe,ag->email);
}
}
  fclose(infoagent);



}

//*******************************************************************************************************************************************
/*void affichemed(age *ag)
{
		FILE* fichemed=NULL;



	fichemed=fopen("fichemed.txt", "r");
	    if (fichemed != NULL)
            {


fscanf(fichemed,"%s %s %s",ad->allergie, ad->cond_med,ad->commentairemed);

}
  fclose(fichemed);}*/




//*************************************************************************************************************************
/*void affichediet(adh *ad)
{
		FILE* fichediet=NULL;



	fichediet=fopen("fichediet.txt", "r");
	    if (fichediet != NULL)
            {


fscanf(fichediet,"%s %s %s",ad->poids, ad->taille,ad->commentairediet);

}
  fclose(fichediet);}*/





//******************************************************************************************************************************
void ajouterss(hotel h)
{




FILE *f;

f=fopen("hotel1.txt","a+");  
if (f!=NULL)
{
  
  fprintf(f,"%s %s %s %s %s %s\n",h.id,h.nom,h.pays,h.ville,h.etoiles,h.promo);


}
fclose(f);
}

//****************************************************************************************************************************************
void afficherss(GtkWidget *pListView)
{
enum {
ID,
NOM,
PAYS,
VILLE,
ETOILES,
PROMO,
TOGGLE_COLUMN,
N_COLUMN
};

GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore=gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN);

FILE *f;
	char id [30];
	char nom [30];
	char pays [30];
	char ville [30];
        char etoiles[30];
	char promo[30];

f=fopen("hotel1.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",id,nom,pays,ville,etoiles,promo)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter, ID, id, NOM, nom, PAYS, pays, VILLE, ville, ETOILES, etoiles,PROMO, promo, TOGGLE_COLUMN, TRUE, -1);
	}
fclose(f);

void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);


}

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("ID",pCellRenderer,"text", ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("NOM",pCellRenderer,"text", NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("PAYS",pCellRenderer,"text", PAYS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("VILLE",pCellRenderer,"text", VILLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("ETOILES",pCellRenderer,"text", ETOILES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("PROMO",pCellRenderer,"text", PROMO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn = gtk_tree_view_column_new_with_attributes("SELECTION",pCellRenderer,"active", TOGGLE_COLUMN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	








gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
    g_object_unref (pListStore);


	
}

//******************************************************************************************************
 void ajouthot(GtkWidget *pListView)
{
enum {
ID,
NOM,
PAYS,
VILLE,
ETOILES,
PROMO,
TOGGLE_COLUMN,
N_COLUMN
};
	char id [30];
	char nom [30];
	char pays[30] ;
	char ville[30] ;
        char etoiles[30];
	char promo[30];
GtkListStore *pListStore;
pListStore=gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN);

FILE *f;
f=fopen("hotel1.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",id,nom,pays,ville,etoiles,promo)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
    gboolean boolean;
gtk_list_store_set(pListStore, &pIter, ID, id, NOM, nom, PAYS, pays, VILLE, ville, ETOILES, etoiles, PROMO ,promo, TOGGLE_COLUMN, TRUE, -1);
	}
gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
    g_object_unref (pListStore);
}

//******************************************************************************************************

void suprimerss(char id[],char nom[],char pays[],char ville[], char etoiles [])
{
  FILE *f;
  FILE *f1;

  char ch[20], ch1[20],ch2[20], ch3[20], ch4[20], ch5[20];


f=fopen("hotel1.txt","r"); 
f1=fopen("hotel2.txt","w");   


if (f1!=NULL && f!=NULL)
{    while(fscanf(f,"%s %s %s %s %s %s",ch,ch1,ch2,ch3,ch4,ch5) != EOF)
  {  

 if (strcmp(ch,id)==0 && strcmp(ch4,etoiles) == 0 && strcmp(ch1,nom) == 0 && strcmp(ch2,pays) == 0 && strcmp(ch3,ville) == 0)
  fprintf(f1,"%s","");
else
  fprintf(f1,"%s %s %s %s %s %s\n",ch,ch1,ch2,ch3,ch4,ch5);
}
}
  fclose(f);
  fclose(f1);

  remove("hotel1.txt");
  rename("hotel2.txt","hotel1.txt");

}

//******************************************************************************************************
void modifierhotel(char id[],char nom[],char pays[],char ville[],char etoiles[] ,char promo[],char id1[],char nom1[],char pays1[],char ville1[],char etoiles1[],char promo1[])
{
  FILE *f;
  FILE *f1;

  char ch[20], ch1[20], ch2[20], ch3[20], ch4[20], ch5[20];

f=fopen("hotel1.txt","r"); 
f1=fopen("hotel2.txt","a");   


if (f1!=NULL && f!=NULL)
{    while(fscanf(f,"%s %s %s %s %s %s",ch,ch1,ch2,ch3,ch4,ch5) != EOF)
  {  

 if (strcmp(ch,id)==0  && strcmp(ch4,etoiles) == 0 && strcmp(ch1,nom) == 0 && strcmp(ch2,pays) == 0 && strcmp(ch3,ville) == 0 && strcmp(ch5,promo) == 0 )
  fprintf(f1,"%s %s %s %s %s %s\n",id1,nom1,pays1,ville1,etoiles1,promo1);
else
  fprintf(f1,"%s %s %s %s %s %s\n",ch,ch1,ch2,ch3,ch4,ch5);
}
}
  fclose(f);
  fclose(f1);
  remove("hotel1.txt");
  rename("hotel2.txt","hotel1.txt");

}


//**********************************************************************************************************************************

/*void suprimer_hormed( char heure [])
{
  FILE *f;
  FILE *f1;

  char ch[20], ch1[20];
int a,b,c;


f=fopen("horaire.txt","r"); 
f1=fopen("rdv.txt","w");   


if (f1!=NULL && f!=NULL)
{    while(fscanf(f," %d %d %d %s ", &a ,&b, &c, ch)!=EOF)
  {  

 if (strcmp(ch,heure) == 0)
  fprintf(f1,"%s","");
else
  fprintf(f1," %d %d %d %s \n",a,b,c,ch);
}
}
  fclose(f);
  fclose(f1);

  remove("horaire.txt");
  rename("rdv.txt","horaire.txt");

}

//**********************************************************************************************************************************

void suprimer_hordiet(char heure [])
{
  FILE *f;
  FILE *f1;

  char ch[20], ch1[20];
int a,b,c;


f=fopen("horairey.txt","r"); 
f1=fopen("rdv.txt","w");   


if (f1!=NULL && f!=NULL)
{    while(fscanf(f," %d %d %d %s ", &a ,&b, &c, ch)!=EOF)
  {  

 if (strcmp(ch,heure) == 0)
  fprintf(f1,"%s","");
else
  fprintf(f1," %d %d %d %s \n",a,b,c,ch);
}
}
  fclose(f);
  fclose(f1);

  remove("horairey.txt");
  rename("rdv.txt","horairey.txt");}*/


