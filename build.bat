@echo off
REM Simple build script for Windows (without make)
echo Building KD-Tree project...
gcc -Wall -Iinclude src/point.c src/kd_node.c src/kd_tree.c src/main.c -o kd_tree -lm
if %ERRORLEVEL% EQU 0 (
    echo Build complete!
    echo Run with: kd_tree.exe
) else (
    echo Build failed!
    exit /b 1
)
