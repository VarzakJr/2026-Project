CC = gcc
CFLAGS = -Wall -Wno-implicit-function-declaration
TARGET = myanalyzer

all: $(TARGET)

$(TARGET): lex.yy.c myanalyzer.tab.c
	$(CC) $(CFLAGS) lex.yy.c myanalyzer.tab.c cgen.c -o $(TARGET) -lfl

myanalyzer.tab.c myanalyzer.tab.h: myanalyzer.y
	bison -d myanalyzer.y

lex.yy.c: mylexer.l myanalyzer.tab.h
	flex mylexer.l

clean:
	rm -f lex.yy.c myanalyzer.tab.c myanalyzer.tab.h $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
