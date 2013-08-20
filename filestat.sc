
# This file was generated by the SOM Compiler.
# FileName: filestat.sc.
# Generated using:
#     SOM Precompiler spc: 1.22
#     SOM Emitter emitcsc: 1.10

/*
 * 
 *      File Statistics: Displays statistics about files dropped on it
 *      Written by : Ghassan Salem
 *      Inspired by : Gregory Czaja (black Hole's originator)
 */

#include "wpabs.sc"

class: FileState, 
    external stem = FileStat, local, external prefix = FileStatX_, 
    classprefix = FileStatC_, major version = 1, minor version = 1, 
    file stem = FileStat;


parent class: WPAbstract;


passthru: C.h, after;
 /* public defs for FileState */
endpassthru;
methods:


    override wpDragOver;

    -- From WPObject

    override wpDrop;

    -- From WPObject

    override wpclsInitData, class;

    -- From WPObject

    override wpclsUnInitData, class;

    -- From WPObject

