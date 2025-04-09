# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 07:09:53 by lleciak           #+#    #+#              #
#    Updated: 2024/09/24 17:11:22 by lleciak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################
#######ARGUMENTS

NAME            = zombies
CXXFLAGS        = -Wall -Wextra -Werror -std=c++98
FILES           = main.cpp Zombie.cpp zombieHorde.cpp
OBJECTS         = $(FILES:.cpp=.o)
CXX             = c++
RM              = rm -f

##########################################################
#######RULES

all:	$(NAME)

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}
                
$(NAME):	$(OBJECTS)
			$(CXX) $(CXXFLAGS) -I ./ -o $(NAME) $(OBJECTS)    
                            
clean:
		$(RM) $(OBJECTS)                
fclean: clean
			$(RM) $(NAME)

test:	$(NAME)
		./$(NAME)

vtest:	$(NAME)
		valgrind --leak-check=full ./$(NAME)

re: fclean all
.PHONY: all clean fclean re test vtest