#
# TransFig makefile
#

all: paper.dvi

# translation into latex

list.tex: list.fig Makefile
	fig2dev -L latex list.fig > list.tex
clean::
	rm -f list.tex paper.dvi paper.ps paper.pdf list.mp list.0

paper.dvi: list.0 paper.tex
	latex paper

list.mp: list.fig
	fig2dev -L mp list.fig list.mp

list.0: list.mp
	mpost list
