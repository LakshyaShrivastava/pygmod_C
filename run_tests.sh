#!/bin/bash

set -e  # Exit on error

TEST_DIR="build/bin"
TESTS=("factor" "variable")

# Step 1: Configure
echo "[1/3] Configuring project..."
cmake -S . -B build

# Step 2: Build
echo "[2/3] Building project..."
cmake --build build

# Step 3: Run tests
echo "[3/3] Running tests..."
echo ""

if [ $# -eq 0 ]; then
    # No args — run all tests
    for test_name in "${TESTS[@]}"; do
        exe_path="$TEST_DIR/${test_name}_tests"
        if [ -x "$exe_path" ]; then
            echo "===== Running ${test_name}_tests ====="
            "$exe_path"
            echo ""
        else
            echo "Skipped: $exe_path not found or not executable."
        fi
    done
else
    exe_path="$TEST_DIR/${1}_tests"
    if [ ! -x "$exe_path" ]; then
        echo "❌ Test executable not found or not executable: $exe_path"
        exit 1
    fi

    if [ $# -eq 1 ]; then
        echo "===== Running $1_tests ====="
        "$exe_path"
    else
        echo "===== Running $1_tests with filter: $2 ====="
        "$exe_path" --gtest_filter="$2"
    fi
fi
