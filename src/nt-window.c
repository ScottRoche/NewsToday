/* ---    nt-window.c    ---
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

#include "nt-window.h"
#include "nt-feed-element.h"

G_DEFINE_TYPE(NtWindow, nt_window, GTK_TYPE_APPLICATION_WINDOW);

/**
 * nt_window_feed_row_create:
 * @item: The item from the model for which to create a widget for.
 * @user_data: user data.
 * 
 * Creates a widget for which is added to a GtkListBox based on certain data.
 * 
 * Returns: A widget which is subsequently added to the list box.
 */
GtkWidget *
nt_window_feed_row_create (gpointer item,
                           gpointer user_data)
{
     g_return_val_if_fail (NT_FEED_ELEMENT (item), NULL);

     NtFeedElement *element = item;
     GtkWidget *feed_row;
     GtkWidget *headline;
     GtkWidget *author;
     GtkWidget *ptime;

     feed_row = gtk_grid_new ();
     gtk_grid_set_column_homogeneous (GTK_GRID (feed_row), TRUE);

     headline = gtk_label_new (nt_feed_element_get_title (element));
     gtk_label_set_xalign (GTK_LABEL (headline), 0.1);
     gtk_label_set_line_wrap (GTK_LABEL (headline), TRUE);
     gtk_grid_attach (GTK_GRID (feed_row), headline, 0, 0, 1, 1);
     gtk_widget_show (headline);

     author = gtk_label_new (nt_feed_element_get_author (element));
     gtk_label_set_xalign (GTK_LABEL (author), 0.1);
     gtk_grid_attach (GTK_GRID (feed_row), author, 0, 1, 1, 1);
     gtk_widget_show (author);

     /**
      * This will hold the time elapsed since published.
      * Haven't implemented this right now because I'm
      * only using testing data.
      * 
      * However, the position of the label is added.
      */
     gchar *buffer = "Publish Time";
     ptime = gtk_label_new (buffer);
     gtk_label_set_xalign (GTK_LABEL (ptime), 0.9);
     gtk_grid_attach (GTK_GRID (feed_row), ptime, 1, 0, 1, 2);
     gtk_widget_show (ptime);

     return feed_row;
}

static void
nt_window_init (NtWindow *self)
{
     GListStore *element_store;
     NtFeedElement *feed_element_a;
     NtFeedElement *feed_element_b;

     gtk_widget_init_template (GTK_WIDGET (self));

     // A single element with arbitrary values for testing.
     feed_element_a = nt_feed_element_new ();
     nt_feed_element_set_title (feed_element_a, "A title for testing purposes");
     nt_feed_element_set_author (feed_element_a, "Scott Roche");

     feed_element_b = nt_feed_element_new ();
     nt_feed_element_set_title (feed_element_b, "A title for testing");
     nt_feed_element_set_author (feed_element_b, "Billy Bob");
     
     // Initialise the GListStore and append the arbitrary feed item.
     element_store = g_list_store_new (NT_TYPE_FEED_ELEMENT);
     g_list_store_append (element_store, feed_element_a);
     g_list_store_append (element_store, feed_element_b);
     

     gtk_list_box_bind_model (GTK_LIST_BOX (self->news_feed),
                              G_LIST_MODEL (element_store),
                              nt_window_feed_row_create,
                              NULL, NULL);
}

static void
nt_window_class_init (NtWindowClass *klass)
{
     gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass),
                                                  "/io/github/scottroche/newstoday/src/ui/nt-window.ui");

     gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), NtWindow, news_feed);
}

NtWindow *
nt_window_new (NtApplication *app)
{
     return g_object_new (NT_TYPE_WINDOW, "application", app, NULL);
}