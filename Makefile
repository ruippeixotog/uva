CC_FILES = $(wildcard src/*.cc)
BIN_FILES = $(patsubst src/%.cc, %, $(CC_FILES))
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

.PHONY: check-syntax
check-syntax:
	$(CC) $(CC_FLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

%: src/%.cc
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)