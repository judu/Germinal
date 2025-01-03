/*
 * This file is part of Germinal.
 *
 * Copyright 2018 Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
 *
 * Germinal is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Germinal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Germinal.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GERMINAL_TERMINAL_H__
#define __GERMINAL_TERMINAL_H__

#include "germinal-cleanup.h"

#ifndef GETTEXT_PACKAGE
#define GETTEXT_PACKAGE "Germinal"
#endif /* GETTEXT_PACKAGE */

#include <glib/gi18n-lib.h>

#include <vte/vte.h>

G_BEGIN_DECLS

#define GERMINAL_TYPE_TERMINAL germinal_terminal_get_type ()
G_DECLARE_FINAL_TYPE (GerminalTerminal, germinal_terminal, GERMINAL, TERMINAL, VteTerminal)

gboolean germinal_terminal_is_zero     (GerminalTerminal *self, guint keycode);
gboolean germinal_terminal_open_url    (GerminalTerminal *self, double x, double y);
gboolean germinal_terminal_spawn       (GerminalTerminal *self, gchar **cmd, GError **error);
void     germinal_terminal_zoom        (GerminalTerminal *self);
void     germinal_terminal_dezoom      (GerminalTerminal *self);
void     germinal_terminal_reset_zoom  (GerminalTerminal *self);
void     germinal_terminal_update_font (GerminalTerminal *self, const gchar *font_str);

void     germinal_terminal_spawn_command (GerminalTerminal *self, GStrv comman);

GtkWidget *germinal_terminal_new ();

G_END_DECLS

#endif /* __GERMINAL_TERMINAL_H__ */
