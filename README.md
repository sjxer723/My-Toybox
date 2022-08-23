# My-Toybox
This repo will provide a program analysis platform, which can automatically monitor the runtime behaviors of programs (e.g., function calls, caching, and branch prediction).


## Setup Enviroment
To begin with this project, you can configure the enviroment via the following several ways:

* **Ubuntu:**

    Run the following commands:

        sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu cmake

* **Mac OS:**

     Run the following commands:

        brew tap riscv/riscv
        brew install riscv-tools
        PATH=$PATH:/usr/local/opt/riscv-gnu-toolchain/bin
        brew install qemu

* **From docker:**

        docker pull sjx723/my_toybox:latest
