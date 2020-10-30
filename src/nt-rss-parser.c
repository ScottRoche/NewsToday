/* ---    nt-rss-parser.h    ---
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

#include "nt-rss-parser.h"

/**
 * nt_rss_feed_channels_create:
 * @feeds: An array of rss url strings.
 * 
 * GrssFeedChannels are added to a list with an inerval set to one minute.
 * 
 * Returns: A list which GrssFeedChannels are prepended to.
 */
GList *
nt_rss_feed_channels_create (gchar *feeds[])
{
     GList *list;
     GrssFeedChannel *feed;

     list = NULL;

     for (int i = 0; feeds[i] != NULL; i++) {
          feed = grss_feed_channel_new ();
          grss_feed_channel_set_source (feed, feeds[i]);
          grss_feed_channel_set_update_interval (feed, 1);
          list = g_list_prepend (list, feed);
     }

     return list;
}

/**
 * nt_rss_feeds_pool_create:
 * @feed_channels: A list of GrssFeedChannel.
 * 
 * Returns: A GrssFeedsPool which auto-fetches from @feed_channels.
 */
GrssFeedsPool *
nt_rss_feeds_pool_create (GList *feed_channels)
{
     GrssFeedsPool *pool;

     /* Reverses the prepended list. */
     feed_channels = g_list_reverse (feed_channels);

     /* Instantiates a new GrssFeedsPool which is set to 
      * auto-fetche from the GrssFeedChannels.
      */
     pool = grss_feeds_pool_new ();
     grss_feeds_pool_listen (pool, feed_channels);
     grss_feeds_pool_switch (pool, TRUE);

     return pool;
}

/**
 * nt_rss_feed_channels_free:
 * @list: A list of GrssFeedChannel.
 * 
 * Frees each GrssFeedChannel in the @list.
 */
void
nt_rss_feed_channels_free (GList *list)
{
     GList *iter;
     for (iter = list; iter; iter = g_list_next (iter)) 
          g_object_unref (iter->data);
}

/**
 * nt_rss_feeds_pool_free:
 * @pool: A reference to a GrssFeedsPool;
 * 
 * Frees a GrssFeedsPool.
 */
void
nt_rss_feeds_pool_free (GrssFeedsPool *pool)
{
     g_object_unref (pool);
}