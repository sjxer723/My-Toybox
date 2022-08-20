CC = gcc
V := @
Q := $(V:1=)
PROGRAMS = hello

UTILS_LIBS = ./utils/libutils.a
SPARSE_LIBS = ./sparse/libsparse.a

all: $(PROGRAMS)
	
$(SPARSE_LIBS): sparse/*.c sparse/*.h
	@cd sparse && make && cd ../

$(UTILS_LIBS): utils/*.c utils/*.h
	@cd utils && make && cd ../

$(PROGRAMS):  % : %.o $(SPARSE_LIBS) $(UTILS_LIBS)
	@echo "  CC      $@"
	$(Q)$(CC)  $^ $(SPARSE_LIBS) $(UTILS_LIBS) -o $@

clean:
	@rm -f *.[oa] .*.d $(PROGRAMS) utils/*.[oa] sparse/*.[oa]

clean-sparse:
	@cd sparse && make clean && cd ../