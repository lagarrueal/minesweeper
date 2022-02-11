# MINESWEEPER
Minesweeper made in C playable in a Linux terminal<br/>
Makefile included for easier compilation and saving of the source files, creation of the documentation and deleting files.

**Compiling the code:**
- from the terminal, go to the root of the directory *minesweeper*
- type the command:      `make` 

**Executing the program:**
- the executable file is in the *bin* directory
- go to the bin directory using the terminal
- type:       `./Minesweeper` to execute the program

or
- from the root of the directory *minesweeper*
- type:       `./bin/Minesweeper` to execute the program

**Create the doc:**
- in the terminal type the command:    `make doc`
- The doc is created in the *docs* directory

**Make a save of source files:**
- in the terminal type the command:    `make save`
- all the files from the directory *src* are copied to the directory *save*

**Delete object files:**
- in the terminal type the command:    `make clean`
- object files will be deleted from the *bin* directory

**Delete all except the sources:**
- in the terminal type the commande:    `make mrproper`

