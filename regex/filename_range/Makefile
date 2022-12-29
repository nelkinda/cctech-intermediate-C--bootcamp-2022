SHELL:=bash

.PHONY: all
all: test

.PHONY: test
test: filename_range
	diff <<<'"hiker": [0,5],' - <(./filename_range hiker)
	diff <<<'"hiker.re": [0,5],' - <(./filename_range hiker.re)
	diff <<<'"hiker.feature": [0,5],' - <(./filename_range hiker.feature)
	diff <<<'"hiker.fun": [0,5],' - <(./filename_range hiker.fun)
	diff <<<'"hiker.t": [0,5],' - <(./filename_range hiker.t)
	diff <<<'"hiker.plt": [0,5],' - <(./filename_range hiker.plt)
	diff <<<'"test_hiker.rb": [5,10],' - <(./filename_range test_hiker.rb)
	diff <<<'"test_hiker.py": [5,10],' - <(./filename_range test_hiker.py)
	diff <<<'"test_hiker.sh": [5,10],' - <(./filename_range test_hiker.sh)
	diff <<<'"tests_hiker.sh": [6,11],' - <(./filename_range tests_hiker.sh)
	diff <<<'"test_hiker.coffee": [5,10],' - <(./filename_range test_hiker.coffee)
	diff <<<'"src/Hiker.re": [4,9],' - <(./filename_range src/Hiker.re)
	diff <<<'"hiker_test": [0,5],' - <(./filename_range hiker_test)
	diff <<<'"src/Hiker_spec.re": [4,9],' - <(./filename_range src/Hiker_spec.re)
	diff <<<'"test/hiker_test.exs": [5,10],' - <(./filename_range test/hiker_test.exs)
	diff <<<'"wibble/test/hiker_spec.rb": [12,17],' - <(./filename_range wibble/test/hiker_spec.rb)
	diff <<<'"hiker_steps.rb": [0,5],' - <(./filename_range hiker_steps.rb)
	diff <<<'"hiker_spec.rb": [0,5],' - <(./filename_range hiker_spec.rb)
	diff <<<'"test_hiker.rb": [5,10],' - <(./filename_range test_hiker.rb)
	diff <<<'"test_hiker.py": [5,10],' - <(./filename_range test_hiker.py)
	diff <<<'"test_hiker.sh": [5,10],' - <(./filename_range test_hiker.sh)
	diff <<<'"tests_hiker.sh": [6,11],' - <(./filename_range tests_hiker.sh)
	diff <<<'"test_hiker.coffee": [5,10],' - <(./filename_range test_hiker.coffee)
	diff <<<'"hiker_spec.coffee": [0,5],' - <(./filename_range hiker_spec.coffee)
	diff <<<'"hikerTest.chpl": [0,5],' - <(./filename_range hikerTest.chpl)
	diff <<<'"hiker.tests.c": [0,5],' - <(./filename_range hiker.tests.c)
	diff <<<'"hiker_tests.c": [0,5],' - <(./filename_range hiker_tests.c)
	diff <<<'"hiker_test.c": [0,5],' - <(./filename_range hiker_test.c)
	diff <<<'"hiker_Test.c": [0,5],' - <(./filename_range hiker_Test.c)
	diff <<<'"HikerTests.cpp": [0,5],' - <(./filename_range HikerTests.cpp)
	diff <<<'"hikerTests.cpp": [0,5],' - <(./filename_range hikerTests.cpp)
	diff <<<'"HikerTest.cs": [0,5],' - <(./filename_range HikerTest.cs)
	diff <<<'"HikerTest.java": [0,5],' - <(./filename_range HikerTest.java)
	diff <<<'"DiamondTest.kt": [0,7],' - <(./filename_range DiamondTest.kt)
	diff <<<'"HikerTest.php": [0,5],' - <(./filename_range HikerTest.php)
	diff <<<'"hikerTest.js": [0,5],' - <(./filename_range hikerTest.js)
	diff <<<'"hiker-test.js": [0,5],' - <(./filename_range hiker-test.js)
	diff <<<'"hiker-spec.js": [0,5],' - <(./filename_range hiker-spec.js)
	diff <<<'"hiker.test.js": [0,5],' - <(./filename_range hiker.test.js)
	diff <<<'"hiker.tests.ts": [0,5],' - <(./filename_range hiker.tests.ts)
	diff <<<'"hiker_tests.erl": [0,5],' - <(./filename_range hiker_tests.erl)
	diff <<<'"hiker_test.clj": [0,5],' - <(./filename_range hiker_test.clj)
	diff <<<'"fizzBuzz_test.d": [0,8],' - <(./filename_range fizzBuzz_test.d)
	diff <<<'"hiker_test.go": [0,5],' - <(./filename_range hiker_test.go)
	diff <<<'"hiker.tests.R": [0,5],' - <(./filename_range hiker.tests.R)
	diff <<<'"hikertests.swift": [0,5],' - <(./filename_range hikertests.swift)
	diff <<<'"HikerSpec.groovy": [0,5],' - <(./filename_range HikerSpec.groovy)
	diff <<<'"hikerSpec.feature": [0,5],' - <(./filename_range hikerSpec.feature)
	diff <<<'"hiker.feature": [0,5],' - <(./filename_range hiker.feature)
	diff <<<'"hiker.fun": [0,5],' - <(./filename_range hiker.fun)
	diff <<<'"hiker.t": [0,5],' - <(./filename_range hiker.t)
	diff <<<'"hiker.plt": [0,5],' - <(./filename_range hiker.plt)
	diff <<<'"hiker": [0,5],' - <(./filename_range hiker)



.PHONY: clean
clean::
	$(RM) *.[adios] *.ii filename_range
