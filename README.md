# mygrep

A command-line tool written in C++ that searches for patterns in text files, inspired by the Unix `grep` utility.

## Usage
```bash
./mygrep <pattern> <file>           # Search normally
./mygrep -l <pattern> <file>        # Show line numbers
./mygrep -o <pattern> <file>        # Show occurrence count
./mygrep -ol <pattern> <file>       # Show both
./mygrep                            # Interactive mode (no file)
```

## Features

- Custom substring search algorithm using pointer arithmetic (no standard library search functions)
- File search with `ifstream`, line by line
- CLI flag parsing (`-l`, `-o`, `-ol`)
- Interactive mode when no arguments are given
- Error handling for missing files and invalid arguments

## Build
```bash
g++ -std=c++11 -o mygrep main.cpp mygrep.cpp
```

## Project Structure
```
main.cpp      # Argument parsing and program entry point
mygrep.cpp    # Search algorithms (findSubstring, searchInFile)
mygrep.hpp    # Header file with function declarations
```

## Author

Touko Mäntynen, TAMK, Spring 2025
