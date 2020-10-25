/* ---    main.c    ---
 *
 *  Copyright (C) 2020 Scott Roche
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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