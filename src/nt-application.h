/* ---    nt-application.h    ---
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

#ifndef __NTAPPLICATION_H
#define __NTAPPLICATION_H

#include <gtk/gtk.h>
#include <libgrss/libgrss.h>

G_BEGIN_DECLS

struct _NtApplication 
{
     GtkApplication parent;
};

typedef struct _NtApplicationPrivate NtApplicationPrivate;

struct _NtApplicationPrivate 
{
     GList *channel_feeds;
     GrssFeedsPool *feeds_pool;
};

#define NT_TYPE_APPLICATION (nt_application_get_type ())
G_DECLARE_FINAL_TYPE (NtApplication, nt_application, NT, APPLICATION, GtkApplication)

NtApplication *     nt_application_new       (void);

G_END_DECLS

#endif /* __NTAPPLICATION_H */