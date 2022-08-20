CC = gcc
V := @
Q := $(V:1=)
AR = ar
OBJ_LIBS = hashmap.o

all: libutils.a

libutils.a: $(OBJ_LIBS)
	@echo "  AR      $@"
	$(Q)$(AR) rcs $@ $^

hashmap.o: hashmap.c
	@echo "  CC      $@"
	$(Q)$(CC) -c -o $@ $<	
