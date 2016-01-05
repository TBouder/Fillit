# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2015/12/18 14:48:31 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fillit

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_launcher.c \
				ft_check_form.c \
				ft_check_content.c \
				ft_extract_form.c \
				ft_split.c \
				ft_resolv.c \
				ft_resolv_helper.c \
				ft_helpers.c

LIB			=	ft_lib.c ft_lib_two.c ft_lib_three.c

OBJ			=	$(SRC:.c=.o) $(LIB:.c=.o)

HEADER 		=	fillit.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC) $(LIB)
	$(CC) -o $(NAME) $(OBJ)

.SILENT : clean
clean:
	rm -f $(OBJ)

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT : test
test: re
	echo "test1-OK : "		
	./fillit tests/test1-OK
	echo "\ntest2-OK : "	
	./fillit tests/test2-OK
	echo "\ntest3-OK : "	
	./fillit tests/test3-OK
	echo "\ntest4-KO : "	
	./fillit tests/test4-KO
	echo "\ntest5-OK : "	
	./fillit tests/test5-OK
	echo "\ntest6-OK : "	
	./fillit tests/test6-OK
	echo "\ntest7-OK : "	
	./fillit tests/test7-OK
	echo "\ntest8-OK : "	
	./fillit tests/test8-OK
	echo "\ntest9-OK : "	
	./fillit tests/test9-OK
	echo "\ntest10-OK : "	
	./fillit tests/test10-OK
	echo "\ntestnullsecond : "	
	./fillit tests/testnullsecond || true
	echo "\ntestNULL : "	
	./fillit tests/testnull || true

.SILENT : testerror
testerror: re
	echo "\nN tests (only error) : " 
	cat tests/n0
	echo "----------"
	./fillit tests/n0 || true
	echo ""
	cat tests/n1
	echo "----------"
	./fillit tests/n1 || true
	echo ""
	cat tests/n2
	echo "----------"
	./fillit tests/n2 || true
	echo ""
	cat tests/n3
	echo "----------"
	./fillit tests/n3 || true
	echo ""
	cat tests/n4
	echo "----------"
	./fillit tests/n4 || true
	echo ""
	cat tests/n5
	echo "----------"
	./fillit tests/n5 || true
	echo ""
	cat tests/n6
	echo "----------"
	./fillit tests/n6 || true
	echo ""
	cat tests/n7
	echo "----------"
	./fillit tests/n7 || true
	echo ""
	cat tests/n8
	echo "----------"
	./fillit tests/n8 || true
	echo ""
	cat tests/n9
	echo "----------"
	./fillit tests/n9 || true
	echo ""

	echo "\nA tests (only error) : " 
	cat tests/a0
	echo "----------"
	./fillit tests/a0 || true
	echo ""
	cat tests/a1
	echo "----------"
	./fillit tests/a1 || true 
	echo ""
	cat tests/a2
	echo "----------"
	./fillit tests/a2 || true 
	echo ""
	cat tests/a3
	echo "----------"
	./fillit tests/a3 || true 
	echo ""
	cat tests/a4
	echo "----------"
	./fillit tests/a4 || true
	echo ""
	cat tests/a5
	echo "----------"
	./fillit tests/a5 || true
	echo ""
	cat tests/a6
	echo "----------"
	./fillit tests/a6 || true
	echo ""
	cat tests/a7
	echo "----------"
	./fillit tests/a7 || true
	echo ""
	cat tests/a8
	echo "----------"
	./fillit tests/a8 || true
	echo ""
	cat tests/a9
	echo "----------"
	./fillit tests/a9 || true
	echo ""

.SILENT : testbc
testbc: re
	echo "\nB + C tests (only succes 1T) : " 
	cat tests/b0
	echo "----------"
	./fillit tests/b0 || true
	echo "\n"
	cat tests/b1
	echo "----------"
	./fillit tests/b1 || true 
	echo "\n"
	cat tests/b2
	echo "----------"
	./fillit tests/b2 || true
	echo "\n" 
	cat tests/b3
	echo "----------"
	./fillit tests/b3 || true 
	echo "\n"
	cat tests/b4
	echo "----------"
	./fillit tests/b4 || true
	echo "\n"
	cat tests/b5
	echo "----------"
	./fillit tests/b5 || true
	echo "\n"
	cat tests/b6
	echo "----------"
	./fillit tests/b6 || true
	echo "\n"
	cat tests/b7
	echo "----------"
	./fillit tests/b7 || true
	echo "\n"
	cat tests/b8
	echo "----------"
	./fillit tests/b8 || true
	echo "\n"
	cat tests/b9
	echo "----------"
	./fillit tests/b9 || true
	echo "\n"
	cat tests/c0
	echo "----------"
	./fillit tests/c0 || true
	echo "\n"
	cat tests/c1
	echo "----------"
	./fillit tests/c1 || true 
	echo "\n"
	cat tests/c2
	echo "----------"
	./fillit tests/c2 || true
	echo "\n" 
	cat tests/c3
	echo "----------"
	./fillit tests/c3 || true 
	echo "\n"
	cat tests/c4
	echo "----------"
	./fillit tests/c4 || true
	echo "\n"
	cat tests/c5
	echo "----------"
	./fillit tests/c5 || true
	echo "\n"
	cat tests/c6
	echo "----------"
	./fillit tests/c6 || true
	echo "\n"
	cat tests/c7
	echo "----------"
	./fillit tests/c7 || true
	echo "\n"
	cat tests/c8
	echo "----------"
	./fillit tests/c8 || true
	echo "\n"
	cat tests/c9
	echo "----------"
	./fillit tests/c9 || true
	echo "\n"

.SILENT : testde
testde: re
	echo "\nD + E tests (only succes 2T) : " 
	cat tests/d0
	echo "----------"
	./fillit tests/d0 || true
	echo "\n"
	cat tests/d1
	echo "----------"
	./fillit tests/d1 || true
	echo "\n"
	cat tests/d2
	echo "----------"
	./fillit tests/d2 || true
	echo "\n"
	cat tests/d3
	echo "----------"
	./fillit tests/d3 || true
	echo "\n"
	cat tests/d4
	echo "----------"
	./fillit tests/d4 || true
	echo "\n"
	cat tests/d5
	echo "----------"
	./fillit tests/d5 || true
	echo "\n"
	cat tests/d6
	echo "----------"
	./fillit tests/d6 || true
	echo "\n"
	cat tests/d7
	echo "----------"
	./fillit tests/d7 || true
	echo "\n"
	cat tests/d8
	echo "----------"
	./fillit tests/d8 || true
	echo "\n"
	cat tests/d9
	echo "----------"
	./fillit tests/d9 || true
	echo "\n"




.SILENT : testf
testf: re
	cat tests/f1
	echo "----------"
	./fillit tests/f1 || true 
	echo ""

	cat tests/f2
	echo "----------"
	./fillit tests/f2 || true
	echo "" 

	cat tests/f3
	echo "----------"
	./fillit tests/f3 || true 
	echo ""

	cat tests/f4
	echo "----------"
	./fillit tests/f4 || true
	echo ""

	cat tests/f5
	echo "----------"
	./fillit tests/f5 || true
	echo ""

	cat tests/f6
	echo "----------"
	./fillit tests/f6 || true
	echo ""