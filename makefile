#Makefile for "check_a_numbers_in_array" C++ application
#Created by r4m0nl1m4 14/03/2020

#executável
PROG = check_a_numbers_in_array						
#compilador
CC = g++
#diretorio
DIR = pwd
#diretivas de compilação
CPPFLAGS = -O0        \
           -g         \
           -Wall      \
           -ansi      \
           -pedantic  \
           -std=c++11 \
           -DIR      
#diretivas para o ligador (linker)
LDFLAGS = -DIR
#arquivos objetos definidos como pré-requisito
OBJS = check_a_numbers_in_array.o			

#regra de construção do executável
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)			

#regra de construção dos arquivos objetos
check_a_numbers_in_array.o:
	$(CC) $(CPPFLAGS) -c check_a_numbers_in_array.cpp

#regra de limpeza dos arquivos
clean:
	rm -rf core $(PROG) $(OBJS)