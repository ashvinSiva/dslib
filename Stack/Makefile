CC = clang
CFLAGS = -Wall -Wextra -g 
SRCS = ArrayStack.c testArrayStack.c
TARGET = test_stack


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

.PHONY: run debug leaks clean


