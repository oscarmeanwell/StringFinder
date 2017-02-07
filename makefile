stringsearch:
	cl main.c -o find.exe
	
Stest:
	find
	find hello
	find hello -i
	find hello -i FakeFile.txt
	find HELLO -i Scrabble.txt
	find hello -i helloworld
	find hello -i Hello -c
	find hello -o out.txt
	find oscar -i Scrabble.txt -o scrabbletest.txt
	find oscar -i Scrabble.txt -o scrabbletest.txt -c
	find oscar -i oscarmeanwell -o scrabbletest.txt
	find OscaR -i oscArMeanwell -o scrabbletest.txt -c
	
Ntest:
	find
	find oscar
	find oscar -i
	find oscar -i FakeFile.txt
	find OSCAR -i Names.txt
	find oscar -i oscarmeanwell
	find OsCaR -i osCar -c
	find oscar -o out.txt
	find OSCAR -i Names.txt -o namestest.txt
	find oscaR -i Names.txt -o namestest.txt -c
	find oscar -i oscarmeanwell -o namestest.txt
	find OscaR -i oscArMeanwell -o namestest.txt -c


Rtest:
	find
	find napier
	find napier -i
	find napier -i FakeFile.txt
	find napier -i Random.txt
	find napier -i edinburghnapier
	find napier -i napIer -c
	find napier -o out.txt
	find napieriscool -i Random.txt -o randomtest.txt
	find napier -i Random.txt -o randomtest.txt -c
	find napier -i napierstudents -o randomtest.txt
	find napier -i NaPier -o randomtest.txt -c
