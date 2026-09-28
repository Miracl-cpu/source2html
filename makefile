CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o evaluation.o s_html.o parcer.o html.o keyword.o
TARGET = source2html.out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET) output.html