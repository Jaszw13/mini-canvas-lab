CPPFLAGS :=-std=c++11 -Wall -Werror=vla
OBJS := assignment.o user.o submission.o main.o

lab2: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

lab2-leak: $(OBJS)
	g++ $(CPPFLAGS) -fsanitize=address,undefined,leak -o $@ $(OBJS)

%.o: %.cpp
	g++ $(CPPFLAGS) -c $<
