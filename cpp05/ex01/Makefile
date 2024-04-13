# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:13:49 by javi              #+#    #+#              #
#    Updated: 2024/04/09 18:36:42 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = maggots

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

OBJDIR = obj
SRCDIR = src
HDRDIR = headers
BINDIR = bin

HEADERS = -I./$(HDRDIR)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(TARGET)

# Buildind executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

# Building object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(HEADERS) -c $< -o $@
	$(CXX) $(CXXFLAGS) $(HEADERS) -MM $< -MF $(@:.o=.d) -MT $@

# Include the .d files
-include $(OBJECTS:.o=.d)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(BINDIR)

re: fclean all

.PHONY: all clean fclean re maggots
