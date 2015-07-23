BASE_DIR = /opt/gcc_build

INSTALL = $(BASE_DIR)/install
CC = $(INSTALL)/bin/g++
NEW_PATH = $(BASE_DIR)/gcc-4.7.2/gcc

OBJS = plugin.o

GCCPLUGINS_DIR:= $(shell $(CC) -print-file-name=plugin)
INCLUDE= -I$(GCCPLUGINS_DIR)/include -I$(NEW_PATH)

FLAGS= -fPIC -O0 -g

all: plugin.so

plugin.so: plugin.c 
	$(CC) $(INCLUDE) $(FLAGS) -shared $^ -o $@

test: plugin.so
	$(CC) -fplugin=./plugin.so test.c -O0 -fdump-tree-all -fdump-ipa-all

clean:
	\rm -f plugin.so test *.c.* *~ *.o a.out

