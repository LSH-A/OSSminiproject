CC = gcc
CFLAGS = -W -Wall
TARGET = pd
DTARGET = pd_debug
OBJECTS= main.c product.o manager.o
all : $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean:
	rm *.o pd* 
