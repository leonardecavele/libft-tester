# HOW TO USE : # 'make' to test all functions at once
# 'make {function.ev}' to test a single function
# 'make libft.a' to rebuild the libft.a
# 'make clean' to delete .ev files
# 'make fclean' to delete libft.a and .ev files
# 'make rb' to test bonus relink
# 'make r' to test mandatory relink

.PHONY: .FORCE all clean r rb libft.a

TESTS = $(wildcard $(TESTS_DIR)*.c)
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -L ../ -lft
TESTS_DIR = tests/
LIB = ../libft.a
wait := 0

# 'make' to test all functions at once
all: $(BINARIES)

# 'make {function.ev}' to test a single function
%.ev: $(TESTS_DIR)%.c $(LIB) .FORCE
	@wait=$(wait) ; if [ "$$wait" -eq 1 ]; then printf \
	"\033[0;31mPRESS ANY KEY\033[0m" ; read -n 1 -s ; echo ; \
	fi ; $(eval wait:=1)
	@$(CC) $(CFLAGS) $< $(LIB) -o $@
	@printf "\033[0;31m|%s|\033[0m\n" $(subst .ev,.c,$@)
	@./$@

# 'make libft.a' to rebuild the libft.a
libft.a:
	@printf "\033[0;31mBUILDING 'libft.a'\033[0m"
	@$(MAKE) fclean -C ../ --quiet
	@make $(LIB) --no-print-directory
	@printf "\r\033[2K\r\033[0;31mDONE BUILDING 'libft.a'\033[0m\n"

# 'make clean' to delete .ev files
clean:
	@rm -f *.ev

# 'make fclean' to delete libft.a and .ev files
fclean: clean
	@$(MAKE) fclean -C ../ --quiet	

# 'make rb' to test bonus relink
rb:
	@$(MAKE) BONUS_FLAG="bonus $(BONUS_FLAG)" r BONUS=1 --no-print-directory

# 'make r' to test mandatory relink
r:
	@printf "\033[1;31mDouble make:\033[1;30m\n"
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory 
	@printf "\033[1;31mC files relink:\033[0;30m\n"
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c; \
	else touch ../ft_strlen.c; fi
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@printf "\033[1;31mHeaders relink:\033[0;30m\n"
	@touch ../libft.h
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 

$(LIB):
	@$(MAKE)  -C ../ > /dev/null 2>&1
	@$(MAKE) bonus -C ../ > /dev/null 2>&1 
