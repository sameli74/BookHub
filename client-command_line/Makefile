all: client

client: main.cpp client_socket.o tools.o methods.o UI.o Client.o Machine.o Book.o Edit.o Visitor.o
	g++ main.cpp client_socket.o tools.o methods.o UI.o Client.o Machine.o Book.o Edit.o Visitor.o -o client

client_socket.o: client_socket.cpp client_socket.h tools.h network_exception.h
	g++ -c client_socket.cpp

tools.o: tools.cpp tools.h
	g++ -c tools.cpp

methods.o: methods.cpp methods.h
	g++ -g -c methods.cpp

UI.o: UI.cpp UI.h Client.h Machine.h
	g++ -g -c UI.cpp

Client.o: Client.cpp Client.h methods.h Machine.h client_socket.h Book.h Visitor.h
	g++ -g -c Client.cpp

Visitor.o: Visitor.h Visitor.cpp Book.h methods.h
	g++ -g -c Visitor.cpp

Machine.o: Machine.cpp Machine.h Edit.h Client.h
	g++ -g -c Machine.cpp

Book.o: Book.cpp Book.h Edit.h methods.h
	g++ -g -c Book.cpp

Edit.o: Edit.cpp Edit.h methods.h
	g++ -g -c Edit.cpp


clean:
	rm *.o
	rm *.out
