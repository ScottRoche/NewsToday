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

#ifndef __NTFEEDELEMENT_H
#define __NTFEEDELEMENT_H

#include <gtk/gtk.h>

#include "nt-application.h"

G_BEGIN_DECLS

struct _NtFeedElement
{
     /*< private >*/
     GObject parent;
};

typedef struct _NtFeedElementPrivate NtFeedElementPrivate;

struct _NtFeedElementPrivate
{
     gchar *title;
     gchar *author;
     time_t *publish_time;
};

#define NT_TYPE_FEED_ELEMENT (nt_feed_element_get_type ())
G_DECLARE_FINAL_TYPE (NtFeedElement, nt_feed_element, NT, FEED_ELEMENT, GObject)

NtFeedElement *     nt_feed_element_new                (void);
void                nt_feed_element_set_title          (NtFeedElement *element, 
                                                        gchar         *title);
const gchar *       nt_feed_element_get_title          (NtFeedElement *element);
void                nt_feed_element_set_author         (NtFeedElement *element, 
                                                        gchar         *author);
const gchar *       nt_feed_element_get_author         (NtFeedElement *element);
void                nt_feed_element_set_publish_time   (NtFeedElement *element, 
                                                        time_t        *publish_time);
const time_t *      nt_feed_element_get_publish_time   (NtFeedElement *element);

G_END_DECLS

#endif /* __NTFEEDELEMENT_H */