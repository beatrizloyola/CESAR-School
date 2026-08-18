CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
TARGET = tensor
SRC = tensor.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) tensor_*.out

.PHONY: clean
