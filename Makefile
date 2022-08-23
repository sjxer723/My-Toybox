CC = gcc
V := @
Q := $(V:1=)

SPARSE_LIBS = ./sparse/libsparse.a
CPU = ./riscv-simulator/build/cpu

all: $(SPARSE_LIBS) $(CPU)
	
$(SPARSE_LIBS): sparse/*.c sparse/*.h
	@cd sparse && make && cd ../

build = $(shell if [-d $(risc-v-cpu)/build]; then echo "exist"; else echo "noexist"; fi)
	
$(CPU): riscv-simulator/*.hpp riscv-simulator/*.cpp riscv-simulator/Pipeline/*.hpp
	@sh build_cpu.sh
#$(UTILS_LIBS): utils/*.c utils/*.h
#	@cd utils && make && cd ../
#
#$(PROGRAMS):  % : %.o $(SPARSE_LIBS) $(UTILS_LIBS)
#	@echo "  CC      $@"
#	$(Q)$(CC)  $^ $(SPARSE_LIBS) $(UTILS_LIBS) -o $@

clean:
	@cd sparse && make clean && cd ../
	@cd riscv-simulator && rm -rf build && cd ../
	@rm -rf out && rm -rf test