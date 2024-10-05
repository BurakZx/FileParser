# FileParser built in C

## A program to parse files and generate them as parsed outputs

# How does it work?
1. clone it into your local repository
2. run it using any c compiler
3. give command line arguments
4. argv[1] is for filename, argv[2] for parsing, argv[3] for parsing with what, argv[4] is a bool for determining what you want to do
5. argv[2] and argv[3] cant be string (if you do it gets first char)
6. argv[4] i a bool that checks if you want to replace or parse. 1 for replace, 0 for parse
7. if no filename is given it will give error thus others are optional
8. default values are ';' for argv[2], '\0' for argv[3] and '0' for argv[4]
9. it will generate a file named "parsedfile.txt" in the same directory

# Example
gcc fileparser.c -o "executableName"
./"executableName" filename.txt ; \n 1

# TODO
- add more parsing options like finding a string and then replacing with a string
- add output format option
- make a proper executable with makefile or so
- split code into functions and use an utils/src folder
