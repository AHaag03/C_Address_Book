cmake_minimum_required(VERSION 3.24)
project(Address_Book C)

set(CMAKE_C_STANDARD 17)

add_executable(Address_Book src/main.c src/address_book/address_book.c include/address_book.h src/address_book_cli/address_book_cli.c include/address_book_cli.h src/address_book_io/address_book_io.c include/address_book_io.h)
