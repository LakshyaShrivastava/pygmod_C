# pygmod_C
C++ implementation of a Python-based graphical model library using modular, test-driven design.

Includes translation of `Variable`, `Factor`, and `Function` classes, with GoogleTest and CMake build system.

---
## Project Structure
```
pygmod_C/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   ├── Factor.cpp
│   ├── Factor.hpp
│   ├── Variable.cpp
│   ├── Variable.hpp
│   └── Function.hpp
├── tests/
│   ├── CMakeLists.txt
│   ├── test_factor.cpp
│   └── test_variable.cpp
├── build/                  # Not going to be tracked in git other than test binaries
├── run_tests.bat           # Windows build & test script
└── run_tests.sh            # Unix/macOS build & test script
```

---
## Quickstart

### Prerequisites
- C++17 compiler (MSVC, g++, or clang++)
- CMake ≥ 3.10
- Git

---
### Windows (CMD or PowerShell)
```bash
git clone https://github.com/LakshyaShrivastava/pygmod_C.git
cd pygmod_C
run_tests.bat
```

### macOS / Linux / WSL
```bash
git clone https://github.com/LakshyaShrivastava/pygmod_C.git
cd pygmod_C
chmod +x run_tests.sh
./run_tests.sh
```

### Run a Specific Test
```bash
run_tests.bat variable VariableTest.NameDefaultsToId   # Windows
./run_tests.sh variable VariableTest.NameDefaultsToId  # Unix/macOS/WSL
```

---
## Testing
Unit tests are written using GoogleTest and split across executables for modular execution:
- `variable_tests`
- `factor_tests`

Test executables are placed in `build/bin` and can be run individually:
```bash
./build/bin/factor_tests
./build/bin/variable_tests --gtest_filter=VariableTest.*
```

---
## Adding a New Source + Test File

✅ Step 1: Create Your Source + Header Files
    - In `src/`, create the `.cpp` and `.hpp` files for your new class. 
    - Let's call these `src/MyModule.cpp` and `src/MyModule.hpp`.
    - Implement your class in these files.

✅ Step 2: Register Your Source File in `src/CMakeLists.txt`
    - Open `src/CMakeLists.txt` and add your file to the library:

        add_library(pygmod_lib
            Factor.cpp
            Variable.cpp
            MyModule.cpp    # ✅ Add this line
        )

        target_include_directories(pygmod_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

✅ Step 3: Create a Test File in `tests/`
    - Let's call this `tests/test_mymodule.cpp`
    - Write test cases in this file using the GoogleTest format.

        // tests/test_mymodule.cpp
        #include <gtest/gtest.h>
        #include "MyModule.hpp"

        TEST(MyModuleTest, ConstructorWorks) {
            MyModule m;
            EXPECT_TRUE(m.isInitialized());
        }

✅ Step 4: Add a New Test Executable in `tests/CMakeLists.txt`
    - Append this to the bottom of `tests/CMakeLists.txt`:

        add_executable(mymodule_tests
            test_mymodule.cpp
        )

        target_link_libraries(mymodule_tests
            pygmod_lib
            gtest_main
        )

        gtest_discover_tests(mymodule_tests)

✅ Step 5: Run the New Tests
    - From project root:
    - Run all tests in the module:

        # Unix/macOS/WSL
        ./run_tests.sh mymodule

        # Windows
        run_tests.bat mymodule

    - Or filter specific tests:

        # Unix
        ./build/bin/mymodule_tests --gtest_filter=MyModuleTest.*

        # Windows
        .\build\bin\mymodule_tests.exe --gtest_filter=MyModuleTest.*

✅ Step 6: (Optional) Add the Module to `run_tests` Script
    - To make your new module's tests run automatically when you execute `run_tests.bat` or `run_tests.sh` with no arguments, you must add its name to the test list.

    - In `run_tests.bat`, update:

        set TESTS=factor variable mymodule

    - In `run_tests.sh`, update:

        TESTS=("factor" "variable" "mymodule")

---
## Git Tracking Policy
- Most of `build/` is excluded via `.gitignore`
- Only test executables inside `build/bin/` are committed, for quick validation