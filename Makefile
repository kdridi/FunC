OPEN		=	open
CC			=	clang
RM			=	rm -rf

CFLAGS		=	-W -Wall -Wextra -Werror
CPPFLAGS	=	

TARGET		=	libFunC.a

SRC			=	$(wildcard src/main/*.c)
OBJ			=	$(SRC:.c=.o)

TEST_SRC	=	$(wildcard src/test/*.c)
TEST_OBJ	=	$(TEST_SRC:.c=.o)

all			:	$(TARGET)

$(TARGET)	:	$(OBJ)
				$(AR) rsc $@ $^

clean		:
				$(RM) $(OBJ)
				$(RM) *.gcda *.gcno *.info

fclean		:	clean
				$(RM) $(TARGET)
				$(RM) tests report

re			:	fclean all

test		:	$(SRC) $(TEST_SRC)
				$(CC) -fprofile-arcs -ftest-coverage -Isrc/main -DMOCKING $(CFLAGS) $(CPPFLAGS) $(shell pkg-config --libs --cflags criterion) $^ -o tests
				./tests

report		:	test
				lcov --capture --initial --directory . --output-file coverage_base.info
				lcov --capture --directory . --output-file coverage_test.info
				lcov --add-tracefile coverage_base.info --add-tracefile coverage_test.info --output-file coverage_merge.info
				lcov --remove coverage_merge.info "`pwd`/src/test/*" -o coverage.info
				genhtml -o $@ -t "couverture de code des tests" coverage.info
				$(OPEN) $@/index.html

.PHONY		:	all clean fclean re test report