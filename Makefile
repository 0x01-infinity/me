CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu11

IDIR := include
SRCDIR := src
OBJDIR := obj
BINDIR := bin

SRC := $(wildcard $(SRCDIR)/*.c)

_OBJ := $(SRC:%.c=%.o)
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(_OBJ))

$(BINDIR)/graphics: $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR):
	mkdir $(BINDIR)

$(OBJ) : | $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -I $(IDIR) -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm $(BINDIR)/graphics