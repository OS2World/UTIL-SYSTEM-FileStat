
/*
 * This file was generated by the SOM Compiler.
 * FileName: filestat.c.
 * Generated using:
 *     SOM Precompiler spc: 1.22
 *     SOM Emitter emitc: 1.26
 */

/*
 * 
 *      File Statistics: Displays statistics about files dropped on it
 *      Written by : Ghassan Salem
 *      Inspired by : Gregory Czaja (black Hole's originator)
 */


#define FileState_Class_Source
#include "FileStat.ih"
#include <wpshadow.h>
#include <wpFolder.h>
#include <wpDataf.h>

#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
void GoThrough(WPObject * pWPObject,PSZ,PSZ,ULONG *,ULONG *,ULONG *,ULONG *, ULONG *);
PSZ pszFormatV(PSZ ,ULONG);

SOM_Scope MRESULT   SOMLINK FileStatX_wpDragOver(FileState *somSelf,
		HWND hwndCnr,
		PDRAGINFO pdrgInfo)
{
    ULONG ulItemCnt=0;
    ULONG ulItem=0;
    USHORT usDropIndic=DOR_DROP;
    FileStateData *somThis = FileStateGetData(somSelf);
    FileStateMethodDebug("FileState","FileStatX_wpDragOver");
      ulItemCnt=DrgQueryDragitemCount(pdrgInfo);
      for(ulItem=0;ulItem<ulItemCnt;ulItem++) {
       DRAGITEM DItem;

        DrgQueryDragitem(pdrgInfo,sizeof(DItem),&DItem,ulItem);

                      /* check that it is a WPS object RMF */
        if(!DrgVerifyRMF(&DItem,"DRM_OBJECT","DRF_OBJECT")) {
                      /* if it's not - don't accept !      */
          usDropIndic=DOR_NEVERDROP;
        }/* end if */
      }/* end for */

      return (MRFROM2SHORT(usDropIndic,DO_UNKNOWN));
}

SOM_Scope MRESULT   SOMLINK FileStatX_wpDrop(FileState *somSelf,
		HWND hwndCnr,
		PDRAGINFO pdrgInfo,
		PDRAGITEM pdrgItem)
{
    WPObject *pWPObjDropped;
    PSZ   object;
    PSZ   pszClass,pszBuffer[15],pszBuffer1[15],pszBuffer2[15],pszBuffer3[15],pszBuffer4[15];
    static PSZ   pszSmallest=NULL;
    static PSZ   pszBiggest=NULL;
    static ULONG ulSmallest=99999999;
    static ULONG ulBiggest=0;
    static ULONG ulTotals=0;
    static ULONG ulItemCnt;
    static ULONG ulNfiles=0;
    static ulSizeAll=0;
    FileStateData *somThis = FileStateGetData(somSelf);
    FileStateMethodDebug("FileState","FileStatX_wpDrop");
    if (pszSmallest==NULL) {
           pszSmallest=(char *)malloc(200);
           pszBiggest=(char *)malloc(200);
    } /* endif */
    if(ulNfiles==0){
       ulNfiles=DrgQueryDragitemCount(pdrgInfo);
       ulItemCnt=0;
    }
    ulNfiles--;
    pWPObjDropped=OBJECT_FROM_PREC(pdrgItem->ulItemID);
    object       =_wpQueryTitle(pWPObjDropped);
    pszClass     =(PSZ)_somGetClassName(pWPObjDropped);

    GoThrough(pWPObjDropped,pszSmallest,pszBiggest,&ulSmallest,
    &ulBiggest,&ulTotals,&ulItemCnt,&ulSizeAll);
    if(ulNfiles==0){
       PSZ   message =malloc(600);
       sprintf(message,"Smallest File: %s  %s Bytes\nBiggest File: %s %s Bytes\nTotal space (True/Alloc.): %s / %s Bytes\nNumber of Files:%s\n",
            pszSmallest,pszFormatV(pszBuffer,ulSmallest),pszBiggest,pszFormatV(pszBuffer1,ulBiggest),pszFormatV(pszBuffer2,ulTotals),pszFormatV(pszBuffer4,ulSizeAll),pszFormatV(pszBuffer3,ulItemCnt));
       WinMessageBox(HWND_DESKTOP,
                                  HWND_DESKTOP,
                                  message,
                                 "Thanks for using File Statistics. Results are:",
                                  0,
                                  MB_OK | MB_DEFBUTTON2 | MB_INFORMATION | MB_SYSTEMMODAL|MB_MOVEABLE );
       free(message);
       *pszSmallest='\0';
       ulSmallest=99999999;
       *pszBiggest='\0';
       ulTotals=ulBiggest=ulSizeAll=0;
    }

    return (parent_wpDrop(somSelf,hwndCnr,pdrgInfo,pdrgItem));
}

#undef SOM_CurrentClass
#define SOM_CurrentClass SOMMeta
SOM_Scope void   SOMLINK FileStatC_wpclsInitData(M_FileState *somSelf)
{
    /* M_FileStateData *somThis = M_FileStateGetData(somSelf); */
    M_FileStateMethodDebug("M_FileState","FileStatC_wpclsInitData");

    parent_wpclsInitData(somSelf);
}

SOM_Scope void   SOMLINK FileStatC_wpclsUnInitData(M_FileState *somSelf)
{
    /* M_FileStateData *somThis = M_FileStateGetData(somSelf); */
    M_FileStateMethodDebug("M_FileState","FileStatC_wpclsUnInitData");

    parent_wpclsUnInitData(somSelf);
}
#undef SOM_CurrentClass

/*컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
� GoThrough                                                          �
� Purpose: Scans all objects to get relevant data
읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�*/
VOID GoThrough(WPObject * pWPObject,PSZ pszSmallest,PSZ pszBiggest,
ULONG *ulSmallest,ULONG *ulBiggest,ULONG *ulSize,ULONG *ulCount,ULONG *ulSizeAll)
{
   ULONG ulFlags,ulFsize;
 ULONG        PathInfoLevel;   /* Data required */
 FILESTATUS3  PathInfoBuf;     /* File info buffer */
 ULONG        PathInfoBufSize; /* Data buffer size */

   PSZ       pszObject =_wpQueryTitle(pWPObject);
   PSZ       pszClass  =(PSZ)_somGetClassName(pWPObject);
 APIRET       rc;              /* Return code */

       PSZ pszFilename=NULL;
       ULONG  pcb;

   SOMClass *Class;
   SOMClass *FolderClass=_somClassFromId(SOMClassMgrObject,
                                         SOM_IdFromString("WPFolder"));
   if (strcmp(pszClass,"WPShadow")==0) {
       pWPObject=_wpQueryShadowedObject(pWPObject,FALSE);
       pszClass  =(PSZ)_somGetClassName(pWPObject);
   } /* endif */

   Class=_somClassFromId(SOMClassMgrObject,
                                   SOM_IdFromString(pszClass));
                                    /* those are represented by real files... */
                                    /* resolve composite objects if necessary */
   if (_somDescendedFrom(Class, FolderClass)){
                                     /* get the real name for populate */
       if _wpQueryRealName(pWPObject,NULL,&pcb,TRUE){
          pszFilename=malloc(pcb+2);            /* get the buffer */
          memset(pszFilename,'\0',pcb+1);
          _wpQueryRealName(pWPObject,pszFilename,&pcb,TRUE);
       } /* endif */
       if (_wpPopulate(pWPObject, 0L, pszFilename, FALSE)) {
          WPObject * pWPObjectTemp;
                      /* go through folder's content   */
          for(pWPObjectTemp=_wpQueryContent(pWPObject,pWPObjectTemp,QC_First);
              pWPObjectTemp != NULL;
              pWPObjectTemp=_wpQueryContent(pWPObject,pWPObjectTemp,QC_Next)) {

              GoThrough(pWPObjectTemp,pszSmallest,pszBiggest,ulSmallest,
              ulBiggest,ulSize,ulCount,ulSizeAll);
          }/* end for */
       } /* endif */
       if (pszFilename != NULL)
          free(pszFilename);
   } else {
      if _wpQueryRealName(pWPObject,NULL,&pcb,TRUE){
          pszFilename=malloc(pcb+2);            /* get the buffer */
          memset(pszFilename,'\0',pcb+1);
          _wpQueryRealName(pWPObject,pszFilename,&pcb,TRUE);
          PathInfoLevel = 1;    /* Indicate that Level 1 information */
          PathInfoBufSize = sizeof(FILESTATUS3);
          rc = DosQueryPathInfo(pszFilename, PathInfoLevel, &PathInfoBuf,
                                   PathInfoBufSize);
          if(rc==0) {
               (*ulCount)++;
               ulFsize=PathInfoBuf.cbFile;
               (*ulSize)+=ulFsize;
               (*ulSizeAll)+=PathInfoBuf.cbFileAlloc;
               if(*ulSmallest>ulFsize){
                  *ulSmallest=ulFsize;
                  strcpy(pszSmallest,pszFilename);
               }
               if(*ulBiggest<ulFsize){
                  *ulBiggest=ulFsize;
                  strcpy(pszBiggest,pszFilename);
               }
           } /* endif rc */
     } /* endif _wpQuery*/
  } /* endif */
  return;
}
PSZ pszFormatV( PSZ pszBuf, ULONG ulNumber)
{
   char cGrp_sep;
   PSZ pszTmp;
   INT iI,iNs,iNth;
   COUNTRYCODE  ctrycStructure;
   COUNTRYINFO  ctryiMemBuff;
   ULONG        ulDataLength;
   APIRET        rc;        /* Return code */
   ctrycStructure.country=0;
   ctrycStructure.codepage=0;
   rc = DosQueryCtryInfo(sizeof(ctryiMemBuff),
              &ctrycStructure, &ctryiMemBuff,
              &ulDataLength);
    cGrp_sep=ctryiMemBuff.szThousandsSeparator[0];
    sprintf(pszBuf,"%ld",ulNumber);
    pszTmp=pszBuf+strlen(pszBuf);
    while(pszTmp>pszBuf+3){
       memmove(pszTmp-2,pszTmp-3,strlen(pszTmp)+4);
       pszTmp-=3;
       *pszTmp=cGrp_sep;
    } /* endfor */
    return pszBuf;
}
