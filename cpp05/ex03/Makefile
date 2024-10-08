# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:13:49 by javi              #+#    #+#              #
#    Updated: 2024/04/14 17:11:43 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

TARGET = $(BINDIR)/$(NAME)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

OBJDIR = obj
SRCDIR = src
HDRDIR = headers
BINDIR = bin

HEADERS = -I./$(HDRDIR)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

# Building the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Building object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(HEADERS) -MMD -MP -c $< -o $@

# Include the .d files
-include $(DEPS)

clean:
	rm -rf $(OBJDIR) $(DEPS)
	rm -rf *_shrubbery

fclean: clean
	rm -f $(TARGET)
	rm -rf $(BINDIR)

re: fclean all

.PHONY: all clean fclean re intern
