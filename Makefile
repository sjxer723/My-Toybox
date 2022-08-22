CC = gcc
V := @
Q := $(V:1=)

SPARSE_LIBS = ./sparse/libsparse.a

all: $(SPARSE_LIBS)
	
$(SPARSE_LIBS): sparse/*.c sparse/*.h
	@cd sparse && make && cd ../

#$(UTILS_LIBS): utils/*.c utils/*.h
#	@cd utils && make && cd ../
#
#$(PROGRAMS):  % : %.o $(SPARSE_LIBS) $(UTILS_LIBS)
#	@echo "  CC      $@"
#	$(Q)$(CC)  $^ $(SPARSE_LIBS) $(UTILS_LIBS) -o $@

clean:
	@cd sparse && make clean && cd ../