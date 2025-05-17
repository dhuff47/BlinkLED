# Tools
CC = arm-none-eabi-gcc
OPENOCD = openocd

# Flags
CFLAGS = -mcpu=cortex-m0 -mthumb -Wall -Werror -g0 -c
LDFLAGS = -nostdlib -nostartfiles -T linker.ld

# Files
SRCS = startup.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = BlinkLED.elf

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Flash target
flash: $(TARGET)
	$(OPENOCD) -f interface/stlink.cfg -f target/stm32f0x.cfg -c "program ./BlinkLED.elf verify reset exit"

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
