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

G_DEFINE_TYPE(NtWindow, nt_window, GTK_TYPE_APPLICATION_WINDOW);

static void
nt_window_init (NtWindow *win)
{
     gtk_widget_init_template (GTK_WIDGET (win));
}

static void
nt_window_class_init (NtWindowClass *class)
{
     gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                                  "/io/github/scottroche/newstoday/src/ui/nt-window.ui");
}

NtWindow *
nt_window_new (NtApplication *app)
{
     return g_object_new (NT_WINDOW_TYPE, "application", app, NULL);
}