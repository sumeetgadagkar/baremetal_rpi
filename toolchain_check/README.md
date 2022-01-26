# Toolchain Check
Sanity check for the toolchain and QEMU

1. Build with debug flag
   ```
   $ make debug
   ```
2. Ensure that the libraries `libncursesw5` and `libpython2.7` are installed
    ```
    $ sudo apt install -y libncursesw5 libpython2.7
    $ sudo ldconfig
    ```   
3. Run the QEMU emulator
    Note: Add <QEMU directory>/build (~/qemu-6.2.0/build) to PATH
    ```
    $ sudo qemu-system-aarch64 -M raspi3b -serial telnet:127.0.0.1:1000,server,nowait -serial telnet:127.0.0.1:1001,server,nowait -S -kernel ./bin/kernel8.elf
    ```
4. On the QEMU application View -> compatmonitor0, then
    ```
    (qemu) gdbserver
    ```
5. On the linux command line, run the gdb console
    ```
    $ <Aarch64 toolchain bin>/aarch64-none-elf-gdb ./bin/kernel8.elf
    ```
6. On the gdb console
    ```
    (gdb) target remote localhost:1234
    ```
7. Observe the following output
    ```
    Remote debugging using localhost:1234
    _start () at start.S:8
    8       1: wfe
    ```