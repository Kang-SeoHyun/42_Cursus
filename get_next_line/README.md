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

## 🍒 **OPEN_MAX** 🍒

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