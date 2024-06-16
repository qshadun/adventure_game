#!/bin/bash
# Find all .c and .h files and apply clang-format
find . -name "*.c" -o -name "*.h" | xargs clang-format -i