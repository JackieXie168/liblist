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

man3_MANS = list.3 queue.3 stack.3
include_HEADERS = list.h queue.h stack.h
lib_LTLIBRARIES = liblist.la

if EXAMPLES
man3_MANS += examples/cache/cache.3
include_HEADERS += examples/cache/cache.h
lib_LTLIBRARIES += libcache.la
endif

liblist_la_SOURCES = list.c

libcache_la_SOURCES = examples/cache/cache.c

doc_DATA =
if DOCS
doc_DATA += paper.dvi list.0
endif

paper.dvi: list.0 paper.toc
	latex paper/paper

#we need two passes to get the TOC; otherwise, TOC is empty
paper.toc: paper/paper.tex
	latex paper/paper

list.mp: paper/list.fig
	fig2dev -L mp paper/list.fig list.mp

list.0: list.mp
	mpost list
