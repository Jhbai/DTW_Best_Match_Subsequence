# Makefile for compiling main.c and dtw_utils.c

CC = gcc
CFLAGS = -Wall -g

# 目標檔案
OBJS = main.o DTW_model.o

# 最終可執行檔
TARGET = main

all: $(TARGET)

# 編譯目標，將所有 .o 檔案連結為可執行檔案
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# 編譯每一個 .c 檔案成為 .o 檔案
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o -lm

DTW_model.o: DTW_model.c
	$(CC) $(CFLAGS) -c DTW_model.c -o DTW_model.o -lm

# 清理所有編譯過的檔案
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean