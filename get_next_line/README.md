# 🧼 GET NEXT LINE 🧼

파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수 만들기.   
> 바구니와 나누기와 함께하는 퐁스코 근닐리..

## **fd**
* file discrepter  
	open(), read(), close()

### 🌧 **open 함수**
* 헤더파일: <fcntl.h>  
```c
// 형식
int open(const char* pathname, int flags[, mode_t mode]); 
// 사용법
fd = open("filename", 접근권한);  
```
return값 = 성공은 양의 정수(fd), 실패는 -1

### 🌧 **read 함수**  
* 헤더파일: <unistd.h>  
```c
// 형식
ssize_t read(int fd, void* buf, size_t nbytes); 형식임.  
//사용법
read(파일식별자(fd), 저장할 장소, 읽을 크기);  
```
return값 = 성공은 읽은 바이트 수, 실패는 -1

### 🌧 **close 함수** 
* 헤더파일: <fcntl.h>   
int close(int fd);매개변수fd : 닫으려하는 파일의 파일식별자반환값- 성공 : 0- 실패 : -1


## **OPEN_MAX**

## **malloc, free**

## **logic**

```plaintxt
example.txt
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