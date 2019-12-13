#include <gtk/gtk.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "profil.h"



int valid_mail(char x[])
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

