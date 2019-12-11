all: ask1

ask1: main.o Forum_constr.o Thread_constr.o Post_constr.o
	g++ -std=c++11 main.o Forum_constr.o Thread_constr.o Post_constr.o -o ask1

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Forum_constr.o: Forum_constr.cpp
	g++ -std=c++11 -c Forum_constr.cpp

Thread_constr.o: Thread_constr.cpp
	g++ -std=c++11 -c Thread_constr.cpp

Post_constr.o: Post_constr.cpp
	g++ -std=c++11 -c Post_constr.cpp

clean:
		rm -rf *o ask1
