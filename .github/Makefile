CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET_LRU = RodCut_LRU
TARGET_MRU = RodCut_MRU
SRC = main.c rod_cut.c
OBJ = $(SRC:.c=.o)

all: $(TARGET_LRU) $(TARGET_MRU)

$(TARGET_LRU): $(OBJ) cache_lru.o
	$(CC) $(CFLAGS) -o $(TARGET_LRU) $(OBJ) cache_lru.o

$(TARGET_MRU): $(OBJ) cache_mru.o
	$(CC) $(CFLAGS) -o $(TARGET_MRU) $(OBJ) cache_mru.o

cache_lru.o: cache_lru.c cache.h
	$(CC) $(CFLAGS) -c cache_lru.c -o cache_lru.o

cache_mru.o: cache_mru.c cache.h
	$(CC) $(CFLAGS) -c cache_mru.c -o cache_mru.o

%.o: %.c rod_cut.h cache.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) cache_lru.o cache_mru.o $(TARGET_LRU) $(TARGET_MRU)

run_lru: $(TARGET_LRU)
	./$(TARGET_LRU) input.txt

run_mru: $(TARGET_MRU)
	./$(TARGET_MRU) input.txt

.PHONY: all clean run_lru run_mru
