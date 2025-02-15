CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGETS=marching_squares

build: $(TARGETS)

marching_squares: main.c read_write_celula.c resize.c grid.c init_contur.c march.c
	$(CC) $(CFLAGS) -o marching_squares main.c read_write_celula.c resize.c grid.c init_contur.c march.c
pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
