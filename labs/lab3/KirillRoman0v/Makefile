CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp lib.cpp finish.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=go

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
