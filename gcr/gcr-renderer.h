/*
 * mate-keyring
 *
 * Copyright (C) 2010 Stefan Walter
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __GCR_RENDERER_H__
#define __GCR_RENDERER_H__

#include <glib-object.h>

#include "gcr-types.h"
#include "gcr-viewer.h"

G_BEGIN_DECLS

#define GCR_TYPE_RENDERER                 (gcr_renderer_get_type())
#define GCR_RENDERER(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCR_TYPE_RENDERER, GcrRenderer))
#define GCR_IS_RENDERER(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCR_TYPE_RENDERER))
#define GCR_RENDERER_GET_INTERFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), GCR_TYPE_RENDERER, GcrRendererIface))

typedef struct _GcrRendererIface GcrRendererIface;

struct _GcrRendererIface {
	GTypeInterface parent;

	/* signals */
	void (*data_changed) (GcrRenderer *self);

	/* virtual */
	void (*render) (GcrRenderer *self, GcrViewer *viewer);

	gpointer dummy1;
	gpointer dummy2;
	gpointer dummy3;
	gpointer dummy4;
	gpointer dummy5;
	gpointer dummy6;
	gpointer dummy7;

};

GType                  gcr_renderer_get_type                      (void) G_GNUC_CONST;

void                   gcr_renderer_render                        (GcrRenderer *self,
                                                                   GcrViewer *viewer);

void                   gcr_renderer_emit_data_changed             (GcrRenderer *self);

GcrRenderer*           gcr_renderer_create                        (const gchar *label,
                                                                   GckAttributes *attrs);

void                   gcr_renderer_register                      (GType renderer_type,
                                                                   GckAttributes *attrs);

G_END_DECLS

#endif /* __GCR_RENDERER_H__ */
