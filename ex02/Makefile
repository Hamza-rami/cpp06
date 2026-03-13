NAME = typeinfo
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Base.cpp A.cpp B.cpp C.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Base.hpp A.hpp B.hpp C.hpp

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