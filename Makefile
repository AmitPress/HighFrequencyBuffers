build:
	cc ringbuffer.c main.c -o main
strict-build:
	cc -Wall -Wextra -Werror ringbuffer.c main.c -o main
run:
	./main
clean:
	rm -rf main