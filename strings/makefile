programName := strings
location := ./src
dep := string.c

$(programName): $(location)/main.c $(location)/$(dep)
	gcc -o $(programName) $(location)/main.c $(location)/$(dep)

clean:
	rm $(programName)