# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:13:49 by javi              #+#    #+#              #
#    Updated: 2024/04/13 23:40:09 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = phonebook

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

OBJDIR = obj
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(TARGET)

# Building executable
$(TARGET):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Building object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(OBJDIR)/*.d

clean:
	rm -rf $(OBJDIR) $(OBJDIR)/*.d

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

