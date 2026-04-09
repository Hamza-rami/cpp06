NAME = Serializer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Serializer.hpp Data.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all