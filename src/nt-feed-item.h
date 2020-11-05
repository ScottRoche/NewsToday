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

#ifndef __NTFEEDITEM_H
#define __NTFEEDITEM_H

#include <gtk/gtk.h>

#include "nt-application.h"

G_BEGIN_DECLS

struct _NtFeedItem
{
     /*< private >*/
     GObject parent;
};

typedef struct _NtFeedItemPrivate NtFeedItemPrivate;

struct _NtFeedItemPrivate
{
     gchar *title;
     gchar *author;
     time_t *publish_time;
};

#define NT_TYPE_FEED_ITEM (nt_feed_item_get_type ())
G_DECLARE_FINAL_TYPE (NtFeedItem, nt_feed_item, NT, FEED_ITEM, GObject)

NtFeedItem *        nt_feed_item_new                   (void);
void                nt_feed_item_set_title             (NtFeedItem *element, 
                                                        gchar      *title);
const gchar *       nt_feed_item_get_title             (NtFeedItem *element);
void                nt_feed_item_set_author            (NtFeedItem *element, 
                                                        gchar      *author);
const gchar *       nt_feed_item_get_author            (NtFeedItem *element);
void                nt_feed_item_set_publish_time      (NtFeedItem *element, 
                                                        time_t     *publish_time);
const time_t *      nt_feed_item_get_publish_time      (NtFeedItem *element);

G_END_DECLS

#endif /* __NTFEEDITEM_H */