NBC:
ifeq ($(OS),Windows_NT)
	gcc -g *.c src/*.c src/*.h -Werror -o nbc.exe
else
	gcc -g *.c src/*.c src/*.h -Werror -o nbc
endif

	
