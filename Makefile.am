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

dist_man3_MANS = man/llist.3 \
	man/lqueue.3 \
	man/lstack.3
include_HEADERS = list.h list_namespace.h queue.h stack.h
lib_LTLIBRARIES = liblist.la

if EXAMPLES
dist_man3_MANS += examples/cache/lcache.3
include_HEADERS += examples/cache/cache.h
lib_LTLIBRARIES += libcache.la
endif

liblist_la_SOURCES = list.c list_private.h
liblist_la_LDFLAGS = $(AM_LDFLAGS) -version-info 2:0:0

libcache_la_SOURCES = examples/cache/cache.c
libcache_la_LIBADD = liblist.la

#
# tests
#
TESTS = tests/basic \
	tests/oldapi
check_PROGRAMS = $(TESTS)

tests_basic_LDADD = liblist.la
tests_oldapi_LDADD = liblist.la

# misc files to throw into the tarball.
# the examples/*test.c files are just interactive prompt-driven
# programs to demonstrate the API.
EXTRA_DIST = examples/Makefile \
	examples/README \
	examples/listtest.c \
	examples/queuetest.c \
	examples/stacktest.c \
	examples/cache/README \
	examples/cache/cachetest.c \
	paper/list.fig \
	paper/paper.tex \
	paper/performance/Makefile \
	paper/performance/allocperf.c \
	paper/performance/stackperf.c \
	paper/performance/travperf.c \
	liblist.pc.in

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = liblist.pc

doc_DATA =
if DOCS
doc_DATA += paper.dvi list.0
endif

# http://www.gnu.org/software/automake/manual/make/Automatic-Variables.html#Automatic-Variables
paper.dvi: paper/paper.tex list.0 paper.toc
	latex $<

#we need two passes to get the TOC; otherwise, TOC is empty
paper.toc: paper/paper.tex list.0
	latex $<

list.mp: paper/list.fig
	fig2dev -L mp $< $@

list.0: list.mp
	mpost $<
