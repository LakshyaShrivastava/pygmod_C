# pygmod_C

**Probabilistic graphical models in C++** — a modular CMake + C++17 core (**`Variable`**, **`Factor`**, **`Function`**, utilities) maintained for undergraduate research at UC Irvine on **probabilistic AI** and efficient inference (directions include **bucket elimination** for graphical models). The layout mirrors discipline from an earlier Python graphical-model library and uses **GoogleTest** for regressions.

**Author:** [Lakshya Shrivastava](https://github.com/LakshyaShrivastava) · [LinkedIn](https://www.linkedin.com/in/lakshya-shrivastava0803/)

**License:** [Apache License 2.0](LICENSE)

---

## Project structure

```
pygmod_C/
├── CMakeLists.txt
├── src/
│   ├── CMakeLists.txt
│   ├── Factor.cpp / Factor.hpp
│   ├── Variable.cpp / Variable.hpp
│   ├── np_utils.cpp / np_utils.hpp
│   └── Function.hpp
├── tests/              # GoogleTest binaries: variable_tests, factor_tests, nputils_tests
├── run_tests.bat       # Windows
└── run_tests.sh        # Unix / macOS / WSL
```

---

## Prerequisites

- C++17 compiler (MSVC, g++, or clang++)
- CMake **≥ 3.10**
- Git

---

## Quickstart

**Windows**

```bash
git clone https://github.com/LakshyaShrivastava/pygmod_C.git
cd pygmod_C
run_tests.bat
```

**macOS / Linux / WSL**

```bash
git clone https://github.com/LakshyaShrivastava/pygmod_C.git
cd pygmod_C
chmod +x run_tests.sh
./run_tests.sh
```

Configure and build manually if you prefer:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

---

## Testing

GoogleTest-backed executables are produced under **`build/bin/`** (depending on generator):

| Binary | Coverage |
|--------|----------|
| `variable_tests` | `Variable` |
| `factor_tests` | `Factor` |
| `nputils_tests` | `np_utils` helpers |

Filter examples:

```bash
./run_tests.sh variable VariableTest.NameDefaultsToId

./build/bin/factor_tests
./build/bin/variable_tests --gtest_filter="VariableTest.*"
```

Windows equivalents: `run_tests.bat …` and `.\build\bin\….exe`.

---

## Contributing

See **[CONTRIBUTING.md](CONTRIBUTING.md)** for registering new source files, adding test executables, and notes on roadmap / git policy.
