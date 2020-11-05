/* ---    nt-application.c    ---
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

#include "nt-application.h"
#include "nt-window.h"
#include "nt-rss-parser.h"

G_DEFINE_TYPE_WITH_PRIVATE(NtApplication, nt_application, GTK_TYPE_APPLICATION);

static void
nt_application_init (NtApplication *self)
{
}

/**
 * nt_application_rss_setup:
 * @self: A reference to the application being run.
 * 
 * Creates a list of RSS feed channels and a feed pool which
 * will be used to fetch the RSS feeds themselves.
 */
static void
nt_application_rss_setup (NtApplication *self)
{
     NtApplicationPrivate *priv = nt_application_get_instance_private (NT_APPLICATION (self));

     // Change this to hold actual rss feeds.
     gchar *feeds_list [] = {
          "http://0.0.0.0:8000/testy-testy.xml",
		NULL

     };

     priv->channel_feeds = nt_rss_feed_channels_create(feeds_list);
     priv->feeds_pool = nt_rss_feeds_pool_create(priv->channel_feeds);
}

/**
 * nt_application_rss_feed_fetch:
 * @pool: The GrssFeedsPool which holds the feed to fetch.
 * @feed: The current feed channel fetched.
 * @items: The items within the @feed.
 * 
 * Auto-fetches rss feeds from a GrssFeedsPool, printing the title of each item within the feed.
 */
static void
nt_application_rss_feed_fetch (GrssFeedsPool *pool, GrssFeedChannel *feed, GList *items)
{
     GList *iter;
     GrssFeedItem *item;

     if (items == NULL) {
          printf ("Error while fetching %s\n", grss_feed_channel_get_title (feed));
          return;
     }

     printf ("Fetched from %s\n", grss_feed_channel_get_title (feed));

     for (iter = items; iter; iter = g_list_next (iter)) {
          item = (GrssFeedItem*) iter->data;
          printf("\t\t%s\n", grss_feed_item_get_title (item));
     }

     printf ("\n\n");
}

static void
nt_application_activate (GApplication *app)
{
     /* Launch a new window. */
     NtApplicationPrivate *priv = nt_application_get_instance_private (NT_APPLICATION (app));
     NtWindow *win;

     win = nt_window_new (NT_APPLICATION (app));
     gtk_window_present (GTK_WINDOW (win));

     nt_application_rss_setup (NT_APPLICATION (app));
     g_signal_connect (priv->feeds_pool, 
                       "feed-ready", G_CALLBACK (nt_application_rss_feed_fetch),
                       NULL);
}

static void
nt_application_dispose (GObject* gobject)
{
     NtApplicationPrivate *priv = nt_application_get_instance_private (NT_APPLICATION (gobject));

     /* Frees the channel_feeds and pool references. */
     nt_rss_feed_channels_free (priv->channel_feeds);
     nt_rss_feeds_pool_free (priv->feeds_pool);
     printf ("RSS feed channels and pool freed\n");

     G_OBJECT_CLASS (nt_application_parent_class)->dispose (gobject);
}

static void
nt_application_class_init (NtApplicationClass *klass)
{
     GObjectClass *object_class = G_OBJECT_CLASS (klass);

     object_class->dispose = nt_application_dispose;

     G_APPLICATION_CLASS (klass)->activate = nt_application_activate;
}

NtApplication *
nt_application_new (void)
{
     return g_object_new (NT_TYPE_APPLICATION,
                          "application-id", "io.github.scottroche.newstoday",
                          "flags", G_APPLICATION_HANDLES_OPEN,
                          NULL);
}