all:
	[ -s bin ] || mkdir bin
	avr-g++ -g -Os -mmcu=atmega128 -std=gnu++17 -c src/gpio.cpp -o bin/gpio.o
	avr-g++ -g -Os -mmcu=atmega128 -std=gnu++17 -c src/uart.cpp -o bin/uart.o
	avr-g++ -g -mmcu=atmega128 -o bin/gpio.elf bin/gpio.o bin/uart.o
	avr-objcopy -j .text -j .data -O ihex bin/gpio.elf bin/gpio.hex

load:
	avrdude -c usbasp -p m128 -U flash:w:bin/gpio.hex
	
clean:
	rm bin -rf
