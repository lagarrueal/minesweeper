#variables de compilation
CC := gcc 
#options de compilation
CFLAGS := -Wall -I.
#variable de linkage
LDFLAGS := -lm

#variables pour les dossiers
BINDIR := bin
SRCDIR := src
DOCDIR := docs
SAVEDIR := save
#variable de doc
DOXYFILE := Doxyfile

CP := cp
SRC := $(wildcard $(SRCDIR)/*.c )
HEAD = $(wildcard $(SRCDIR)/*.h )
OBJ := $(subst $(SRCDIR), $(BINDIR),$(SRC:.c=.o))
PROG ?= Minesweeper
BIN := $(addprefix $(BINDIR)/, $(PROG))

#compilation du programme
.PHONY: all
all: $(BIN)

$(BINDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

#fait une sauvegarde des fichiers sources dans le répertoire save	
.PHONY: save 
save: 
	$(CP) $(SRCDIR)/* $(SAVEDIR)/

#génère la doc html et latex dans le répertoire docs
.PHONY: doc
doc: $(DOXYFILE)
	@doxygen $(DOXYFILE)

#supprime les fichiers objet
.PHONY: clean
clean: 
	@rm -rf $(BINDIR)/*.o 

#supprime l'exécutable, la sauvegarde des sources, les documentations
.PHONY: mrproper
mrproper: clean
	@rm -rf $(BIN) $(SAVE) $(DOCDIR)/html $(DOCDIR)/latex 
