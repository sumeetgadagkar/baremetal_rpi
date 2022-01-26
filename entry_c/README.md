# Entry C
Entry into C code

1. Build with debug flag
   ```
   $ make debug
   ```
2. Run the QEMU emulator
    ```
    $ sudo qemu-system-aarch64 -M raspi3b -serial telnet:127.0.0.1:1000,server,nowait -serial telnet:127.0.0.1:1001,server,nowait -S -kernel ./bin/kernel8.elf
    ```
3. On the QEMU application View -> compatmonitor0, then
    ```
    (qemu) gdbserver
    ```
4. On the linux command line, run the gdb console
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
    _start () at start.S:9
    9           mrs x1, mpidr_el1
    ```
7. Put breakpoint at main
    ```
    (gdb) b main
    Breakpoint 1 at 0x80050: file main.c, line 5.
    (gdb) c
    Continuing.

    Thread 1 hit Breakpoint 1, main () at main.c:5
    5           while(1)
    ```