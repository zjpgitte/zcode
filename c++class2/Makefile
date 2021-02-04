main:main.o class.o
	g++ $^ -o $@
%.o:%.c
	g++ -c $<
.PHONY:clean
clean:
	rm -f *.o main
