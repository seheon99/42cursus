CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror

all: Colleen Grace Sully

Colleen:
	@${CC} ${CFLAGS} C/Colleen/Colleen.c -o C/Colleen/Colleen
	@echo "C/Colleen/Colleen"

Grace:
	@${CC} ${CFLAGS} C/Grace/Grace.c -o C/Grace/Grace
	@echo "C/Grace/Grace"

Sully:
	@mkdir -p C/Sully/execute
	@${CC} ${CFLAGS} C/Sully/Sully.c -o C/Sully/execute/Sully
	@echo "C/Sully/execute/Sully"

clean:
	@find C/Colleen -type f -not \( -name 'Colleen.c' -or -name 'Colleen' \) -exec rm -vf {} \;
	@find C/Grace -type f -not \( -name 'Grace.c' -or -name 'Grace' \) -exec rm -vf {} \;
	@find C/Sully/execute -type f -not -name 'Sully' -exec rm -vf {} \;

fclean: clean
	@rm -vf C/Colleen/Colleen
	@rm -vf C/Grace/Grace
	@rm -rvf C/Sully/execute

re: fclean all
