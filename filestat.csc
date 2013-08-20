/*
     File Statistics: Displays statistics about files dropped on it
     Written by : Ghassan Salem 
     Inspired by : Gregory Czaja (black Hole's originator)
*/
include <wpabs.sc>

class: FileState,
       external stem   = FileStat,
       local,
       external prefix = FileStatX_,
       classprefix     = FileStatC_,
       major version   = 1,
       minor version   = 1,
       file stem       = FileStat;


parent: WPAbstract;

#release order:

passthru: C.ph;
 /* private defs for FileState */
endpassthru;

passthru: C.ih;
 /* implementation defs for FileState */

 /* PM definitions */
   #define INCL_WIN
   #define INCL_DOS
   #define INCL_GPIBITMAPS
   #include <os2.h>

   #define INCL_WPCLASS
   #define INCL_WPFOLDER
   #include <pmwp.h>

 /* internal definitions */
   #define MYSTR_CLASSNAME      "FileState"
endpassthru;

passthru: C.h, after;
 /* public defs for FileState */
endpassthru;

/* pszMyheader holds (usually) the Message Box Title */
data:
   PSZ   pszMyHeader;

methods:
#/*====================================================================*/
#/*                                                                    */
#/* Override drag&drop methods                                         */
#/*                                                                    */
#/*====================================================================*/
    override wpDragOver;

    override wpDrop;

#/*====================================================================*/
#/*                                                                    */
#/* Override class methods                                             */
#/*                                                                    */
#/*====================================================================*/
    override wpclsInitData, class;

    override wpclsUnInitData, class;

