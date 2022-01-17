AArch64_TOOLCHAIN  = ../gcc-arm-aarch64-none-elf/bin/aarch64-none-elf-
BIN = ./bin/
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

echo = @echo
rm = @rm

.PHONY : all clean

all: bin clean kernel8.img

bin:
	if ! test -d $(BIN);\
	then mkdir $(BIN);\
	fi

start.o: start.S
	$(AArch64_TOOLCHAIN)gcc $(CFLAGS) -c start.S -o $(BIN)start.o

kernel8.img: start.o
	$(AArch64_TOOLCHAIN)ld -nostdlib $(BIN)start.o -T link.ld -o $(BIN)kernel8.elf
	$(AArch64_TOOLCHAIN)objcopy -O binary $(BIN)kernel8.elf $(BIN)kernel8.img

clean:
	$(rm) $(BIN)kernel8.elf $(BIN)*.o >/dev/null 2>/dev/null || true