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

test1: plugin.so
	$(CC) -o merged -fplugin=./plugin.so test1.c test11.c -O0 -flto -flto-partition=none -fdump-ipa-all

test2: plugin.so
	$(CC) -fplugin=./plugin.so test2.c -O0 -fdump-tree-all -fdump-ipa-all

test3: plugin.so
	$(CC) -fplugin=./plugin.so test3.c -O0 -fdump-tree-all -fdump-ipa-all

clean:
	\rm -f plugin.so test *.c.* *~ *.o a.out

