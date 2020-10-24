#include <stdio.h>
#include <gtk/gtk.h>

/**
 * Called during g_application_run() constructing a GTK window.
 */
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
     GtkWidget *window;

     window = gtk_application_window_new (app);
     gtk_window_set_title (GTK_WINDOW (window), "NewsToday");
     gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
     gtk_widget_show_all (window);
}

/**
 * 
 */
int main (int    argc,
          char **argv)
{
     GtkApplication *app;
     int status;

     app = gtk_application_new ("io.github.scottroche.newstoday", G_APPLICATION_FLAGS_NONE);
     g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
     status = g_application_run (G_APPLICATION (app), argc, argv);
     g_object_unref (app);

     return status;
}