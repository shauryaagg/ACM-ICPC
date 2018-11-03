g++ -std=c++17 *.cpp;
for input in data/*.in ; do
	./a.out <$input> "${input%.in}.out" ;
	diff "${input%.in}.out" "${input%.in}.ans";
done