C String Searcher version 1.0 11/02/2016

GENERAL USAGE NOTES
-------------------

- This program was built for the standard 2013 Microsoft Compiler.
- This program can be compiled on the 2015 Microsoft Compiler without error.
- This program can be compiled on MinGW for Windows without error

Compiling
---------

- The program comes precompiled as you will see from the find.exe
- To recompile either compile main.c in your standard compiling method or type "nmake stringsearch" to compile the program
- The executable MUST be called find.exe. If you compile with the makefile method it will ensure this.


HOW TO
------

This program is a command line tool and uses command line arguments. Open a command prompt or terminal
in the directory of this file. Then you do not need to launch the software and then input a command, 
instead you do it all in one, e.g. "find hello -i helloworld" would start the program and perform the string seach. 


COMMAND INSTRUCTIONS
--------------------

Commands will take the following format:

	find somestring -i somefile.txt -o somefile.txt -c
	find somestring -i somestring -o somefile.txt -c
	find somestring -i somefile.txt 
	find somestring -i somestring -c

-i signifies input
-o signifies output
-c signifies 'ignore case'

If no input is given the program will error.
If no output is given the program will write to the console
The case flag is optional not mandatory.


THE MAKEFILE
-------------

- The makefile for this program is named 'makefile'
- The makefile carries out tests on the following files - "Scrabble.txt", "Names.txt", & "Random.txt".
- "Scrabble.txt" and "Names.txt" are two very large text files. 
- Scrabble contains all the valid words in the game of scrabble. 
- Names contains all the names on the 1900 USA cencus.
- Random is short and comprised of random words.

When in the compiler type "nmake Stest", "nmake Ntest" & "nmake Rtest" to see the below logic applied
on the files Scrabble.txt, Names.txt, and Random.txt respectively.

  To prove the programs error handling on each data file the following logic will be applied
  Open scrabblemake.txt, namesmake.txt, and randommake.txt to see the commands that are
  executed with each test.


		find 						(will error - see console output)
		find somestring 				(will error - see console output)
		find somestring -i				(will error - see console output)
		find somestring -i fakefile 			(a file that does not exist will error - see console output)
		find somestring -i file				(wont error - see console output)
		find somestring -i somestring			(wont error - see console output)
		find somestring -i somestring -c		(wont error - see console output)
		find somestring -o somefile 			(will error as no input entered)
		find somestring -i file -o file			(wont error - see file)
		find somestring -i file -o file -c		(wont error - see file)
		find somestring -i somestring -o file		(wont error - see file)
		find somestring -i somestring -o file -c	(wont error - see file)


  Errors will be printed on the console as will ouput when a file output is not specified.
  All other output will be directed to a file called the file name followed by test. e.g. "Names.txt" --> "Namestest.txt"
		

NOTE: I realise these tests may be rather complicated because 12 commands are executed for each test,
      this is just to illustarte the programs error handling capability. I can explain it all if needed.

