# direktoriji
SRC_DIR = includes/c
OBJ_DIR = .tmp/o

# fajlovi
MAIN = main.c
OBJS = $(OBJ_DIR)/main.o $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

# compiler i flags
CC = clang
CFLAGS = -Wall -Wextra -O0 -Iincludes/c

# naziv finalnog executable-a
TARGET = program

# default target
all: $(TARGET)

# linkanje svih .o u program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -g

# kompajliranje main.c
$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -g

# kompajliranje .c fajlova iz includes/c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -g

# osiguranje da obj direktorij postoji
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)