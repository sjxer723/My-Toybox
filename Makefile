CC = gcc
V := @
Q := $(V:1=)
PROGRAMS = hello

OBJ_LIBS = call-graph.o
OBJ_LIBS += utils/hashmap.o

LIBS = ./sparse/libsparse.a

all: $(OBJ_LIBS) $(PROGRAMS)
	
$(LIBS): sparse/*.c sparse/*.h
	@cd sparse && make && cd ../

%.o: %.c
	@echo "  CC      $@"
	$(Q)$(CC) -c -o $@ $<

$(PROGRAMS):  % : %.o $(LIBS)
	@echo "  CC      $@"
	$(Q)$(CC)  $^ $(LIBS) $(OBJ_LIBS) -o $@

clean:
	@rm -f $(PROGRAMS) && rm *.o

clean-sparse:
	@cd sparse && make clean && cd ../