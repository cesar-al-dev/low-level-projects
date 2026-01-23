CC=gcc
CPFLAGS=-g -Wall

SRC=main.c
OBJ=$(SRC:.c=.o)
BIN=dwc

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CPFLAGS) -o $(BIN) $(OBJ)

%.o: %.c
	$(CC) -c $(CPFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ) $(BIN)
