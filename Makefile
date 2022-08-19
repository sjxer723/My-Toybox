CC = gcc
V := @
Q := $(V:1=)
PROGRAMS = hello
LIBS = ./sparse/libsparse.a

all: 
	cd sparse && make && cd ../
	make hello

$(PROGRAMS):  % : %.o
	@echo "  CC      $@"
	$(Q)$(CC)  $^ $(LIBS) -o $@

clean:
	@rm -f $(PROGRAMS) && cd sparse && make clean && cd ../