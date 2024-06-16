CC = clang
CFLAGS = -g -Wall
TARGET = out/my_program
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, out/%.o, $(SRCS))

# Create the output directory if it doesn't exist
$(shell mkdir -p out)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

out/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf out

# Define a rule to run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
