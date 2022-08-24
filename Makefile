CC = gcc
V := @
Q := $(V:1=)

SPARSE_LIBS = ./sparse/libsparse.a
CPU = ./riscv-simulator/build/cpu

all: $(SPARSE_LIBS) $(CPU) xv6
	
$(SPARSE_LIBS): sparse/*.c sparse/*.h
	@cd sparse && make && cd ../
	
$(CPU): riscv-simulator/*.hpp riscv-simulator/*.cpp riscv-simulator/Pipeline/*.hpp
	@sh build_cpu.sh

xv6: 
	@cd xv6-labs-2021 && make && cd ../

#$(UTILS_LIBS): utils/*.c utils/*.h
#	@cd utils && make && cd ../
#
#$(PROGRAMS):  % : %.o $(SPARSE_LIBS) $(UTILS_LIBS)
#	@echo "  CC      $@"
#	$(Q)$(CC)  $^ $(SPARSE_LIBS) $(UTILS_LIBS) -o $@

clean:
	@cd sparse && make clean && cd ../
	@cd riscv-simulator && rm -rf build && cd ../
	@cd xv6-labs-2021 && make clean && cd ../
	@rm -rf out && rm -rf test
	