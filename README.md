# Operating Systems Project: UNIX utilities

### Background
In this project I built for utilities: wcat, wgrep, wzip, and wunzip.
I also created a Makefile to compile the source code and build the 4 executables 
wcat, wgrep, wzip, wunzip.
All utilities function properly with shell redirection ">" (./utility file > file2).
I made this project in Operating Systems with Professor Matthew Thayer at Seattle 
University.

#### Utilities
##### wcat:
Reads a file specified by the user and prints its contents.
##### wgrep: 
Reads a file and prints each line containing the user-specified search term.
The matching is case-sensitive.
##### wzip:
File compression tool that uses run-length encoding.
Compressed file will consist of 4-byte integers in binary format paired with a single
character in ASCII.
Thus, a compressed file will consist of 5-byte entries.
##### wunzip: 
Reverses wzip tool to uncompress a file and print the results.

#### Edge Case Testing
All utilities perform properly with standard input, these are the edge cases 
I tested in addition to that:
##### wcat:  
- Invoked with multiple files (will print each file in turn).
- Passed no command-line arguments (error message printed with exit status 1).
- File opening fails (error message printed with exit status 1).
- Multiple files where one or many fail to open.
- Invoked with empty file.
##### wgrep: same as wcat EXCEPT
- If given search term, but no file, wgrep reads from standard input.
- If given empty string "" as search term, ALL lines printed.
- Works with search terms of multiple words as long as they are encapsulated in
quotation marks (./wgrep "Hello, World" main.cpp).
##### wzip and wunzip: same as wcat EXCEPT
- If multiple files are passed to wzip, they are compressed into a single compressed 
output, and when unzipped, will turn into a single uncompressed stream of text.
- Invoked with file of only one character.

#### Makefile 
##### all: 
make all is equivalent to make p1.
##### p1: 
make p1 creates excecutables for the 4 utilities, 
will compile if needed to update or create.
##### clean: 
Will erase the .o files created by make p1 or make all.
