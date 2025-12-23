@echo off
%windir%\System32\xcopy /y /I /S "%~dp0/../bin/ExternalLoader" "%~dp0/../api/lib/ExternalLoader"
%windir%\System32\xcopy /y /I /S "%~dp0/../bin/FlashLoader" "%~dp0/../api/lib/FlashLoader"
%windir%\System32\xcopy /y /I /S "%~dp0/../Data_Base" "%~dp0/../api/Data_Base"

@echo off 
    setlocal enableextensions disabledelayedexpansion
    set "search=$HSM_PATH_WIN"
    set "replace="%~dp0..\bin\HSM\data\""
    set "textFile=%~dp0..\bin\stlibp11_SAM.conf"
	echo %textFile%
    for /f "delims=" %%i in ('type "%textFile%" ^& break ^> "%textFile%" ') do (
        set "line=%%i"
        setlocal enabledelayedexpansion
        >>"%textFile%" echo(!line:%search%=%replace%!
        endlocal
    )

%windir%\System32\xcopy /y /I /S /F "%~dp0/../bin/stlibp11_SAM.conf" "%~dp0/../api/lib/"