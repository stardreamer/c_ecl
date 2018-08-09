#Makefile
SRCDIR := src

OBJDIR := obj

BINDIR := bin

CC := gcc
FLAGS := -Wall -pedantic -ffreestanding -Wstrict-overflow=4 -Wformat-security -Wextra -Wfloat-equal -Wundef -Wshadow -O2  -c -std=c99 -MD
BINDIR_REL := $(addprefix ../, $(BINDIR))

SRCDIR_REL := $(addprefix ../, $(SRCDIR))

SRCFILES := $(wildcard $(addsuffix /*.c, $(SRCDIR_REL)))

OBJDIR_REL := $(addprefix ../, $(OBJDIR))

OBJFILES := $(patsubst $(SRCDIR_REL)/%.c,$(OBJDIR_REL)/%.o,$(wildcard $(SRCFILES)))

default:
	@echo -e "\e[0;33mmake c_ecl\e[0;32m - compile c_ecl"
	@echo -e "\e[0;33mmake clean\e[0;32m - clean obj files"
	@echo -e "\e[0;33mmake delete\e[0;32m - remove c_ecl" 
	
c_ecl:$(BINDIR_REL)/c_ecl $(OBJFILES)  
	@echo -e "The program was successfully compiled \n"
	

$(BINDIR_REL)/c_ecl: $(OBJFILES) 
	$(CC) -Wall $^ -o $@ -lm

	

$(OBJDIR_REL)/%.o: $(SRCDIR_REL)/%.c
	$(CC) $<  $(FLAGS) $(addprefix -I, $(SRCDIR_REL)) -o $@ -pipe -lm
	
include  $(wildcard $(OBJDIR_REL)/*.d)
clean:
	@rm -f $(OBJDIR_REL)/*.o $(OBJDIR_REL)/*.d
	@rm -f $(OBJDIR_REL_S)/*.o $(OBJDIR_REL_S)/*.d
	@rm -f $(OBJDIR_REL_D)/*.o $(OBJDIR_REL_D)/*.d
	@rm -f $(BINDIR_REL)/*
	@echo "Cleaned"
delete:
	@echo "Program was removed!"
	@rm -f $(BINDIR_REL)
.PHONY: clean delete c_ecl
