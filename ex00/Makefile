NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ScalarConverter.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = ScalarConverter.hpp

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