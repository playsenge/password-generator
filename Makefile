make: main.c consoleutils.c passwordgenerator.c lib/csprng.c
	gcc -o main main.c consoleutils.c passwordgenerator.c lib/csprng.c -Wall -Werror -Wpedantic
	./main
