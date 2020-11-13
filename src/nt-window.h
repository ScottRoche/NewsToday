/* ---    nt-window.h    ---
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

#ifndef __NTWINDOW_H
#define __NTWINDOW_H

#include <gtk/gtk.h>

#include "nt-application.h"

G_BEGIN_DECLS

struct _NtWindow 
{
     /*< private >*/
     GtkApplicationWindow parent;

     GtkListBox *news_feed;
};

typedef struct _NtWindowPrivate NtWindowPrivate;

struct _NtWindowPrivate
{
     GListStore *feed_items;
};

#define NT_TYPE_WINDOW (nt_window_get_type ())
G_DECLARE_FINAL_TYPE (NtWindow, nt_window, NT, WINDOW, GtkApplicationWindow)

NtWindow *     nt_window_new       (NtApplication *app);

G_END_DECLS

#endif /* __NTWINDOW_H */