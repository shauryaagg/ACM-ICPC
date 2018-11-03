g++ -std=c++14 *.cpp;
for input in data/*.in ; do
	./a.out <$input> "${input%.in}.out" ;
	diff "${input%.in}.out" "${input%.in}.ans";
done