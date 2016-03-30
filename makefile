
export CC=gcc
export CFLAGS=-c -Wall
export LDFLAGS=

export OBJ_FILE_DIR=obj
export EXE_BIN_DIR=bin

all:
	-mkdir -p $(OBJ_FILE_DIR)
	-mkdir -p $(EXE_BIN_DIR)
	$(MAKE) -C example
	
clean:
	$(MAKE) -C example clean
	