#include <gtk/gtk.h>


void
on_buttons1_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttons2_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_saves1_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_supps1_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnects1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry1_show                         (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_entry1_activate                     (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_labels1_activate_current_link       (GtkLabel        *label,
                                        gpointer         user_data);

void
on_labels1_populate_popup              (GtkLabel        *label,
                                        GtkMenu         *menu,
                                        gpointer         user_data);

gboolean
on_labels1_activate_link               (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data);

void
on_labels1_selection_get               (GtkWidget       *widget,
                                        GtkSelectionData *data,
                                        guint            info,
                                        guint            time,
                                        gpointer         user_data);

gboolean
on_notebookS1_select_page              (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data);

gboolean
on_notebookS1_select_page              (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data);

GtkNotebook*
on_notebookS1_create_window            (GtkNotebook     *notebook,
                                        GtkWidget       *widget,
                                        gint             arg1,
                                        gint             arg2,
                                        gpointer         user_data);

void
on_windows1_activate_default           (GtkWindow       *window,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_enregs1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_windows1_enter_notify_event         (GtkWidget       *widget,
                                        GdkEventCrossing *event,
                                        gpointer         user_data);

void
on_Modifierprofile_clicked             (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_profilemodifier_enter_notify_event  (GtkWidget       *widget,
                                        GdkEventCrossing *event,
                                        gpointer         user_data);

void
on_enregistrerinfo_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficherRDV_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerRDV_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterrdv_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterrdv_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterRDV_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_windows1_show                       (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_profilemodifier_show                (GtkWidget       *widget,
                                        gpointer         user_data);

gboolean
on_windows1_enter_notify_event         (GtkWidget       *widget,
                                        GdkEventCrossing *event,
                                        gpointer         user_data);

void
on_quitterinfo_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierprofile_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconnects1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterinfo_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quittertree_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterss1_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quittertree_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quittrermodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterinfo_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajtrdv_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_ajtrdv_enter_notify_event           (GtkWidget       *widget,
                                        GdkEventCrossing *event,
                                        gpointer         user_data);

void
on_treeviews1_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

gboolean
on_treeviews1_select_cursor_row        (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data);

void
on_modifierrdv_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_item3_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_treeviews1_button_press_event       (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_item3_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_treeviews1_toggle_cursor_row        (GtkTreeView     *treeview,
                                        gpointer         user_data);

gboolean
on_treeviews1_select_cursor_row        (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data);

void
on_treeviews1_selection_get            (GtkWidget       *widget,
                                        GtkSelectionData *data,
                                        guint            info,
                                        guint            time,
                                        gpointer         user_data);

void
on_test1_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_enrmodification_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulermodification_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_validers1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_heurerdv_popdown                    (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_checkbutton1sss_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2sss_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1sss_pressed             (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1sss_released            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajthot_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierhotel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerhotel_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajthot_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierhot_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerhot_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerhot_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviews1_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajtexc_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierexc_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerexc_clicked                (GtkButton       *button,
                                        gpointer         user_data);
