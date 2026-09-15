CC = clang 
CFLAGS = -Wall -Wextra -g
SRCS = testHT.c hashtable.c
TARGET = testHT

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(SRCS)
	$(CC) $(CFLAGS) -fsanitize=address -o $(TARGET)_asan $(SRCS) 
	./$(TARGET)_asan

leaks: $(TARGET)
	leaks --atExit -- ./$(TARGET)

clean: 
	rm -f $(TARGET) $(TARGET)_asan *.o

# Tells 'make' that these 4 keywords isn't a physical file layout and are commands
.PHONY: run debug leaks clean

