# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:13:49 by javi              #+#    #+#              #
#    Updated: 2024/03/18 19:16:32 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = brain

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

OBJDIR = obj
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(OBJECTS:.o=.d)

clean:
	@rm -rf $(OBJDIR) $(OBJDIR)/*.d
	@echo "Objects removed" 

fclean: clean
	@rm -f $(TARGET)
	@echo "All clean"

re: fclean all

.PHONY: all clean fclean re
