CC_FILES = $(wildcard src/*.cc)
BIN_FILES = $(patsubst src/%.cc, %, $(CC_FILES))
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

%: src/%.cc
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
