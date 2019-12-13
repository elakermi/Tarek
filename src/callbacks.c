#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <gtk/gtkwidget.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "hot1.h"
#include "exc1.h"

//******************************************************************************************************************************
void
on_saves1_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom1;	
GtkWidget *prenom1;
GtkWidget *CIN1;
GtkWidget *sexe1;
GtkWidget *email1;
GtkWidget *contact1;

GtkWidget *jour1;
GtkWidget *moi1;
GtkWidget *annee1;
age ag,*Page;

	Page=malloc(sizeof(age));
	nom1=lookup_widget(objet_graphique,"entry1");
	prenom1=lookup_widget(objet_graphique,"entry2");
	sexe1=lookup_widget(objet_graphique,"combobox3");
	CIN1=lookup_widget(objet_graphique,"entry3");
	contact1=lookup_widget(objet_graphique,"entry7");
	email1=lookup_widget(objet_graphique,"entry6");
	
	jour1=lookup_widget(objet_graphique,"comboboxs1");
	moi1=lookup_widget(objet_graphique,"comboboxs2");
	annee1=lookup_widget(objet_graphique,"comboboxs3");
affiche_information(Page);

  gtk_entry_set_text (GTK_ENTRY (nom1), _(Page->nom));
  gtk_entry_set_text (GTK_ENTRY (prenom1), _(Page->prenom));
  gtk_entry_set_text (GTK_ENTRY (CIN1), _(Page->CIN));
  
  gtk_entry_set_text (GTK_ENTRY (contact1), _(Page->contact));
  gtk_entry_set_text (GTK_ENTRY (email1), _(Page->email));
 
}



//******************************************************************************************************************************


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* windows1;
GtkWidget* admin;
GtkWidget* entry1;


windows1=create_windows1();
   gtk_widget_show (windows1);

admin=lookup_widget(button,"admin");

gtk_widget_hide(admin);
}
//******************************************************************************************************************************



void
on_enregs1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom1;	
GtkWidget *prenom1;
GtkWidget *CIN1;
GtkWidget *sexe1;
GtkWidget *email1;
GtkWidget *contact1;

GtkWidget *jour1;
GtkWidget *moi1;
GtkWidget *annee1;

age ag;
	nom1=lookup_widget(objet_graphique,"entry1");
	prenom1=lookup_widget(objet_graphique,"entry2");
	sexe1=lookup_widget(objet_graphique,"combobox3");
	CIN1=lookup_widget(objet_graphique,"entry3");
	contact1=lookup_widget(objet_graphique,"entry7");
	email1=lookup_widget(objet_graphique,"entry6");
	
	jour1=lookup_widget(objet_graphique,"comboboxs1");
	moi1=lookup_widget(objet_graphique,"comboboxs2");
	annee1=lookup_widget(objet_graphique,"comboboxs3");
strcpy(ag.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(ag.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(ag.contact,gtk_entry_get_text(GTK_ENTRY(contact1)));
strcpy(ag.CIN,gtk_entry_get_text(GTK_ENTRY(CIN1)));
strcpy(ag.date_nais.jour,gtk_combo_box_get_active(GTK_COMBO_BOX(jour1)));
strcpy(ag.date_nais.moi,gtk_combo_box_get_active(GTK_COMBO_BOX(moi1)));
strcpy(ag.date_nais.annee,gtk_combo_box_get_active(GTK_COMBO_BOX(annee1)));
strcpy(ag.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));

strcpy(ag.email,gtk_entry_get_text(GTK_ENTRY(email1)));


ajout_information(ag);


}

//*******************************************************************************************************************************
void
on_enregistrerinfo_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom1;	
GtkWidget *prenom1;
GtkWidget *CIN1;
GtkWidget *sexe1;
GtkWidget *email1;
GtkWidget *contact1;

GtkWidget *jour1;
GtkWidget *moi1;
GtkWidget *annee1;
GtkWidget *imageerreur1;
age ag;
	nom1=lookup_widget(objet_graphique,"modifiernom");
	prenom1=lookup_widget(objet_graphique,"modifierprenom");
	sexe1=lookup_widget(objet_graphique,"modifiersexe");
	CIN1=lookup_widget(objet_graphique,"modifiercin");
	contact1=lookup_widget(objet_graphique,"modifiertele");
	email1=lookup_widget(objet_graphique,"modifieremail");
	jour1=lookup_widget(objet_graphique,"modifierjourn");
	moi1=lookup_widget(objet_graphique,"modifiermoin");
	annee1=lookup_widget(objet_graphique,"modifieranneen");
strcpy(ag.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(ag.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(ag.contact,gtk_entry_get_text(GTK_ENTRY(contact1)));
strcpy(ag.email,gtk_entry_get_text(GTK_ENTRY(email1)));
strcpy(ag.CIN,"14240248");

int a=0;
if(digital(ag.contact)!=0 && controle_saisie_numero(ag.contact)!=0)

{



imageerreur1=lookup_widget(objet_graphique,"erreurs6");
 gtk_widget_hide (imageerreur1);a=1;
}
else 
{	imageerreur1=lookup_widget(objet_graphique,"erreurs6");
 gtk_widget_show (imageerreur1);
}
if(gtk_combo_box_get_active (sexe1)!=-1)

{
strcpy(ag.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));


imageerreur1=lookup_widget(objet_graphique,"erreurs5");
 gtk_widget_hide (imageerreur1);a=1;
}
else 
{	imageerreur1=lookup_widget(objet_graphique,"erreurs5");
 gtk_widget_show (imageerreur1);
}
if((gtk_combo_box_get_active (jour1)!=-1) && (gtk_combo_box_get_active (moi1)!=-1)&&(gtk_combo_box_get_active (annee1)!=-1))

{
strcpy(ag.date_nais.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour1)));
strcpy(ag.date_nais.moi,gtk_combo_box_get_active_text(GTK_COMBO_BOX(moi1)));
strcpy(ag.date_nais.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee1)));
imageerreur1=lookup_widget(objet_graphique,"erreurs4");
 gtk_widget_hide (imageerreur1);
a=1;
}
else 
{	imageerreur1=lookup_widget(objet_graphique,"erreurs4");
 gtk_widget_show (imageerreur1);a=0;
}

if (a==1)
ajout_information(ag);

}

//******************************************************************************************************************************
void
on_afficherhot_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget  *pListView     ;
window3 = lookup_widget(objet_graphique,"windows1"); 
pListView = lookup_widget(window3,"treeviews1");

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
gtk_list_store_set(pListStore, &pIter, ID, id, NOM, nom, PAYS, pays, VILLE, ville, ETOILES, etoiles, PROMO, promo, TOGGLE_COLUMN, TRUE, -1);
	}
fclose(f);

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
pColumn = gtk_tree_view_column_new_with_attributes("CheckBox",pCellRenderer,"active", TOGGLE_COLUMN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
    g_object_unref (pListStore);


}

//******************************************************************************************************************************
void
on_supprimerhot_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
	gchar *id;
  	gint *nom;
	gint *pays;
	gint *ville;
	gchar *etoiles;
	gchar *promo;
   
	GtkWidget *nomm;
	GtkWidget *payss;	
	GtkWidget *villee;
	GtkWidget *idd;
	GtkWidget *etoiless;
	GtkWidget *promoo;
	GtkWidget *window;
	GtkWidget *test;
	GtkWidget *test1;
  GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;

	GtkWidget *list;
list=lookup_widget(objet_graphique, "treeviews1");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
  if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {


    gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nom, 2, &pays, 3, &ville, 4, &etoiles, 5, &promo, -1);}


suprimerss(id,nom,pays,ville,etoiles);

GtkWidget *pListView;
	pListView=lookup_widget(objet_graphique,"treeviews1");
ajouthot(pListView);
     

   }




//******************************************************************************************************************************


void
on_windows1_show                       (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget  *listeview     ;
window3 = lookup_widget(widget,"windows1"); 
listeview = lookup_widget(window3,"treeviews1");
afficherss(listeview);

}

//******************************************************************************************************************************
void
on_profilemodifier_show                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nom1;	
GtkWidget *prenom1;
GtkWidget *CIN1;
GtkWidget *email1;
GtkWidget *tele1;
GtkWidget *sexe1;
age ag,*Page;

Page=malloc(sizeof(age));

	nom1=lookup_widget(objet_graphique,"modifiernom");
	prenom1=lookup_widget(objet_graphique,"modifierprenom");
	email1=lookup_widget(objet_graphique,"modifieremail");
	CIN1=lookup_widget(objet_graphique,"modifiercin");
	tele1=lookup_widget(objet_graphique,"modifiertele");
	sexe1=lookup_widget(objet_graphique,"modifiersexe");

affiche_information(Page);

  gtk_entry_set_text (GTK_ENTRY (nom1), _(Page->nom));
  gtk_entry_set_text (GTK_ENTRY (prenom1), _(Page->prenom));
  gtk_label_set_text (GTK_ENTRY (CIN1), _(Page->CIN));
  gtk_entry_set_text (GTK_ENTRY (tele1), _(Page->contact));
  gtk_entry_set_text (GTK_ENTRY (email1), _(Page->email));


 GdkColor color;
  gdk_color_parse ("#C99FEB", &color);
  
GtkWidget *color1;
	color1=lookup_widget(objet_graphique,"profilemodifier");
  gtk_widget_modify_base (color1, GTK_STATE_NORMAL, &color);

}

//******************************************************************************************************************************
gboolean
on_windows1_enter_notify_event         (GtkWidget       *objet_graphique,
                                        GdkEventCrossing *event,
                                        gpointer         user_data)
{
GtkWidget* nom1;	
GtkWidget *prenom1;
GtkWidget *CIN1;
GtkWidget *sexe1;
GtkWidget *email1;
GtkWidget *contact1;

GtkWidget *jour1;
GtkWidget *moi1;
GtkWidget *annee1;

int a;
age *ag,*Page;

	Page=malloc(sizeof(age));
	nom1=lookup_widget(objet_graphique,"noms1");

	prenom1=lookup_widget(objet_graphique,"prenoms1");
	sexe1=lookup_widget(objet_graphique,"sexes1");
	CIN1=lookup_widget(objet_graphique,"cins1");
	contact1=lookup_widget(objet_graphique,"telephones1");
	email1=lookup_widget(objet_graphique,"emails1");
	
	jour1=lookup_widget(objet_graphique,"jours1");
	moi1=lookup_widget(objet_graphique,"mois1");
	annee1=lookup_widget(objet_graphique,"annees1");
	


		FILE* infoagent=NULL;
	infoagent=fopen("infoagent.txt", "r");
	    if (infoagent != NULL)
            {while(fscanf(infoagent,"%s %s %s %s %s %s %s %s %s", Page->nom, Page->prenom,Page->CIN,Page->contact,Page->date_nais.jour,Page->date_nais.moi,Page->date_nais.annee,Page->sexe,Page->email)!=EOF){

fscanf(infoagent,"%s %s %s %s %s %s %s %s %s",Page->nom, Page->prenom,Page->CIN,Page->contact,Page->date_nais.jour,Page->date_nais.moi,Page->date_nais.annee,Page->sexe,Page->email);

	if (strncmp("14240248",Page->CIN,20)==0) 
{


  

  gtk_label_set_text(GTK_LABEL (nom1), _(Page->nom));

  gtk_label_set_text(GTK_LABEL (prenom1), _(Page->prenom));
  gtk_label_set_text(GTK_LABEL (CIN1), _(Page->CIN));
  gtk_label_set_text(GTK_LABEL (contact1), _(Page->contact));

  {gtk_label_set_text(GTK_LABEL (email1), _(Page->email));}
  
  
  gtk_label_set_text(GTK_LABEL (jour1), _(Page->date_nais.jour));
  gtk_label_set_text(GTK_LABEL (moi1), _(Page->date_nais.moi));
  gtk_label_set_text(GTK_LABEL (annee1), _(Page->date_nais.annee));
  gtk_label_set_text(GTK_LABEL (sexe1), _(Page->sexe));
  
}
}
}  fclose(infoagent);





  return FALSE;
}

//******************************************************************************************************************************


void
on_Modifierprofile_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
                GtkWidget* modifierprofile;

modifierprofile=create_profilemodifier ();
  gtk_widget_show (modifierprofile);

}

//******************************************************************************************************************************


void
on_deconnects1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window1;
GtkWidget* admin;


	window1=lookup_widget(button,"windows1");
admin=create_admin();
   gtk_widget_hide (window1);



gtk_widget_show(admin);
}


//******************************************************************************************************************************

void
on_quittertree_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}

//******************************************************************************************************************************
void
on_quitterss1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window1;
GtkWidget* admin;


	window1=lookup_widget(button,"windows1");
admin=create_admin();
   gtk_widget_hide (window1);



gtk_widget_show(admin);
}

//******************************************************************************************************************************



void
on_quittrermodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* window1;


	window1=lookup_widget(button,"profilemodifier");

   gtk_widget_destroy (window1);



gtk_widget_show(window1);
}


void
on_quitterinfo_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_ajthot_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *jour;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *moi;
GtkWidget *annee;
GtkWidget *combobox7;
GtkWidget *combobox8;
GtkWidget *label20;
hotel h;
hotel2 h2;
GtkWidget *jourFin;
GtkWidget *moiFin;
GtkWidget *anneeFin;

GtkWidget *nom;
GtkWidget *id;
GtkWidget *pays;
GtkWidget *ville;


combobox7=lookup_widget(objet_graphique, "etoiles");
combobox8=lookup_widget(objet_graphique, "promohot");

jour=lookup_widget(objet_graphique, "jourhot");
moi=lookup_widget(objet_graphique, "moihot");
annee=lookup_widget(objet_graphique, "anneehot");

jourFin=lookup_widget(objet_graphique, "jourFin");
moiFin=lookup_widget(objet_graphique, "moiFin");
anneeFin=lookup_widget(objet_graphique, "anneeFin");



h.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
h.moi=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moi));
h.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

h.jourFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jourFin));
h.moiFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moiFin));
h.anneeFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (anneeFin));


	id=lookup_widget(objet_graphique,"id");
	nom=lookup_widget(objet_graphique,"nom");
	pays=lookup_widget(objet_graphique,"pays");
	ville=lookup_widget(objet_graphique,"ville");
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(h.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
strcpy(h.ville,gtk_entry_get_text(GTK_ENTRY(ville)));




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

GtkWidget *combobox1;

GtkWidget *image;
GtkTreeIter pIter;
GtkListStore *pListStore;
pListStore=gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN);
GtkWidget *pListView;
	pListView=lookup_widget(objet_graphique,"treeviews1");
combobox1=lookup_widget(objet_graphique, "etoiles");

int a;
if(gtk_combo_box_get_active (combobox8)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_hide (image);



a=1;
}
else 
{	image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_show (image);a=0;
}

if(gtk_combo_box_get_active (combobox7)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_hide (image);



a=1;
}
else 
{	image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_show (image);
a=0;
}
if (a==1)
{
strcpy(h.promo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));
strcpy(h.etoiles,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
//gtk_combo_box_remove_text (GTK_COMBO_BOX (combobox1), gtk_combo_box_get_active (GTK_COMBO_BOX (combobox1)));
ajouterss(h);
ajouthot(pListView);

}

}





void
on_treeviews1_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	

}




void
on_modifierhot_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *verifi;
GtkWidget *test,*b1,*b2,*b3;

verifi=lookup_widget(GTK_WIDGET(objet_graphique),"verifi");
b1=lookup_widget(objet_graphique, "enrmodification");
b2=lookup_widget(objet_graphique, "annulermodification");
b3	=lookup_widget(objet_graphique, "ajthot");

 gtk_widget_show (b1);
 gtk_widget_show (b2);

    gtk_label_set_text(GTK_LABEL(verifi),"veuiller modifier votre hotel");

 gtk_widget_hide (b3);



}








void
on_item3_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{


}




void
on_test1_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_enrmodification_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

	gchar *id;
  	gchar *nom;
	gchar *pays;
	gchar *ville;
	gchar *etoiles;
	gchar *promo;
   
	GtkWidget *nomm;
	GtkWidget *payss;	
	GtkWidget *villee;
	GtkWidget *idd;
	GtkWidget *etoiless;
	GtkWidget *promoo;
	GtkWidget *window;
	GtkWidget *test;
	GtkWidget *test1;
  GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;

	GtkWidget *list;
list=lookup_widget(objet_graphique, "treeviews1");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
  if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {


    gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nom,2,&pays,3,&ville,4,&etoiles,5,&promo, -1);}




     



GtkWidget *jour1;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *moi1;
GtkWidget *annee1;
GtkWidget *combobox7;
GtkWidget *combobox8;
GtkWidget *label20;

hotel h;


combobox7=lookup_widget(objet_graphique, "etoiles");
combobox8=lookup_widget(objet_graphique, "promohot");

jour1=lookup_widget(objet_graphique, "jourhot");
moi1=lookup_widget(objet_graphique, "moihot");
annee1=lookup_widget(objet_graphique, "anneehot");

idd=lookup_widget(objet_graphique, "id");
nomm=lookup_widget(objet_graphique, "nom");
payss=lookup_widget(objet_graphique, "pays");
villee=lookup_widget(objet_graphique, "ville");


h.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
h.moi=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moi1));
h.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));

strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nomm)));
strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(h.pays,gtk_entry_get_text(GTK_ENTRY(payss)));
strcpy(h.ville,gtk_entry_get_text(GTK_ENTRY(villee)));



GtkWidget *image;



int a;
if(gtk_combo_box_get_active (combobox8)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_hide (image);
a=1;
}

else 
{	image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_show (image);a=0;
}

if(gtk_combo_box_get_active (combobox7)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_hide (image);



a=1;
}
else 
{	image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_show (image);
a=0;
}
if (a==1)
{
strcpy(h.promo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));
strcpy(h.etoiles,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));

modifierhotel(id,nom,pays,ville,etoiles,promo,h.id,h.nom,h.pays,h.ville,h.etoiles,h.promo);

GtkWidget *pListView;
	pListView=lookup_widget(objet_graphique,"treeviews1");
ajouthot(pListView);



}

}



void
on_annulermodification_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *verifi;
GtkWidget *test,*b1,*b2,*b3;

verifi=lookup_widget(GTK_WIDGET(objet_graphique),"verifi");
b1=lookup_widget(objet_graphique, "enrmodification");
b2=lookup_widget(objet_graphique, "annulermodification");
b3	=lookup_widget(objet_graphique, "ajthot");

 gtk_widget_hide (b1);
 gtk_widget_hide (b2);

    gtk_label_set_text(GTK_LABEL(verifi),"");

 gtk_widget_show (b3);


}


void
on_validers1_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
hotel h;

GtkWidget *combobox7;
GtkWidget *combobox8;

combobox7=lookup_widget(objet_graphique, "etoiles");
combobox8=lookup_widget(objet_graphique, "promohot");

strcpy(h.promo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));
int i=0;
FILE* f;
if (strcmp(h.promo,"10%")==0)
{


	f=fopen("horaire.txt","r");
  	if(f!=NULL) 
         {
           while(fscanf(f," %d %d %d %s ", &h.jour ,&h.moi, &h.annee, h.etoiles)!=EOF){   gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _(h.etoiles)); i++;}

}
  fclose(f);

}
if (strcmp(h.promo,"20%")==0)
{


	f=fopen("horairey.txt","r");
  	if(f!=NULL) 
         {
           while(fscanf(f," %d %d %d %s ", &h.jour ,&h.moi, &h.annee, h.etoiles)!=EOF){   gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _(h.etoiles)); }

}
  fclose(f);

}

if (strcmp(h.promo,"30%")==0)
{


	f=fopen("horairey.txt","r");
  	if(f!=NULL) 
         {
           while(fscanf(f," %d %d %d %s ", &h.jour ,&h.moi, &h.annee, h.etoiles)!=EOF){   gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _(h.etoiles)); }

}
  fclose(f);

}
if (strcmp(h.promo,"40%")==0)
{


	f=fopen("horairey.txt","r");
  	if(f!=NULL) 
         {
           while(fscanf(f," %d %d %d %s ", &h.jour ,&h.moi, &h.annee, h.etoiles)!=EOF){   gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _(h.etoiles)); }

}
  fclose(f);

}




}


gboolean
on_etoileshot_popdown                    (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_checkbutton1sss_toggled             (GtkToggleButton *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *a;


a=lookup_widget(objet_graphique, "usertarek");



gtk_entry_set_visibility (a,
                          TRUE);

}


void
on_checkbutton2sss_toggled             (GtkToggleButton *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *a;


a=lookup_widget(objet_graphique, "passtarek");



gtk_entry_set_visibility (a,
                          TRUE);

}


void
on_checkbutton1sss_pressed             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *a;
a=lookup_widget(objet_graphique, "usertarek");
gtk_entry_set_visibility (a,TRUE);
       
}


void
on_checkbutton1sss_released            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *a;
a=lookup_widget(objet_graphique, "usertarek");
gtk_entry_set_visibility (a,FALSE);
}








void
on_ajtexc_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *jour;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *moi;
GtkWidget *annee;
GtkWidget *combobox7;
GtkWidget *combobox8;
GtkWidget *label20;
excursion e;
excursion2 e2;


GtkWidget *villedepart;
GtkWidget *id;
GtkWidget *villearrive;
GtkWidget *prix;
GtkWidget *voyageur;


combobox7=lookup_widget(objet_graphique, "heure");
combobox8=lookup_widget(objet_graphique, "promoexc");

jour=lookup_widget(objet_graphique, "jourexc");
moi=lookup_widget(objet_graphique, "moiexc");
annee=lookup_widget(objet_graphique, "anneeexc");

/*jourFin=lookup_widget(objet_graphique, "jourFin");
moiFin=lookup_widget(objet_graphique, "moiFin");
anneeFin=lookup_widget(objet_graphique, "anneeFin");*/



e.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
e.moi=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moi));
e.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

/*h.jourFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jourFin));
h.moiFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moiFin));
h.anneeFin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (anneeFin));*/


	id=lookup_widget(objet_graphique,"id");
	villedepart=lookup_widget(objet_graphique,"villedepart");
	villearrive=lookup_widget(objet_graphique,"villearrive");
	prix=lookup_widget(objet_graphique,"prix");
strcpy(e.villedepart,gtk_entry_get_text(GTK_ENTRY(villedepart)));
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.villearrive,gtk_entry_get_text(GTK_ENTRY(villearrive)));
strcpy(e.prix,gtk_entry_get_text(GTK_ENTRY(prix)));




enum {
ID,
VILLEDEPART,
VILLEARRIVE,
PRIX,
HEURE,
PROMO,
VOYAGEUR,
TOGGLE_COLUMN,
N_COLUMN
};

GtkWidget *combobox1;

GtkWidget *image;
GtkTreeIter pIter;
GtkListStore *pListStore;
pListStore=gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN);
GtkWidget *pListView;
	pListView=lookup_widget(objet_graphique,"treeviews1");
combobox1=lookup_widget(objet_graphique, "heure");

int a;
if(gtk_combo_box_get_active (combobox8)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_hide (image);



a=1;
}
else 
{	image=lookup_widget(objet_graphique,"erreursss3");
 gtk_widget_show (image);a=0;
}

if(gtk_combo_box_get_active (combobox7)!=-1)

{

image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_hide (image);



a=1;
}
else 
{	image=lookup_widget(objet_graphique,"erreursss1");
 gtk_widget_show (image);
a=0;
}
if (a==1)
{
strcpy(e.promo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox8)));
strcpy(e.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox7)));
//gtk_combo_box_remove_text (GTK_COMBO_BOX (combobox1), gtk_combo_box_get_active (GTK_COMBO_BOX (combobox1)));
ajouterss1(e);
ajoutexc(pListView);
/*
if (strcmp(h.promo,"10%")==0)
suprimer_hormed(h.etoiles);
if (strcmp(h.promo,"20%")==0)
suprimer_hordiet(h.etoiles);
if (strcmp(h.promo,"30%")==0)
suprimer_hormed(h.etoiles);
if (strcmp(h.promo,"40%")==0)
suprimer_hordiet(h.etoiles);*/
}

}


void
on_modifierexc_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *verifi;
GtkWidget *test,*b1,*b2,*b3;

verifi=lookup_widget(GTK_WIDGET(objet_graphique),"verifi");
b1=lookup_widget(objet_graphique, "enrmodification");
b2=lookup_widget(objet_graphique, "annulermodification");
b3	=lookup_widget(objet_graphique, "ajtexc");

 gtk_widget_show (b1);
 gtk_widget_show (b2);

    gtk_label_set_text(GTK_LABEL(verifi),"veuiller modifier votre excursion");

 gtk_widget_hide (b3);

}


void
on_supprimerexc_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
gchar *id;
  	gint *villedepart;
	gint *villearrive;
	gint *prix;
	gchar *heure;
	gchar *promo;
   
	GtkWidget *villedepartt;
	GtkWidget *villearrivee;	
	GtkWidget *prixx;
	GtkWidget *idd;
	GtkWidget *heuree;
	GtkWidget *promoo;

	GtkWidget *window;
	GtkWidget *test;
	GtkWidget *test1;
  GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;

	GtkWidget *list;
list=lookup_widget(objet_graphique, "treeviews1");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
  if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {


    gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &villedepart, 2, &villearrive, 3, &prix, 4, &heure, 5, &promo, -1);}


suprimerss1(id,villedepart,villearrive,prix,heure,promo);

GtkWidget *pListView;
	pListView=lookup_widget(objet_graphique,"treeviews1");
ajoutexc(pListView);
}

