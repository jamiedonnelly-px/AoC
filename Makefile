
start:
	@mkdir -p src/day_$(day)
	@cp template.c src/day_$(day)/part1.c
	@cp template.c src/day_$(day)/part2.c 
	@touch src/day_$(day)/input.txt

part1: 
	@echo "Compiling and running part1 for day $(day)..."
	@cd src/day_$(day) && gcc -o part1.o part1.c && ./part1.o

part2: 
	@echo "Compiling and running part2 for day $(day)..."
	@cd src/day_$(day) && gcc -o part2.o part2.c && ./part2.o