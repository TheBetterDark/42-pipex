# 42-Libft

## Description

This is the first project as student in the 42 curriculum. The goal of this project is to create a library of functions that will be used in future projects. The purpose of this project is to understand how to create a library, how to use a library, and understand how the standard C library functions work.

**NOTE**: This library is modified to include some additional functions that are not part of the original project. Please refer to the branch [vogsphere](https://github.com/TheBetterDark/42-libft/tree/vogsphere) for the original project.

## Usage

To use this library, you need to compile the library using the Makefile. The Makefile will compile the library and create a static library called libft.a.

```
git clone https://github.com/TheBetterDark/42-libft.git
cd 42-libft
make
```

## Makefile

The Makefile has the following rules:

- all: This rule will compile the library.
- clean: This rule will remove all object files.
- fclean: This rule will remove all object files and the library.
- re: This rule will remove all object files, the library, and recompile the library.

## Functions

The library includes:

- Check: `ft_isalnum`, `ft_isalpha`, `ft_isascii`, `ft_isdigit`, `ft_isprint`
- Conversion: `ft_atoi`, `ft_itoa`, `ft_strupr`, `ft_tobase`, `ft_tolower`, `ft_toupper`,
- IO: `ft_printf`, `ft_putchar_fd`, `ft_putendl_fd`, `ft_putnbr_fd`, `ft_putstr_fd`, `ft_putunbr_fd.c`
- List: `ft_lstadd_back`, `ft_lstadd_front`, `ft_lstclear`, `ft_lstdelone`, `ft_lstiter`, `ft_lstlast`, `ft_lstmap`, `ft_lstnew`, `ft_lstsize`
- Memory: `ft_bzero`, `ft_calloc`, `ft_memchr`, `ft_memcmp`, `ft_memcpy`, `ft_memmove`, `ft_memset`, `ft_realloc`
- String: `ft_split`, `ft_strchr`, `ft_strdup`, `ft_strjoin`, `ft_strlcat`, `ft_strlcpy`, `ft_strlen`, `ft_strmapi`, `ft_strncmp`, `ft_strnstr`, `ft_strrchr`, `ft_strtrim`, `ft_substr`
