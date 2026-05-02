# Contributing to pygmod_C

Development notes for extending the core library or tests live here; the main README stays scoped to overview, build, and testing.

---

## Repository layout recap

```
pygmod_C/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   ├── Factor.cpp / Factor.hpp
│   ├── Variable.cpp / Variable.hpp
│   ├── np_utils.cpp / np_utils.hpp
│   └── Function.hpp
├── tests/
│   ├── CMakeLists.txt
│   ├── test_variable.cpp
│   ├── test_factor.cpp
│   └── test_nputils.cpp
├── build/                   # Prefer local CMake output; binaries under build/bin/
├── run_tests.bat
└── run_tests.sh
```

**Git tracking:** Most of `build/` is excluded via `.gitignore`. If this repo retains committed test binaries under `build/bin/` for quick validation, keep that policy intentional when changing `.gitignore`.

---

## Adding a new source module and tests

### 1. Add source files

Create `src/MyModule.hpp` and `src/MyModule.cpp` (following existing naming conventions).

### 2. Register the module in `src/CMakeLists.txt`

Add your `.cpp` to the library target:

```cmake
add_library(pygmod_lib
    Factor.cpp
    Variable.cpp
    np_utils.cpp
    MyModule.cpp
)

target_include_directories(pygmod_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

### 3. Add tests

Create `tests/test_mymodule.cpp`:

```cpp
#include <gtest/gtest.h>
#include "MyModule.hpp"

TEST(MyModuleTest, ConstructorWorks) {
    MyModule m;
    EXPECT_TRUE(m.isInitialized());
}
```

### 4. Register the test executable in `tests/CMakeLists.txt`

Append:

```cmake
add_executable(mymodule_tests
    test_mymodule.cpp
)

target_link_libraries(mymodule_tests
    pygmod_lib
    gtest_main
)

gtest_discover_tests(mymodule_tests)
```

### 5. Run tests

From the project root:

```bash
# Windows
run_tests.bat mymodule

# Unix / macOS / WSL
./run_tests.sh mymodule
```

Or run the binary directly (paths vary by generator):

```bash
./build/bin/mymodule_tests --gtest_filter=MyModuleTest.*
```

### 6. (Optional) Include in full test scripts

So `run_tests.bat` / `run_tests.sh` with no arguments also run your module, add `mymodule` to their `TESTS` lists (see scripts for the existing `factor`, `variable`, `nputils` entries).

---

## Roadmap (research directions)

Higher-level inference work—e.g. **bucket elimination** and related variable-elimination methods for graphical models—is the intended next layer on top of this `Variable` / `Factor` core. Contributions in that direction should keep **CMake + GoogleTest** coverage as features land.
