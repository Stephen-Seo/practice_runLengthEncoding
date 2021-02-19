SOURCES = src/main.c src/map.c
OBJECTS = $(subst .c,.o,$(SOURCES))

COMMON_FLAGS = -Wall -Wextra -Wpedantic
ifdef DEBUG
	CFLAGS = $(COMMON_FLAGS) -O0 -g
else
	CFLAGS = $(COMMON_FLAGS) -O3 -DNDEBUG
endif

all: RunLengthEncoding

RunLengthEncoding: $(OBJECTS)
	$(CC) -o RunLengthEncoding $^

.PHONY:

clean:
	rm -f RunLengthEncoding
	rm -f src/*.o
