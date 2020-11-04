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

#include "nt-feed-element.h"

G_DEFINE_TYPE_WITH_PRIVATE (NtFeedElement, nt_feed_element, G_TYPE_OBJECT)

static void
nt_feed_element_init (NtFeedElement *self)
{
     
}

void
nt_feed_element_set_title (NtFeedElement *element,
                           gchar   *title)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     priv->title = title;
}

const gchar *
nt_feed_element_get_title (NtFeedElement *element)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     return priv->title;
}

void
nt_feed_element_set_author (NtFeedElement *element,
                            gchar    *author)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     priv->author = author;
}

const gchar *
nt_feed_element_get_author (NtFeedElement *element)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     return priv->author;
}

void
nt_feed_element_set_publish_time (NtFeedElement *element,
                                  time_t        *publish_time)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     priv->publish_time = publish_time;
}

const time_t *
nt_feed_element_get_publish_time (NtFeedElement *element)
{
     NtFeedElementPrivate *priv = nt_feed_element_get_instance_private (NT_FEED_ELEMENT (element));
     return priv->publish_time;
}

static void
nt_feed_element_class_init (NtFeedElementClass *klass)
{
}

NtFeedElement *
nt_feed_element_new ()
{
     return g_object_new (NT_TYPE_FEED_ELEMENT, NULL);
}