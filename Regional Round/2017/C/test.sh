g++ *.cpp;
for input in 0*.in ; do
	./a.out <$input> "${input%.in}.out" ;
	diff "${input%.in}.out" "${input%.in}.ans";
done