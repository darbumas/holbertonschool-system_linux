# 0x01-nm_objdump

This repository contains code for projects related to understanding and
manipulating the ELF file format in Linux. This includes building custom versions
of the nm and objdump commands, which are essential tools for working with
binary files in Unix-like operating system

# ELF File Format
The Executable and Linkable Format (ELF) is a standard binary file format that
is used for executable files, relocatable object code, shared libraries, and
core dumps. Understanding the ELF file format is critical for various advanced
tasks in Linux, including debugging, binary analysis, and low-level programming.

## NM Command
nm is a command-line utility for Unix and Unix-like operating systems that shows
the symbol table of an ELF or object file. The symbol table includes a lot of
information about the file's contents, including function names, global
variables, and constants.

In this project, we build a program that replicates the functionality of the
nm command.

## OBJDUMP Command
objdump is another command-line utility that shows information about one or more
object files. This can include things like the file's assembly code, section
headers, symbol table, and more.

Here, we also build a program that reproduces the functionality of the objdump
command.

## Building and Running the Code
To compile the code, use the provided Makefile.

