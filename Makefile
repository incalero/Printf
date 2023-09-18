NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Werror -Wextra

TARGET = my_program
SRC = main.c my_printf.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean

# Generar dependencias automáticamente
DEPS := $(SRC:.c=.d)
-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -o $@

# Reglas para no relink si los archivos de encabezado no han cambiado
$(OBJ): $(DEPS)