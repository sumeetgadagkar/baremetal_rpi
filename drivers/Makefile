AArch64_TOOLCHAIN  = ../gcc-arm-aarch64-none-elf/bin/aarch64-none-elf-
BIN = ./bin/
OBJS = main.o gpio.o
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -g
INCLUDE_PATHS = -I../gcc-arm-aarch64-none-elf/lib/gcc/aarch64-none-elf/10.3.1/include



echo = @echo
rm = @rm

all: bin clean kernel8.img

bin:
	if ! test -d $(BIN);\
	then mkdir $(BIN);\
	fi

%.o: %.c
	$(AArch64_TOOLCHAIN)gcc $(CFLAGS) $(INCLUDE_PATHS) -c $< -o $(BIN)$@

start.o: start.S
	$(AArch64_TOOLCHAIN)gcc $(CFLAGS) -c start.S -o $(BIN)start.o

kernel8.img: start.o $(OBJS)
	$(AArch64_TOOLCHAIN)ld -nostdlib $(BIN)start.o $(addprefix $(BIN), $(OBJS)) -T link.ld -o $(BIN)kernel8.elf
	$(AArch64_TOOLCHAIN)objcopy -O binary $(BIN)kernel8.elf $(BIN)kernel8.img

clean:
	$(rm) $(BIN)kernel8.elf $(BIN)*.o >/dev/null 2>/dev/null || true