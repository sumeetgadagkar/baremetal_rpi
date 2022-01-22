AArch64_TOOLCHAIN  = ../gcc-arm-aarch64-none-elf/bin/aarch64-none-elf-
BIN = ./bin/
SRC = ./src/
OBJS = main.o gpio.o
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -MMD 
ASMFLAGS = -MMD
INCLUDE_PATHS = -I../gcc-arm-aarch64-none-elf/lib/gcc/aarch64-none-elf/10.3.1/include -Iinc

echo = @echo
rm = @rm

.PHONY : all clean debug debug_flag

all: bin clean kernel8.img

debug : debug_flag all

debug_flag :
	$(eval CFLAGS += $(DEBUG))

bin:
	if ! test -d $(BIN);\
	then mkdir $(BIN);\
	fi

%.o: $(SRC)%.c
	$(AArch64_TOOLCHAIN)gcc $(CFLAGS) $(INCLUDE_PATHS) -c $< -o $(BIN)$@

start.o: start.S
	$(AArch64_TOOLCHAIN)gcc $(ASMFLAGS) -c start.S -o $(BIN)start.o

kernel8.img: start.o $(OBJS)
	$(AArch64_TOOLCHAIN)ld -nostdlib $(BIN)start.o $(addprefix $(BIN), $(OBJS)) -Map=$(BIN)kernel8.map  -T link.ld -o $(BIN)kernel8.elf
	$(AArch64_TOOLCHAIN)objcopy -O binary $(BIN)kernel8.elf $(BIN)kernel8.img

clean:
	$(rm) $(BIN)kernel8.elf $(BIN)*.o $(BIN)kernel8,map >/dev/null 2>/dev/null || true