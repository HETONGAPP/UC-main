@echo off
setlocal

rem getting current directory
set "script_dir=%~dp0"

rem target directory
set "parent_dir=%script_dir%\..\.git\hooks"

rem delete old directory
rd /s /q "%parent_dir%"

mklink /d "%parent_dir%" "%script_dir%\..\hooks"

endlocal
