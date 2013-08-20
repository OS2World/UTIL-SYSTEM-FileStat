/* This procedure install a file statistics object on your desktop
   by Ghassan Salem September  20, 1993      version 1                 
   This was only tested on OS/2 2.1       
   Maybe it works on earlier versions with SOMFIX and the REXX fixes */
/* Well, as in the original program, I didn't bother a lot, and borrowed heavily
    from the Black Hole's installation procedure */
Parse source . . __rexx_name;
__rexx_dir = Filespec('D',__rexx_name)||Filespec('P',__rexx_name)

Call RxFuncAdd 'SysLoadFuncs', 'REXXUTIL', 'SysLoadFuncs';
Call SysLoadFuncs;           

     system_dll=FileSpec('Drive',Value('SYSTEM_INI',,'OS2ENVIRONMENT'))||'\OS2\DLL';
     rc=SysDeregisterObjectClass('FileState');
     Address CMD '@ERASE 'system_dll'\FILESTAT.DLL 2>NUL';
     Address CMD '@COPY '__rexx_dir'FileStat.DLL 'system_dll;
     If rc <> 0                 /* registered OK ?                */
        Then Do;
          Say  "FileState: could not replace the DLL, rc="rc".";
          Say  "FileState: delete the object and the DLL from \OS2\DLL directory.";
          Exit;
          End;
     rc=SysRegisterObjectClass('FileState',system_dll||'\FILESTAT.DLL');
     If rc <> 1                 /* registered OK ?                */
        Then Do;
          Say  "FileState: could not register its object class, rc="rc".";
          Exit;
          End;
     rc=SysCreateObject('FileState','File Stat','<WP_DESKTOP>', ,
                        'ICONFILE='__rexx_dir'FILESTAT.ICO;OBJECTID=<FILESTAT>;',,
                        'ReplaceIfExists');
     If rc <> 1                 /* registered OK ?                */
        Then Do;
          Say  "FileState: could not create its object, rc="rc".";
          End;
Exit;
