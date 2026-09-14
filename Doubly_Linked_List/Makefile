#Define Macros (variables)
CC = clang
CFLAGS = -Wall -Wextra -g 
SRCS = testDLList.c DLList.c
TARGET = testDLL


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
