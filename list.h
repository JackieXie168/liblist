/* list.h -- data structures and such for generic list package
 * 
 * Last edited: Tue Jul 28 15:29:56 1992 by bcs (Bradley C. Spatz) on wasp
 * Updated by Nathan Phillip Brink 2010
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
 *
 */

#ifndef _LIBLIST_LIST_H
#define _LIBLIST_LIST_H

#include <list_namespace.h>
#include <stddef.h>

/* Define a structure to describe the list. */
struct list;
typedef struct list *list_t;

/* Define a structure to describe each element in the list. */
struct list_element;
typedef struct list_element *list_element_t;

/*
  Backwards API compatibility plug.
  We're willing to make the API as backwards-compatible as possible
  but we are going to enforce opaque handles, eliminating the macros
  instead of functions option.
 */
#define LIST_ELEMENT struct list_element
#define LIST struct list

typedef int (*list_traverse_func_t)(void *data, void *node_data);
typedef void (*list_dealloc_func_t)(void *);

/**
   A default data-freeing function for the LIST_DEALLOC.
 */
void list_free_free(void *);

/* Prototype ahoy! */
list_t list_init();
list_t list_mvprev(list_t);
list_t list_mvnext(list_t);
void *list_insert_before(list_t, void *data, size_t len);
void *list_insert_after(list_t, void *data, size_t len);
void *list_remove_front(list_t);
void *list_remove_rear(list_t);
void *list_remove_curr(list_t);
void list_free(list_t, list_dealloc_func_t);

/* Define some constants for controlling list traversals.  We
 * bit-code the attributes so they can be OR'd together.
 */
#define LIST_FORW	0
#define LIST_BACK	2
#define LIST_FRNT	4
#define LIST_CURR	8
#define LIST_REAR	(16 | LIST_BACK)   /* 16 + 2, since REAR implies BACKwards. */
#define LIST_SAVE	32
#define LIST_ALTR	64

/* Define some constants for return codes and such. */
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#define LIST_DEALLOC   (&list_free_free)
#define LIST_NODEALLOC (list_dealloc_func_t)NULL
#define LIST_EMPTY     0
#define LIST_OK        1
#define LIST_EXTENT    2

/* Yet more prototypes. */
void *list_front(list_t);
void *list_curr(list_t);
void *list_rear(list_t);
list_t list_mvfront(list_t);
list_t list_mvrear(list_t);

int list_empty(list_t);
size_t list_size(list_t);

int list_traverse(list_t list, void *data, list_traverse_func_t func, int opts);

#endif
