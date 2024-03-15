TARGET=	monkeypi
OBJS=	main.o

SHELL=	/bin/sh
RM=	rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
