@echo off
setlocal enabledelayedexpansion

:: Test binary location (adjust if needed)
set TEST_DIR=build\bin\Debug
set TESTS=factor variable

:: Step 1: Configure
echo [1/3] Configuring project...
cmake -S . -B build
if errorlevel 1 goto :error

:: Step 2: Build
echo [2/3] Building project...
cmake --build build
if errorlevel 1 goto :error

:: Step 3: Run tests
echo [3/3] Running tests...
echo.

:: If no args: run all tests
if "%1"=="" (
    for %%T in (%TESTS%) do (
        set TEST_EXE=%TEST_DIR%\%%T_tests.exe
        if exist "!TEST_EXE!" (
            echo ===== Running %%T_tests.exe =====
            "!TEST_EXE!"
            echo.
        ) else (
            echo Skipped: %%T_tests.exe not found.
        )
    )
    goto :eof
)

:: If one or two args given
set TEST_EXE=%TEST_DIR%\%1_tests.exe
if exist "%TEST_EXE%" (
    if "%2"=="" (
        echo ===== Running %1_tests.exe =====
        "%TEST_EXE%"
    ) else (
        echo ===== Running %1_tests.exe with filter "%2" =====
        "%TEST_EXE%" --gtest_filter=%2
    )
) else (
    echo ❌ Test executable not found: %TEST_EXE%
    exit /b 1
)

goto :eof

:error
echo.
echo ❌ An error occurred during configure or build.
exit /b 1
