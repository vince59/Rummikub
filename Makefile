export DEBUG=yes
export CC=gcc
#LOG_LEVEL = 1 : error only, 2 : error and warning, 3 : error warning and info
ifeq ($(DEBUG),yes)
	CFLAGS=-I./include/  -W -Wall  -pedantic -g -D LOG_LEVEL=3
else
	CFLAGS=-I./include/ -W -Wall  -pedantic -D LOG_LEVEL=1
endif
export CFLAGS
export LDFLAGS=

LIB_DIR=src/lib

EXEC=rummik
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)
	@echo "compilation de Rummik"

rummik: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
	