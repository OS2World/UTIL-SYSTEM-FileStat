#===================================================================
#
#   Sample application makefile,common definitions for the IBM C
#   compiler environment
#===================================================================
.SUFFIXES:
.SUFFIXES: .rc .res .obj .lst .c .asm .hlp .itl .ipf
#===================================================================
# Default compilation macros for sample programs
#
# Compile switches  that are enabled
CC = icc
CC = $(CC) /c   #   compile don't link
CC = $(CC) /ss  #   allow  "//" for comment lines
CC = $(CC) /Se  #   allow cset  extensions
CC = $(CC) /Ms  #   use the system calling convention and not optilink as the default

CC = $(CC) /Ti- #   include debugging info
CC = $(CC) /W2  #   warning level 3
CC = $(CC) /Ka- #   lost of precision messages + on / - off   <----
CC = $(CC) /Kb+ #   turn basic diagnostics msg on +
CC = $(CC) /Kc- #   turn preprocessor msg off -
CC = $(CC) /Kt- #   turn preprocessor trace off
CC = $(CC) /Ki- #   turn non-init vars msg on +   <----
CC = $(CC) /Kp- #   turn unused func parms on +   <----
CC = $(CC) /Kx- #   unused external defs on +     <----

CC = $(CC) /Gm+ #   use the multi-threaded libraries
CC = $(CC) /Gd- #   static linking of libraries
CC = $(CC) /Re  #   generate code that uses a run-time environment
CC = $(CC) /Gn- #   generate default libraries info
CC = $(CC) /Gs- #   enable stack probes
CC = $(CC) /Q+  #   don't show copyright notices


CCEXE = $(CC) /Ge+   #  generate EXE
CCDLL = $(CC) /Ge-   #  generate DLL


LFLAGS  = /NOI /ALIGN:16 /EXEPACK /CO /MAP /BASE:0x10000
LFLAGS  = $(LFLAGS) /CODEVIEW
LINK    = LINK386  $(LFLAGS)
DEFLIBS = OS2386 + SOM

LIBS    = DDE4MBS + OS2386
STLIBS  = DDE4SBS + OS2386
MTLIBS  = DDE4MBS + os2386
DLLLIBS = DDE4NBS + os2386
VLIBS   = DDE4SBS + vdh + os2386

.c.lst:
    $(CCDLL) -Fc$*.lst -Fo$*.obj $*.c

.c.obj:
    $(CCDLL) -Fo$*.obj $*.c

.asm.obj:
    $(ASM)   $*.asm

.ipf.hlp:
        ipfc $*.ipf /W3

.itl.hlp:
        cc  -P $*.itl
        ipfc $*.i
        del $*.i

.rc.res:
        rc -r -p -x $*.rc
