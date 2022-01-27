AArch64_TOOLCHAIN  = ../gcc-arm-aarch64-none-elf/bin/aarch64-none-elf-
BIN = ./bin/
SRC = ./src/
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
ASMFLAGS = 
DEBUG = -g
INCLUDE_PATHS = -I../gcc-arm-aarch64-none-elf/lib/gcc/aarch64-none-elf/10.3.1/include -Iinc

echo = @echo
rm = @rm

C_FILES = $(wildcard $(SRC)*.c) $(wildcard $(SRC)*/*.c)
ASM_FILES = $(wildcard *.S) $(wildcard $(SRC)*.S) $(wildcard $(SRC)*/*.S)
OBJS = $(C_FILES:.c=_c.o) $(ASM_FILES:.S=_s.o)

.PHONY : all clean debug debug_flag bin
.SILENT : bin

all: bin clean kernel8.img

debug : debug_flag all

debug_flag :
	$(eval CFLAGS += $(DEBUG))
	$(eval ASMFLAGS += $(DEBUG))

bin:
	if ! test -d $(BIN);\
	then mkdir $(BIN);\
	fi

%_c.o: %.c
	$(AArch64_TOOLCHAIN)gcc $(CFLAGS) $(INCLUDE_PATHS) -c $< -o $(BIN)$(notdir $@)

%_s.o: %.S
	$(AArch64_TOOLCHAIN)gcc $(ASMFLAGS) $(INCLUDE_PATHS) -c $< -o $(BIN)$(notdir $@)

kernel8.img: $(OBJS)
	$(AArch64_TOOLCHAIN)ld -nostdlib $(addprefix $(BIN), $(notdir $(OBJS))) -Map=$(BIN)kernel8.map  -T link.ld -o $(BIN)kernel8.elf
	$(AArch64_TOOLCHAIN)objcopy -O binary $(BIN)kernel8.elf $(BIN)kernel8.img

clean:
	$(rm) $(BIN)kernel8.elf $(BIN)*.o $(BIN)*.d $(BIN)kernel8.map >/dev/null 2>/dev/null || true
	$(rm) null.d >/dev/null 2>/dev/null || true