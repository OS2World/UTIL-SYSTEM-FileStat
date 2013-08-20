#--------------------------------------------
# Simplified makefile
#--------------------------------------------
#--------------------------------------------
# Include inference rules and definitions
#--------------------------------------------
!include makedefs.inc

.c.obj:
#        $(CCDLL) -I$(HPATH) $*.c 1> $*.err
        $(CCDLL) -I$(HPATH) $*.c 
#        @TYPE $*.err
        @ECHO No Fatal Error for $*.c

.csc.ih:
        sc -v -r $*.csc

#--------------------------------------------
# Define suffixes
#--------------------------------------------
.SUFFIXES:
.SUFFIXES: .c .obj .dll .csc .sc .h .ih .ph .psc .rc .res .dlg

#--------------------------------------------
#  Environment Setup for the component(s).
#--------------------------------------------
SCPATH=D:\som\release1\som.r1\include
HPATH=d:\som\release1\som.r1\include
LIBPATH=D:\TOOLKT21\os2lib

#--------------------------------------------
# Compiler/tools Macros
#--------------------------------------------
LINK    = LINK386


#--------------------------------------------
# List all objects for app
#--------------------------------------------
DLLOBJS = FileStat.obj

#--------------------------------------------
# Make entry point
#--------------------------------------------
all: FileStat.ih FileStat.dll 

FileStat.ih:  $$(@B).csc

FileStat.obj: $$(@B).c $$(@B).ih $$(@B).h  $$(@B).sc

FileStat.dll: $$(@B).def $(DLLOBJS) 
          $(LINK) $(LFLAGS) $(DLLOBJS),$@,$*.Map,$(DEFLIBS),$*.def; > $*.erl
