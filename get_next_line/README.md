# 🧼 GET NEXT LINE 🧼

파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수 만들기.   
> 바구니와 나누기와 함께하는 퐁스코 근닐리..

## 🍒 **fd** 🍒
* file descriptor, 파일 식별자    

파일 식별자는 파일을 열었을 때, 그 파일에 번호를 부여하는 것 이다. 파일명이 아니라 부여된 숫자 그 파일 식별자 값을 가지고 쉽게 파일에 접근 할 수 있다.  
> 파일 식별자 0 ~ 2에는 자동으로 부여되는 것이 있다.  
	fd = 0 : 파일 입력 (키보드)  
	fd = 1 : 파일 출력 (모니터)   
	fd = 2 : 파일 오류 (모니터)   

## 🍒 **파일 입출력** 🍒
* open(), read(), close()
### 🌧 **open 함수**
* 헤더파일: <fcntl.h>  
```c
// 형식
int open(const char* pathname, int flags[, mode_t mode]); 
// 사용법
open("filename", 접근권한);  
// ex
fd = open("a.txt", O_RDONLY);
```
* 접근권한  
<img width="622" src="https://user-images.githubusercontent.com/77817094/190886820-87c7a6db-4483-4ec0-8425-dfda6040ce61.png">  

return값 = 성공은 양의 정수(fd), 실패는 -1

### 🌧 **read 함수**  
* 헤더파일: <unistd.h>  
```c
// 형식
ssize_t read(int fd, void* buf, size_t nbytes);  
//사용법
read(파일식별자, 저장할 장소, 읽을 크기);  
// ex
reres = read(fd, baguni, BUFFER_SIZE);
```
return값 = 성공은 읽은 바이트 수, 실패는 -1

### 🌧 **close 함수** 
* 헤더파일: <fcntl.h>   
``` c
// 형식
int close(int fd);
// 사용법
close(닫으려는 파일식별자)
// ex
close(fd);
```
return값 = 성공은 0, 실패는 -1

## 🍒 **malloc, free** 🍒
* 댕글링 포인트  
> 자기가 가리키는 곳의 값이 free가 되어서 댕청이가🤪 되어버린 포인터

### 🌧 **malloc함수**
* 헤더파일: <stdlib.h>  

이 함수는 지정된 크기의 공간을 확보하고 void 형 포인터를 돌려준다.  
```c
void* malloc( size_t size );
```

### 🌧 **free함수**
* 헤더파일: <stdlib.h>  

동적으로 할당한 메모리 영역은 해제하는 형태로 반환해야 한다. 그렇지 않으면 다른 프로그램과 시스템을 정상적으로 운영하는데 필요한 메모리가 손실될 수 있다. 단기간만 실행하는 응용 프로그램의 소량의 메모리 누수라면 문제가 없지만, 장기간 실행하는 서버 등의 프로그램 메모리 누수가 있는 경우 치명적이다. 하지만 시스템이 자동으로 경고 해주지 않기때문에 할당한 메모리를 free() 함수를 사용하여 명시적으로 해제해야 함.
```c
void free( void * memblock );
```


스텍 데이터 코드 힙

## 🍒 **logic** 🍒
만약 txt = 123\n456789\nabcd\nefg\0 이라고 한다면 
```plaintxt
123  
456789  
abcd  
efg\0  

☝🏻 
backup : '\0'  
baguni : 123  
	\n45  
backup : 123\n45 -> 바구니 푸기의 return값  
result : 123\n   -> 나누기에서 포인터 이용해서 바꿈 -> gnl의 return값  
backup : 45	   -> 나누기의 return값  
✌🏻  
backup : 45
baguni : 678  
	9\na  
backup : 456789\na  
return : 456789\n  
backup : a  
🤟🏻   
backup : a
baguni : bcd  
	\nef  
backup : abcd\nef  
result : abcd\n  
backup : ef  
🖖🏻 
backup : ef
baguni : g\0    
backup : efg\0  
result : efg\0  
backup : '\0'
```

## 🍒 **bonus part** 🍒  
* 여러개의 fd가 들어왔을 때, 처리하기  

연결리스트로 하는 방법 배열로 하는 방법이 있는데 배열을 선택함으로 <u>open_max값</u>을 헤더파일에 정의하였다.  

### 🌧 **logic**
```c
char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup[OPEN_MAX];

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = (char *)malloc(sizeof(char) * 1);
		if (!backup[fd])
			return (NULL);
		*backup[fd] = '\0';
	}
	backup[fd] = ft_baguni_pugi(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	backup[fd] = ft_na_nugi(&result, backup[fd]);
	return (result);
}
```

### 🌧 **OPEN_MAX** 🌧
* 이용할 수 있는 스레드 갯수  

ulimit의 openfile 수보다 많은 수의 소켓통신을 하면 장애 발생.
```bash
# 하드리미트 확인
$ ulimit -Hn
# 소프트리미트 확인
$ ulimit -Sn
# 전반적인 사이즈들 확인 가능
$ ulimit -a -H
$ ulimit -a -S
# open files 갯수 변경가능
$ ulimit -n 숫자
```
ulimit 명령어를 이용하여 확인가능  

