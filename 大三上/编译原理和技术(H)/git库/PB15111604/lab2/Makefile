all:
	c++ fib_gen.cpp  `llvm-config --cxxflags --ldflags --system-libs --libs`  -o fib_gen
	./fib_gen 
	./fib_gen > f.ll
	echo "lli f.ll" > tmp.sh
	echo -n "if [ $$" >> tmp.sh
	echo "? = 88 ]" >> tmp.sh
	echo "then" >> tmp.sh
	echo "    echo returned 88, OK!" >> tmp.sh
	echo "else" >> tmp.sh
	echo "    echo returned $$?, not OK!" >> tmp.sh
	echo "fi" >> tmp.sh
	sh ./tmp.sh
clean:
	rm tmp.sh fib_gen