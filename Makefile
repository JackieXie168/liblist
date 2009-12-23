# Makefile for generic list package.
#
# Last edited: Tue Jul 28 15:40:05 1992 by bcs (Bradley C. Spatz) on wasp
#
# Copyright (C) 1992 Bradley C. Spatz, bcs@ufl.edu
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#

LIBS	= -L. -llist
#LIBS	= -L . -llist   # Use this for HP-UX; great loader guys!
MANDIR	= /usr/share/man
LIBDIR	= /usr/lib
INCDIR	= /usr/include

#add macro for ranlib 4/96 *kob* - ranlib doesn't exist on solaris
RANLIB = ls

all:		liblist.a 
		(cd examples; make)

liblist.a:	list.o
		ar rc liblist.a list.o
		$(RANLIB) liblist.a

list.o:		list.h list.3 Makefile

install:
		install -c liblist.a $(DESTDIR)$(LIBDIR)
		$(RANLIB) $(DESTDIR)$(LIBDIR)/liblist.a
		install -c list.h $(DESTDIR)$(INCDIR)
		install -c queue.h $(DESTDIR)$(INCDIR)
		install -c stack.h $(DESTDIR)$(INCDIR)
		(cd examples/cache; make install)

install.man:
		install -c list.3 $(DESTDIR)$(MANDIR)/man3
		install -c queue.3 $(DESTDIR)$(MANDIR)/man3
		install -c stack.3 $(DESTDIR)$(MANDIR)/man3

clean:
		rm -f *.o *.a core
		(cd examples; make clean)
