#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <glib.h>
#include <locale.h>
#include <sqlite3.h>

// Make them global

GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget	*btnConnect;
GtkWidget	*loginUspjeh;
GtkWidget	*loginStatus;
GtkBuilder	*builder; 

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("main.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

     gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	btnConnect = GTK_WIDGET(gtk_builder_get_object(builder, "btnConnect"));
	loginUspjeh = GTK_WIDGET(gtk_builder_get_object(builder, "loginUspjeh"));
	loginStatus = GTK_WIDGET(gtk_builder_get_object(builder, "loginStatus"));


	gtk_widget_show(window);

	gtk_main();

	return EXIT_SUCCESS;
	}

void on_btnConnect_clicked(GtkButton *button, gpointer user_data) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("main.db", &db);
    if (rc != SQLITE_OK) {
        gtk_label_set_text(GTK_LABEL(loginUspjeh), "Error");
        return;
    }
    gtk_label_set_text(GTK_LABEL(loginUspjeh), "Success!");
    sqlite3_close(db);
}