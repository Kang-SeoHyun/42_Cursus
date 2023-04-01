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
**memset**  
``c
int main(){}
``  
**printf, write**  
  
**malloc, free**  
  
**usleep**  
  
**gettimeofday**  
  
**pthread_create**  
  
**pthread_detach**  
  
**pthread_join**  
  
**pthread_mutex_init**  
  
**pthread_mutex_destroy**  
  
**pthread_mutex_lock**  
  
**pthread_mutex_unlock**  
  
