all: media ab dY dAdB

media: media.c
	gcc -o media  media.c

ab: ab.c
	gcc -o ab  ab.c

dY: dY.c
	gcc -o dY  dY.c 

dAdB: dAdB.c
	gcc -o dAdB  dAdB.c

dB: dB.c
	gcc -o dB  dB.c

run_me: media
	./media
run_ab: ab
	./ab
run_dY: dY
	./dY
run_dAdB: dAdB
	./dAdB