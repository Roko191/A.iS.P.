# direktoriji
SRC_DIR = includes/c
OBJ_DIR = .tmp/o

# fajlovi
MAIN = main.c
OBJS = $(OBJ_DIR)/main.o $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

# compiler i flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iincludes/c

# naziv finalnog executable-a
TARGET = program

# default target
all: $(TARGET)

# linkanje svih .o u program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# kompajliranje main.c
$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# kompajliranje .c fajlova iz includes/c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# osiguranje da obj direktorij postoji
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)