# ๐Libft๐

man์ ํ์ฉํ์ฌ ๋๋ง์ ๋ผ์ด๋ธ๋ฌ๋ฆฌ ์ ์ํ๊ธฐ.

## Contents
* [ft_isalpha](#ft_isalpha)
* [ft_isdigit](#ft_isdigit)
* [ft_isalnum](#ft_isalnum)
* [ft_isascii](#ft_isascii)
* [ft_isprint](#ft_isprint)
* [ft_strlen](#ft_strlen)
* [ft_toupper](#ft_toupper)
* [ft_tolower](#ft_tolower)
* [ft_strchr](#ft_strchr)
* [ft_strrchr](#ft_strrchr)
* [ft_strnstr](#ft_strnstr)
* [ft_strncmp](#ft_strncmp)
* [ft_strlcpy](#ft_strlcpy)
* [ft_strlcat](#ft_strlcat)
* [ft_atoi](#ft_atoi)
* [ft_memcmp](#ft_memcmp)

## Chapter 3.1

### ft_isalpha
> ์ํ๋ฒณ์ธ์ง ์๋์ง ํ์ธ ํด์ค  

### ft_isdigit
> ์ซ์์ธ์ง ์๋์ง

### ft_isalnum
> ์ํ๋ฒณ, ์ซ์ ์ธ์ง ์๋์ง

### ft_isascii
> ์์คํค์ธ์ง

### ft_isprint
> ํ๋ฆฐํธ ๊ฐ๋ฅํ ์ซ์์ธ์ง

### ft_strlen
> ๋ฌธ์์ด ๊ธธ์ด

### ft_toupper
> ๋๋ฌธ์๋ก ๋ณํ

### ft_tolower
> ์๋ฌธ์๋ก ๋ณํ

### ft_strchr
> char์ฐพ์์ ๊ฑฐ๊ธฐ์๋ถํฐ ์ถ๋ ฅ

### ft_strrchr
> ๋ค์์ char์ฐพ์์ ์ถ๋ ฅ

### ft_memcmp
> s1, s2๋ฅผ n๊น์ง ๋น๊ตํจ

### ft_strnstr
> ๋ฌธ์์ด์์ len๊ธธ์ด๋งํผ์์์ needle์ฐพ๊ธฐ

### ft_memset
> ๋ฉ๋ชจ๋ฆฌ๋ฅผ len ์ฌ์ด์ฆ๋งํผ c๋ก ์ด๊ธฐํํจ.

### ft_bzero
> n์ด 0์ด๋ฉด ์๋ฌด๊ฒ๋ ์ํจ. ๋ฉ๋ชจ๋ฆฌ s์ n๊น์ง 0์ผ๋ก ์ด๊ธฐํํ๊ธฐ

### ft_strncmp
> n๊ฐ๋งํผ ๋ฌธ์์ด ๋๊ฐ ๋น๊ต

### ft_memchr
> ๋ฉ๋ชจ๋ฆฌ ์์ญ์์ n๊น์ง ํ์ธํด์ ๋ฌธ์๊ฐ ๋ฐ๊ฒฌ๋ ๊ณณ์ ํฌ์ธํฐ ๋ฐํ

### ft_memcpy
> ๋ฉ๋ชจ๋ฆฌ ์์ญ ์ ๊ฒน์น ๋ ๋ณต์ฌํ๊ธฐ

### ft_memmove
> ๋ฉ๋ชจ๋ฆฌ ์์ญ ๊ฒน์น ๋ ๋ณต์ฌํ๊ธฐ

### ft_strlcpy
> src์์ dst๋ก size๋งํผ ๋ณต์ฌํ๊ธฐ

### ft_strlcat
> dst๋ค์ src๋ฅผ size๋งํผ ์ด์ด๋ถ์
> > dstsize = dst_len + src_len + 1(NULL);

------------------------------------------
### ft_atoi
> ๋ฌธ์์ด์ intํ์ผ๋ก ๋์  ๋ถํธ์ด์ํ๋ฉด ์๋จ

> ์ฐ๋ฆฌ๋ int๊ฐ 32 bit ์ฆ 4 ๋ฐ์ดํธ๋ผ๊ณ  ๋ฐฐ์ ์ง๋ง, ์ค์ ๋ก๋ ์์คํ๋ง๋ค ๊ทธ ํฌ๊ธฐ๊ฐ ๊ฐ๊ธฐ ๋ฌ๋ผ size_t๋ผ๋ ๊ณ ์ ๋ ์ฝ์์ ์ฐ๋ ๊ฒ.

## Chapter 3.2
### 
