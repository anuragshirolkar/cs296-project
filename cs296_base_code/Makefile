# Programs
SHELL 	= bash
CC     	= g++
LD	= ld
RM 	= rm
ECHO	= /bin/echo
CAT	= cat
PRINTF	= printf
SED	= sed
DOXYGEN = doxygen
SH=bash

#target file names
TARGET=cs296_03_exe
TARGET_LIB=cs296_03_exelib
SH_LIB=-lCS296test

#installation folder
INSTALL=../install

#paths
PROJECT_ROOT:=$(CURDIR)
EXT=$(PROJECT_ROOT)/external
INCLUDE=$(EXT)/include
EXT_LIB=$(EXT)/lib
EXT_SRC=$(EXT)/src
SRCDIR = $(PROJECT_ROOT)/src
OBJDIR = $(PROJECT_ROOT)/myobjs
BINDIR = $(PROJECT_ROOT)/mybins
LIBDIR = $(PROJECT_ROOT)/mylibs
DOCDIR = $(PROJECT_ROOT)/doc
DAT= $(PROJECT_ROOT)/data
SCR=$(PROJECT_ROOT)/scripts
PLOTS=$(PROJECT_ROOT)/plots

# Library Paths
BOX2D_ROOT=$(EXT)
GLUI_ROOT=/usr
GL_ROOT=/usr/include/

#Libraries
LIBS = -lBox2D -lglui -lglut -lGLU -lGL

# Compiler and Linker flags
CPPFLAGS =-g -Wall -fno-strict-aliasing
CPPFLAGS+=-I $(BOX2D_ROOT)/include -I $(GLUI_ROOT)/include
LDFLAGS+=-L $(BOX2D_ROOT)/lib -L $(GLUI_ROOT)/lib

NO_COLOR=\e[0m
OK_COLOR=\e[1;32m
ERR_COLOR=\e[1;31m
WARN_COLOR=\e[1;33m
MESG_COLOR=\e[1;34m
FILE_COLOR=\e[1;37m

OK_STRING="[OK]"
ERR_STRING="[ERRORS]"
WARN_STRING="[WARNINGS]"
OK_FMT="${OK_COLOR}%30s\n${NO_COLOR}"
ERR_FMT="${ERR_COLOR}%30s\n${NO_COLOR}"
WARN_FMT="${WARN_COLOR}%30s\n${NO_COLOR}"

SRCS := $(wildcard $(SRCDIR)/*.cpp)
INCS := $(wildcard $(SRCDIR)/*.hpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OBJS_R := $(OBJS)
OBJS_D := $(OBJS)

#shared_lib bool variable
SHARED_LIB=FALSE

REPORT = $(DOCDIR)/g03_report
TEX = g03_report

######################################

.PHONY: all setup clean distclean report doc install dist

all:setup $(OBJS) exe report doc 
setup:
	@mkdir -p myobjs
	@mkdir -p mylibs
	@mkdir -p mybins 
	@ if [ ! -f "$(INCLUDE)/Box2D/Box2D.h" ] || [ ! -f "$(EXT_LIB)/libBox2D.a" ] || [ ! -e "$(EXT_SRC)/Box2D" ] ; then \
	cd external;\
	cd src;\
	tar xvzf Box2D.tgz;\
	cd Box2D;\
	mkdir -p buildcs296;\
	cd buildcs296;\
	echo "Done";\
	cmake ../;\
	make;\
	make install;\
	$(ECHO) "Setup Done." ;\
	fi;


-include $(OBJS:.o=.d)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(PRINTF) "$(MESG_COLOR)Compiling: $(NO_COLOR) $(FILE_COLOR) %25s$(NO_COLOR)" "$(notdir $<)"
	@$(CC) -O3 $(CPPFLAGS) -c $< -o $@ -MD 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else printf "${OK_COLOR}%30s\n${NO_COLOR}" "[OK]"; \
	fi;
	@$(RM) -f temp.log temp.err



exe: setup $(OBJS)
	@$(PRINTF) "$(MESG_COLOR)Building executable:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $(BINDIR)/$(TARGET))"
	@$(CC) -o $(BINDIR)/$(TARGET) $(LDFLAGS) $(OBJS) $(LIBS) 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err


clean:
	@$(ECHO) -n "Cleaning up..."
	@$(RM) -rf $(OBJDIR) *~ $(DEPS) $(SRCDIR)/*~ my* $(DOCDIR)/*.html $(DOCDIR)/html $(REPORT).aux  $(REPORT).pdf $(REPORT).bbl $(REPORT).blg $(REPORT).dvi $(REPORT).log $(REPORT).toc
	@$(ECHO) "Done"


distclean:clean
	@$(RM) -rf $(EXT_LIB)/* $(INCLUDE)/* $(EXT_SRC)/Box2D

install: setup exe doc report
	@mkdir -p $(INSTALL)
	@echo "installing..."
	@cp -r mybins/cs296_03_exe $(INSTALL)
	@cp -r doc $(INSTALL)
	@cp -r scripts $(INSTALL)


report:
	@echo -n "Generating Report..."
	@cd $(DOCDIR);\
	pdflatex g03_report >/dev/null;\
	bibtex g03_report >/dev/null;\
	pdflatex g03_report >/dev/null;\
	pdflatex g03_report >/dev/null;\
	pdflatex g03_report >/dev/null
	@python3 scripts/g03_gen_html.py
	@echo "done"

dist: distclean
	@tar -cvzf ../../cs296_g03_project.tar.gz .. ../../README


doc:
	@$(ECHO) -n "Generating Doxygen Documentation ...  "
	@$(RM) -rf doc/html
	@$(DOXYGEN) $(DOCDIR)/Doxyfile 2 > /dev/null
	@$(ECHO) "Done"


#data:all
#	@mkdir -p data
#	@if [ ! -f "mybins/cs296_03_exe" ] ; \
#		then make exe;\
#	fi;
#	@$(ECHO) "Generating csv files..."
#	@python3 scripts/g03_gen_csv.py
