#!/bin/bash
find  -type f -name "*.cpp" -print0 |
while IFS= read -r -d '' pathname; do
    echo "Compiling ${pathname} to ${pathname%.cpp}..."
    g++ -o "${pathname%.cpp}" "$pathname"
    echo "Done compiling ${pathname}"
done
