build:
	gcc -c src/libpear.c -o src/libpear.o
	ar rcs libpear.a src/libpear.o

test:
	gcc -I src $(FILE) -L. -lpear -o output
	.\output.exe

clean:
	-powershell -Command "Remove-Item -Force src\libpear.o, libpear.a, output.exe -ErrorAction SilentlyContinue"

# clean:
# 	rm -f src/pear_table.o libpear.a main.exe