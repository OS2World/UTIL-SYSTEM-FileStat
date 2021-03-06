
/*
 * This file was generated by the SOM Compiler.
 * FileName: filestat.h.
 * Generated using:
 *     SOM Precompiler spc: 1.22
 *     SOM Emitter emith: 1.11
 */

/*
 * 
 * 
 *      File Statistics: Displays statistics about files dropped on it
 *      Written by : Ghassan Salem
 *      Inspired by : Gregory Czaja (black Hole's originator)
 */


#ifndef FileStat_h
#define FileStat_h


#include <som.h>

/*
 * Define the class name as an object type
 */
#ifndef FileState
#define FileState SOMAny
#endif
#include "wpabs.h"

/*
 * Passthru lines: File: "C.h", "after"
 */
/* public defs for FileState */

#define FileState_MajorVersion 1
#define FileState_MinorVersion 1

/*
 * External name shortening if required
 */
#ifdef SOM_USE_SHORT_EXTERNAL_NAMES
#define FileStateNewClass FileStatc
#pragma linkage(FileStatc, system)
#define FileStateClassData FileStatd
#define FileStateCClassData FileStatx
#endif /* SOM_USE_SHORT_EXTERNAL_NAMES */
/*--------------Migration------------*/
#define FileState_classObj FileStateClassData.classObject
#define _FileState FileState_classObj

/*
 * New and Renew macros for FileState
 */
#define _FileStateNew() (_somNew(FileStateClassData.classObject))
#define FileStateNew() \
	( FileStateClassData.classObject \
		? _FileStateNew() \
		: ( FileStateNewClass(FileState_MajorVersion, FileState_MinorVersion), _FileStateNew() ) )
#define FileStateRenew(buf) \
	( _somRenew(FileStateClassData.classObject, buf) )

/*
 * Override method: wpDragOver
 */
#define FileState_wpDragOver(somSelf,hwndCnr,pdrgInfo) \
	WPObject_wpDragOver(somSelf,hwndCnr,pdrgInfo)

/*
 * Override method: wpDrop
 */
#define FileState_wpDrop(somSelf,hwndCnr,pdrgInfo,pdrgItem) \
	WPObject_wpDrop(somSelf,hwndCnr,pdrgInfo,pdrgItem)

/*
 * Declare the class creation procedure
 */
SOMEXTERN SOMAny * SOMLINK FileStateNewClass(integer4 scemajorVersion,
		integer4 sceminorVersion);
#pragma linkage(FileStateNewClass, system)

/*
 * Declare the class data structure
 */
SOMEXTERN struct FileStateClassDataStructure {
	SOMAny *classObject;
} FileStateClassData;

/*
 * Declare the C specific class data structure
 */
SOMEXTERN struct FileStateCClassDataStructure {
	somMethodTab *parentMtab;
	somDToken instanceDataToken;
} FileStateCClassData;

#endif       /* FileStat_h */

/*
 * This file was generated by the SOM Compiler.
 * FileName: filestat.h.
 * Generated using:
 *     SOM Precompiler spc: 1.22
 *     SOM Emitter emith: 1.11
 */

#ifndef FileStat_mh
#define FileStat_mh


/*
 * Define the class name as an object type
 */
#ifndef M_FileState
#define M_FileState SOMAny
#endif

#define M_FileState_MajorVersion 1
#define M_FileState_MinorVersion 1

/*
 * External name shortening if required
 */
#ifdef SOM_USE_SHORT_EXTERNAL_NAMES
#define M_FileStateNewClass FileStatc
#pragma linkage(FileStatc, system)
#define M_FileStateClassData FileStatd
#define M_FileStateCClassData FileStatx
#endif /* SOM_USE_SHORT_EXTERNAL_NAMES */
/*--------------Migration------------*/
#define M_FileState_classObj M_FileStateClassData.classObject
#define _M_FileState M_FileState_classObj

/*
 * New and Renew macros for M_FileState
 */
#define _M_FileStateNew() (_somNew(M_FileStateClassData.classObject))
#define M_FileStateNew() \
	( M_FileStateClassData.classObject \
		? _M_FileStateNew() \
		: ( M_FileStateNewClass(M_FileState_MajorVersion, M_FileState_MinorVersion), _M_FileStateNew() ) )
#define M_FileStateRenew(buf) \
	( _somRenew(M_FileStateClassData.classObject, buf) )

/*
 * Override method: wpclsInitData
 */
#define M_FileState_wpclsInitData(somSelf) \
	M_WPObject_wpclsInitData(somSelf)

/*
 * Override method: wpclsUnInitData
 */
#define M_FileState_wpclsUnInitData(somSelf) \
	M_WPObject_wpclsUnInitData(somSelf)

/*
 * Declare the class creation procedure
 */
SOMEXTERN SOMAny * SOMLINK M_FileStateNewClass(integer4 scemajorVersion,
		integer4 sceminorVersion);
#pragma linkage(M_FileStateNewClass, system)

/*
 * Declare the class data structure
 */
SOMEXTERN struct M_FileStateClassDataStructure {
	SOMAny *classObject;
} M_FileStateClassData;

/*
 * Declare the C specific class data structure
 */
SOMEXTERN struct M_FileStateCClassDataStructure {
	somMethodTab *parentMtab;
	somDToken instanceDataToken;
} M_FileStateCClassData;

#endif       /* FileStat_h */
