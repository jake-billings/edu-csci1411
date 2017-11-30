#!/bin/bash
find  -type f -name "*.cpp" -print0 |
while IFS= read -r -d '' pathname; do
    echo "Filtering ${pathname} to ${pathname}_plan.cpp..."
    cat "${pathname}" | grep -E "(//|/\*| \*)" > "${pathname%.cpp}_plan.cpp"
    echo "Done planning ${pathname}"
done
