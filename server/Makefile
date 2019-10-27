all: server

server: main.cpp server_socket.o server.o	tools.o MyServer.o user_on_server.o Visitor.o Book.o Edit.o methods.o
	g++ main.cpp server_socket.o server.o tools.o MyServer.o user_on_server.o Visitor.o Book.o Edit.o methods.o -o server

server.o: server.cpp server.h
	g++ -c server.cpp

server_socket.o: server_socket.cpp server_socket.h tools.h network_exception.h
	g++ -c server_socket.cpp

tools.o: tools.cpp tools.h
	g++ -c tools.cpp

methods.o: methods.cpp methods.h
	g++ -g -c methods.cpp

UI.o: UI.cpp UI.h Client.h Machine.h
	g++ -g -c UI.cpp

MyServer.o: MyServer.cpp user_on_server.h Visitor.h MyServer.h methods.h Book.h Edit.h available_books.h
	g++ -g -c MyServer.cpp

user_on_server.o: user_on_server.h user_on_server.cpp Visitor.h
	g++ -g -c user_on_server.cpp

Visitor.o: Visitor.h Visitor.cpp Book.h methods.h
	g++ -g -c Visitor.cpp

Machine.o: Machine.cpp Machine.h Edit.h Client.h
	g++ -g -c Machine.cpp

Book.o: Book.cpp Book.h Edit.h methods.h
	g++ -g -c Book.cpp

Edit.o: Edit.cpp Edit.h methods.h
	g++ -g -c Edit.cpp


clean:
	rm *.o server
