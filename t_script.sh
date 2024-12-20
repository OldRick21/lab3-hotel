#!/bin/bash
gcovr -r . -e CMakeFiles --html-details -o coverage/coverage.html --gcov-ignore-errors=all
