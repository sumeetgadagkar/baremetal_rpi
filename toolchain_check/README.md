# Toolchain Check
Sanity check for the toolchain and QEMU

1. Build with debug flag
   ```
   $ make debug
   ```
2. Run the QEMU emulator
    ```
    $ sudo qemu-system-aarch64 -M raspi3 -serial telnet:127.0.0.1:1000,server,nowait -serial telnet:127.0.0.1:1001,server,nowait -S -kernel ./bin/kernel8.elf
    ```
3. On the QEMU application View -> compatmonitor0, then
    ```
    (qemu) gdbserver
    ```
4. On the linux command line
    ```
    $ <Aarch64 toolchain bin>/aarch64-none-elf-gdb ./bin/kernel8.elf
    ```
5. On the gdb console
    ```
    (gdb) target remote localhost:1234
    ```
6. Observer the following output
    ```
    Remote debugging using localhost:1234
    _start () at start.S:8
    8       1: wfe
    ```