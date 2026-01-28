OBJECT = interop.c
OBJECT2 = test.c
CFLAGS = -Wall -g
OUT = ./out/
_out := $(shell mkdir -p out)

ifeq ($(OS), Windows_NT)
TARGET = interop.dll
TARGET2 = test.exe
else ifeq ($(OS), Linux)
TARGET = interop.so
TARGET2 = test.exe
else ifeq ($(OS), Darwin)
TARGET = interop.dy
TARGET2 = test.dmg
else 
TARGET = interop
TARGET2 = test
endif

main: $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) -shared $(OBJECT) -o $(OUT)$(TARGET)
	$(CC) -shared $(OBJECT) -o $(OUT)$(TARGET).a
%.o: %.c
	$(CC) $(CFLAGS) -c $<
 
.PHONY: clean 
clean:
	rm -f $(OUT)$(TARGET) 
	rm -f $(OUT)$(TARGET).a
	rm -f $(OUT)$(TARGET2)
test: $(TARGET)
	$(CC) $(OBJECT2) $(OUT)$(TARGET).a -o $(OUT)$(TARGET2) 