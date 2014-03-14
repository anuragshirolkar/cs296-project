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

# Library Paths
BOX2D_ROOT=$(EXT)
GLUI_ROOT=/usr
GL_ROOT=/usr/include/

#Libraries
LIBS = -lBox2D -lglui -lglut -lGLU -lGL

# Compiler and Linker flags
CPPFLAGS =-g -O3 -Wall -fno-strict-aliasing
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

#shared_lib bool variable
SHARED_LIB=FALSE

######################################

.PHONY: all setup clean distclean

all:setup $(OBJS) 
setup:
	@mkdir -p myobjs
	@mkdir -p mylibs
	@mkdir -p mybins 
	@ if [ ! -f "$(INCLUDE)/Box2D/Box2D.h" ] || [ ! -f "$(EXT_LIB)/libBox2D.a" ]; then \
	cd external;\
	cd src;\
	tar xvzf Box2D.tgz;\
	cd Box2D;\
	mkdir -p buildcs296;\
	cd buildcs296;\
	cmake ..;\
	make;\
	make install;\
	$(ECHO) "Setup Done." ;\
	fi;

-include $(OBJS:.o=.d)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
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
	@$(RM) -rf $(OBJDIR) *~ $(DEPS) $(SRCDIR)/*~ my*
	@$(ECHO) "Done"

distclean:clean
	@$(RM) -rf $(EXT_LIB)/* $(INCLUDE)/* $(EXT_SRC)/Box2D $(DOCDIR)/html

