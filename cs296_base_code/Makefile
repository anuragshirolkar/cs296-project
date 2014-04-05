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

REPORT = $(DOCDIR)/g03_prof_report
TEX = g03_prof_report

######################################

.PHONY: all setup clean distclean report doc data plot debug_prof release_prof setup_r setup_d cleandat distclean1

all:setup $(OBJS) exe 
setup: distclean1
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

setup_r: distclean1
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
	cmake -DCMAKE_BUILD_TYPE=Release ../;\
	make;\
	make install;\
	$(ECHO) "Setup Done." ;\
	fi;

setup_d: distclean1
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
	cmake -DCMAKE_BUILD_TYPE=Debug ../;\
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

$(OBJS_R): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(PRINTF) "$(MESG_COLOR)Compiling: $(NO_COLOR) $(FILE_COLOR) %25s$(NO_COLOR)" "$(notdir $<)"
	@$(CC) -O3 $(CPPFLAGS) -c $< -o $@ -MD 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else printf "${OK_COLOR}%30s\n${NO_COLOR}" "[OK]"; \
	fi;
	@$(RM) -f temp.log temp.err

$(OBJS_D): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(PRINTF) "$(MESG_COLOR)Compiling: $(NO_COLOR) $(FILE_COLOR) %25s$(NO_COLOR)" "$(notdir $<)"
	@$(CC) $(CPPFLAGS) -c $< -o $@ -MD 2> temp.log || touch temp.err
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

exe_r: 
	@$(PRINTF) "$(MESG_COLOR)Building executable:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $(BINDIR)/$(TARGET))"
	@$(CC)  -O3 -o $(BINDIR)/$(TARGET) $(LDFLAGS) $(OBJS) $(LIBS) 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err
exe_d:
	@$(PRINTF) "$(MESG_COLOR)Building executable:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $(BINDIR)/$(TARGET))"
	@$(CC) -o $(BINDIR)/$(TARGET) $(LDFLAGS) $(OBJS) $(LIBS) 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err
exelib: setup $(OBJS)
	@$(PRINTF) "$(MESG_COLOR)Building executable using mylibs:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $(BINDIR)/$(TARGET_LIB))"
ifeq ($(SHARED_LIB),FALSE)
	@make -s static
else 
	@make -s dynamic
endif

ifeq ($(SHARED_LIB),FALSE)
	@g++ -o $(BINDIR)/$(TARGET_LIB) $(LDFLAGS) $(OBJDIR)/main.o $(LIBDIR)/libCS296test.a $(LIBS) 2> temp.log || touch temp.err
else 
	@g++ -o $(BINDIR)/$(TARGET_LIB) $(LDFLAGS) $(OBJDIR)/main.o $(LIBDIR)/libCS296test.so $(LIBS) 2> temp.log || touch temp.err
endif
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err

static: 
	@ar -cq $(LIBDIR)/libCS296test.a $(OBJDIR)/*[!main].o;\
	
dynamic:
	@$(CC) -shared -Wall $(CPPFLAGS) -o $(LIBDIR)/libCS296test.so -fPIC  $(SRCDIR)/*[!main].cpp;

clean:
	@$(ECHO) -n "Cleaning up..."
	@$(RM) -rf $(OBJDIR) *~ $(DEPS) $(SRCDIR)/*~ my* $(DOCDIR)/html $(REPORT).aux  $(REPORT).pdf $(REPORT).bbl $(REPORT).blg $(REPORT).dvi $(REPORT).log  $(DAT) $(PLOTS)
	@$(ECHO) "Done"

cleandat:
	@rm *.dat

distclean:clean cleandat
	@$(RM) -rf $(EXT_LIB)/* $(INCLUDE)/* $(EXT_SRC)/Box2D

distclean1:clean
	@$(RM) -rf $(EXT_LIB)/* $(INCLUDE)/* $(EXT_SRC)/Box2D

report:
	@cd $(DOCDIR);\
	pdflatex $(TEX)
	

doc:
	@$(ECHO) -n "Generating Doxygen Documentation ...  "
	@$(RM) -rf doc/html
	@$(DOXYGEN) $(DOCDIR)/Doxyfile 2 > /dev/null
	@$(ECHO) "Done"
data:all
	@mkdir -p data
	@$(SH) $(SCR)/g03_gen_data.sh
	@$(SH) $(SCR)/g03_gen_csv.sh
	@$(SH) $(SCR)/g03_gen_data_csv.sh
	@$(SH) $(SCR)/g03_gen_data_random.sh
plot:
	@mkdir -p plots
	@echo "done"
	@cd $(SCR);\
	gnuplot $(SCR)/g03_plot01.gpt;\
	gnuplot $(SCR)/g03_plot02.gpt;\
	gnuplot $(SCR)/g03_plot03.gpt;\
	gnuplot $(SCR)/g03_plot04.gpt;\
	gnuplot $(SCR)/g03_plot05.gpt;
	@rm $(DAT)/hist.temp
	@rm  $(DAT)/hist1.temp
	@rm -rf  $(SCR)/fit.log
	@rm -rf $(SCR)/temp.csv

debug_prof: setup_d $(OBJS_D) exe_d
	@perf record -g -- mybins/cs296_03_exe 10000
	@mv perf.data g03_debug_prof.dat 


release_prof: setup_r $(OBJS_R) exe_r
	@perf record -g -- mybins/cs296_03_exe 10000
	@mv perf.data g03_release_prof.dat
	
