CC 			= cc
CFLAGS 		= -Wall
OBJFILES 	= pomidor.o main.o
TARGET      = pomidor

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
	rm ~/.local/bin/$(TARGET)

install:
	cp $(TARGET) ~/.local/bin
