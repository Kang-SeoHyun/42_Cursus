# 📚Libft📚

man을 활용하여 나만의 라이브러리 제작하기.

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
> 알파벳인지 아닌지 확인 해줌  

### ft_isdigit
> 숫자인지 아닌지

### ft_isalnum
> 알파벳, 숫자 인지 아닌지

### ft_isascii
> 아스키인지

### ft_isprint
> 프린트 가능한 숫자인지

### ft_strlen
> 문자열 길이

### ft_toupper
> 대문자로 변환

### ft_tolower
> 소문자로 변환

### ft_strchr
> char찾아서 거기서부터 출력

### ft_strrchr
> 뒤에서 char찾아서 출력

### ft_memcmp
> s1, s2를 n까지 비교함

### ft_strnstr
> 문자열에서 len길이만큼안에서 needle찾기

### ft_memset
> 메모리를 len 사이즈만큼 c로 초기화함.

### ft_bzero
> n이 0이면 아무것도 안함. 메모리 s의 n까지 0으로 초기화하기

### ft_strncmp
> n개만큼 문자열 두개 비교

### ft_memchr
> 메모리 영역에서 n까지 확인해서 문자가 발견된 곳의 포인터 반환

### ft_memcpy
> 메모리 영역 안 겹칠때 복사하기

### ft_memmove
> 메모리 영역 겹칠때 복사하기

### ft_strlcpy
> src에서 dst로 size만큼 복사하기

### ft_strlcat
> dst뒤에 src를 size만큼 이어붙임
> > dstsize = dst_len + src_len + 1(NULL);

------------------------------------------
### ft_atoi
> 문자열을 int형으로 대신 부호이상하면 안됨

> 우리는 int가 32 bit 즉 4 바이트라고 배웠지만, 실제로는 시스템마다 그 크기가 각기 달라 size_t라는 고정된 약속을 쓰는 것.

## Chapter 3.2
### 
