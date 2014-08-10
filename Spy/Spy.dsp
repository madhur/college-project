# Microsoft Developer Studio Project File - Name="Spy" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Spy - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Spy.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Spy.mak" CFG="Spy - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Spy - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Spy - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Spy - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Spy - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Spy - Win32 Release"
# Name "Spy - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DefTree.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MsgWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\MyList.cpp
# End Source File
# Begin Source File

SOURCE=.\MySpy.cpp
# End Source File
# Begin Source File

SOURCE=.\PING.cpp
# End Source File
# Begin Source File

SOURCE=.\PingThread.cpp
# End Source File
# Begin Source File

SOURCE=.\Spy.cpp
# End Source File
# Begin Source File

SOURCE=.\Spy.rc
# End Source File
# Begin Source File

SOURCE=.\SpyDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\SpyHelp.cpp
# End Source File
# Begin Source File

SOURCE=.\SpyView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DefTree.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MsgWindow.h
# End Source File
# Begin Source File

SOURCE=.\MyList.h
# End Source File
# Begin Source File

SOURCE=.\MySpy.h
# End Source File
# Begin Source File

SOURCE=.\PING.h
# End Source File
# Begin Source File

SOURCE=.\PingThread.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Spy.h
# End Source File
# Begin Source File

SOURCE=.\SpyDoc.h
# End Source File
# Begin Source File

SOURCE=.\SpyHelp.h
# End Source File
# Begin Source File

SOURCE=.\SpyView.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ac2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\acc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap20.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button2p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button3p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button4p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button5p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button6p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button7p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button8p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Buttonp.bmp
# End Source File
# Begin Source File

SOURCE=E:\Check.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Check.bmp
# End Source File
# Begin Source File

SOURCE=".\res\FinalI copy.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\FinalI.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Flash.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Flash1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Flash1p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Flash2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\flash3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Flashp.bmp
# End Source File
# Begin Source File

SOURCE=.\Help.bmp
# End Source File
# Begin Source File

SOURCE=.\info.bmp
# End Source File
# Begin Source File

SOURCE=.\snap.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Spy.ico
# End Source File
# Begin Source File

SOURCE=.\res\Spy.rc2
# End Source File
# Begin Source File

SOURCE=.\res\SpyDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\STitle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Untitled-1 copy.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
