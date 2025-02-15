CC=gcc
CFLAGS=-Wall -Wextra 
TARGETS=image_editor

build: $(TARGETS)

image_editor: main.c read.c save.c edit_img.c equalize_histogram.c filters.c
	$(CC) $(CFLAGS) -o image_editor main.c read.c save.c edit_img.c equalize_histogram.c filters.c
pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema3.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
