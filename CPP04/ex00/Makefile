# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 07:09:53 by lleciak           #+#    #+#              #
#    Updated: 2024/10/28 11:11:25 by lleciak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################
#######ARGUMENTS

NAME            = Animal
CXXFLAGS        = -Wall -Wextra -Werror -std=c++98
FILES           = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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

re: fclean all
.PHONY: all clean fclean re test vtest