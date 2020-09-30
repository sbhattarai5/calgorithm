src:= $(wildcard *.cpp)

.PHONY: $(src)

$(src):
	g++ $@ -lgtest -lgtest_main -lpthread
	./a.out
	rm a.out
