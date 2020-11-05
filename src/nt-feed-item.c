/* ---    nt-feed-element.c    ---
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

#include "nt-feed-item.h"

G_DEFINE_TYPE_WITH_PRIVATE (NtFeedItem, nt_feed_item, G_TYPE_OBJECT)

static void
nt_feed_item_init (NtFeedItem *self)
{
     
}

void
nt_feed_item_set_title (NtFeedItem *element,
                        gchar      *title)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private ( (element));
     priv->title = title;
}

const gchar *
nt_feed_item_get_title (NtFeedItem *element)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private (NT_FEED_ITEM (element));
     return priv->title;
}

void
nt_feed_item_set_author (NtFeedItem *element,
                         gchar      *author)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private (NT_FEED_ITEM (element));
     priv->author = author;
}

const gchar *
nt_feed_item_get_author (NtFeedItem *element)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private (NT_FEED_ITEM (element));
     return priv->author;
}

void
nt_feed_item_set_publish_time (NtFeedItem *element,
                               time_t     *publish_time)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private (NT_FEED_ITEM (element));
     priv->publish_time = publish_time;
}

const time_t *
nt_feed_item_get_publish_time (NtFeedItem *element)
{
     NtFeedItemPrivate *priv = nt_feed_item_get_instance_private (NT_FEED_ITEM (element));
     return priv->publish_time;
}

static void
nt_feed_item_class_init (NtFeedItemClass *klass)
{
}

NtFeedItem *
nt_feed_item_new ()
{
     return g_object_new (NT_TYPE_FEED_ITEM, NULL);
}