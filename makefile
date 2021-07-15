TARGET=keno
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic

BIN=./bin
OBJS= $(BIN)/main.o $(BIN)/KenoBet.o
all: $(OBJS)
	$(LD) -o $(BIN)/$(TARGET) $(OBJS) $(LDFLAGS)
 
$(BIN)/main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o $(BIN)/main.o
 
$(BIN)/KenoBet.o: src/KenoBet.cpp
	$(CC) -c $(CCFLAGS) src/KenoBet.cpp  -o $(BIN)/KenoBet.o
 
clean:
	rm -f $(BIN)/*.o $(BIN)/keno
