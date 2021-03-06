#include <gtk/gtk.h>

GtkWidget *g_btn;
GtkWidget *g_lbl;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/ui.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    g_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "text"));
    g_btn = GTK_WIDGET(gtk_builder_get_object(builder, "button"));

    g_object_unref(builder);
    gtk_widget_show(window);                
    gtk_main();
    return 0;
}

void click()
{
    gtk_label_set_text(GTK_LABEL(g_lbl), "Hello, world!");
}

void on_window_main_destroy()
{
    gtk_main_quit();
}
