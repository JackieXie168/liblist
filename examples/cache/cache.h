/* cache.h -- declarations and such for a generic, list(3)-based cache package.
 *
 * Last edited: Tue Jul 28 15:42:15 1992 by bcs (Bradley C. Spatz) on wasp
 *
 * Copyright (C) 1992, Bradley C. Spatz, bcs@ufl.edu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _LIBLIST_CACHE_H
#define _LIBLIST_CACHE_H

#include <list.h>

typedef struct cache_t {
   int max_elements;
   LIST *list;
} CACHE;

typedef list_traverse_func_t cache_match_func_t;
typedef list_dealloc_func_t cache_dealloc_func_t;

/* Provide some useful prototypes. */
CACHE *cache_init(int max_size);
void *cache_enter(CACHE *cache, void *data, int bytes, void **removed);
void *cache_check(CACHE *cache, void *data, cache_match_func_t match);
void cache_free(CACHE *cache, cache_dealloc_func_t dealloc);

/* Define the deallocation constants. */
#define CACHE_DEALLOC   LIST_DEALLOC
#define CACHE_NODEALLOC LIST_NODEALLOC

#endif
