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

G_DEFINE_TYPE(NtApplication, nt_application, GTK_TYPE_APPLICATION);

static void
nt_application_init (NtApplication *app)
{
}

static void
nt_application_activate (GApplication *app)
{
     /* Launch a new window. */
     NtWindow *win;

     win = nt_window_new (NT_APPLICATION (app));
     gtk_window_present (GTK_WINDOW (win));
}

static void
nt_application_class_init (NtApplicationClass *class)
{
     G_APPLICATION_CLASS (class)->activate = nt_application_activate;
}

NtApplication *
nt_application_new (void)
{
     return g_object_new (NT_APPLICATION_TYPE,
                          "application-id", "io.github.scottroche.newstoday",
                          "flags", G_APPLICATION_HANDLES_OPEN,
                          NULL);
}