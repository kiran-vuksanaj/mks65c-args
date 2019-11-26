ifeq ($(DEBUG),true)
	CFLAGS = -g
endif
all: parseargs.c
	gcc $(CFLAGS) parseargs.c
run:
	./a.out
