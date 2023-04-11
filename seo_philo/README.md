# 🧔🏼 philosophers 🧔🏼
> process 
> > threading  
> > thread 만드는 법  
> > mutex

## 규칙✏️
1. 양손에 포크
2. 동그란 table
3. 철학자 죽으면 시스템 종료
4. 사망, 출력 10ms 이상 차이X
5. 최대한 죽지 X

## 순서✏️
먹고 -> 자고 -> 생각 -> 먹고 -> ...

## 인자✏️
./philo 철학자 죽는시간 먹는시간 자는시간 식사횟수[옵션]

## 출력✏️
[timestamp_in_ms] [철학자idx] has taken a fork  
[timestamp_in_ms] [철학자idx] is eating  
[timestamp_in_ms] [철학자idx] is sleeping  
[timestamp_in_ms] [철학자idx] is thinking  
[timestamp_in_ms] [철학자idx] died  

## Mandatory✏️
philosophers: thread  
forks       : mutex  

## 허용함수✏️
**printf, write, malloc, free**  
> 잘 알쥬~?  

**memset**  
> 메모리의 값을 원하는 만큼 특정 값으로 세팅해 줌.  
```c
#include <memory.h>
#include <string.h> //둘 중 하나 쓰기

void *memset(void *ptr, int value, size_t num);
```  
>> 반환값: 성공 ptr반환, 실패 NULL  

**usleep**  
> 마이크로초를 기반  
> 원하는 밀리초 * 1000 (1초 = 1000밀리초)  
```c
#include <unistd.h>

void usleep(unsigned long useconds);
```  

**gettimeofday**  
> 마이크로초 단위의 시간을 되돌려 줌.    
```c
#include <sys/time.h>
#include <unistd.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
``` 
> tv: 현재 시스템 시간을 저장하기 위한 구조체   
> tz: 타임존을 설정하기 위해 사용되는 구조체  
>> 반환값: 성공 0, 실패 -1  

### pthread란❓
pthread란 POSIX thread의 약자로 유닉스 계열 POSIX 시스템에서 스레드를 편하게
만들 수 있게 도와주는 API이다.  
* <pthread.h>에 저장되어 있음.  

**pthread_create**  
> thread를 생성하는 함수  
```c
#include <pthread.h>

int pthread_create(phtread_t *thread, const phtread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```  
1. pthread_t *thread : 쓰레드 식별자로서 생성된 스레드를 담을 쓰레드의 주소
2. const phread_attr_t *attr :  쓰레드 특성을 지정하기 위해 이용, 대개 NULL 처리
3. void *(*start_routine)(void *) : thread가 실행되었을 때 시작할 함수이다.
4. void *arg:  세 번째 매개변수인 함수의 인자로 들어갈 인자이다.  
* ex) pthread_create()를 한번 실행시키면 main이랑 새로 생성한 th로 총 2개가 동작.  
>> 반환값: 성공 thr_id, 실패 음수(?)  

**pthread_detach**  
> 특정 쓰레드를 해제  
> create를 통해 생성한 쓰레드는 종료 시점에 자동으로 자원 해제 안됨.  
>> 해제 시켜줘야 함  
>> pthread_join, pthread_detach로 해제 가능  
```c
# include <pthread.h>

int phtread_detach(phtread_t th);
``` 

**pthread_join**  
> 특정 쓰레드가 종료되기까지 기다린 후 실행
```c
#include <pthread.h>

int pthread_join(pthread_t th, void **thread_return);
```  
* 두 번째 매개변수는 해당 쓰레드 함수의 리턴값이 된다.  
* join된 쓰레드는 반납된 쓰레드로 간주하며, 모든 자원을 반납.  

-> detach, join의 차이
* detach : 만나는 즉시 쓰레드 종료  
	* 다른 쓰레드가 실행하는 함수가 실행될 수 있음.
* join : 쓰레드가 종료될 때까지 기다림  
	* 다른 쓰레드가 실행하는 함수가 이루어질 수 없음.

### mutex란❓
* mutex는 여러 개의 쓰레드를 공유하는 데이터를 보호하기 위해 사용되는 도구이다.  
* 한 번에 하나의 쓰레드만 실행가능하도록 만듦으로써 공유되는 자원을 공유한다.  
* 하나의 쓰레드만 접근할 수 있는 영역을 critical section이라고 함.  

**pthread_mutex_init**  
> mutex를 사용할 수 있게 함.  
```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```  
>> 반환값 : 성공 0, 실패 errno  
1. pthread_mutex_t *mutex : 초기화 할 mutex 객체
2. const pthread_mutexattr_t *attr : mutex의 특성을 맞추기 위해 설정(기본 NULL)  

```c
//정적으로 할당하고 싶을 때
pthread_mutex_t mutex = PTHREAD_MUTX_INITIALIZER;
```
<에러>  
* EINVAL : attr이 이상한 값이 들어옴
* ENOMEM : 다른 뮤텍스에서 사용한 쓰레드

**pthread_mutex_lock & pthread_mutex_unlock**  
> mutex 임계 구역 진입 시 그 코드 구역을 잠그고 여는 역할
```c
#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```  
>> 반환값 : 성공 0, 실패 errno  
<에러>  
* pthread_mutex_lock  
	* 에러 시 에러코드  
		* EINVAL : mutex 유효하지 않음  
		* EDEADLK : 데드락 조건이 발생  

* pthread_mutex_unlock  
	* 에러 시 에러코드  
		* EINVAL : mutex 유효하지 않음  
		* EPERM : 현재 쓰레드가 잠겨져있지 않음  

**pthread_mutex_destroy**  
> mutex 객체 삭제. 
```c
#include <pthread.h>

int pthread_mutex_destroy(pthread_mutex_t *mutex);
```
>> 반환값 : 성공 0, 실패 errno  
