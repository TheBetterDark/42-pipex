# 42-pipex

## Description

This project is an introduction to the concept of pipes in Unix-like operating systems. The goal is to create a program that mimics the behavior of the shell command `'< file1 cmd1 | cmd2 > file2'`.

The program will take in 4 arguments: 
1. `the input file` 
2. `the command to run on the input file`
3. `the command to run on the output of the first command`
4. `and the output file`

The program will then create a pipe between the two commands and redirect the input and output to the specified files. The program will then run the two commands and write the output to the output file. This project is split into 4 parts:

1. `The first command is executed without any redirections`
2. `The first command's output is redirected to the input of the second command`
3. `The output of the second command is redirected to the output file`
4. `The program will handle multiple pipes`

## Usage

To compile the program, run `make`. The program can be run with the following command:
```bash
./pipex infile cmd1 cmd2 outfile
```

Where `infile` is the input file, `cmd1` is the first command, `cmd2` is the second command, and `outfile` is the output file.

**Here is an example of how to run the program:**
```bash
echo "Hello, world!" > infile
./pipex infile "cat" "wc -w" outfile
cat outfile
```
## Makefile

The Makefile has the following rules:

- all: This rule will compile the library.
- clean: This rule will remove all object files.
- fclean: This rule will remove all object files, excutable files, and the library.
- re: This rule will remove all object files, the library, excutable files and recompile the library.
- libs: This rule will pull the library from the repository.
