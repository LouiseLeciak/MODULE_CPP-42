# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 07:09:53 by lleciak           #+#    #+#              #
#    Updated: 2024/11/22 16:51:56 by lleciak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################################
#######ARGUMENTS

NAME            = Form
CXXFLAGS        = -Wall -Wextra -Werror -std=c++98 -g3
FILES           = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/PresidentialPardonForm.cpp src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp src/Intern.cpp
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