# π§Ό GET NEXT LINE π§Ό

νμΌ λμ€ν¬λ¦½ν°λ‘λΆν° μ½νμ§, κ°νμΌλ‘ λλλ ν μ€μ λ°ννλ ν¨μ λ§λ€κΈ°.   
> λ°κ΅¬λμ λλκΈ°μ ν¨κ»νλ νμ€μ½ κ·Όλλ¦¬..

## π **fd** π
* file descriptor, νμΌ μλ³μ    

νμΌ μλ³μλ νμΌμ μ΄μμ λ, κ·Έ νμΌμ λ²νΈλ₯Ό λΆμ¬νλ κ² μ΄λ€. νμΌλͺμ΄ μλλΌ λΆμ¬λ μ«μ κ·Έ νμΌ μλ³μ κ°μ κ°μ§κ³  μ½κ² νμΌμ μ κ·Ό ν  μ μλ€.  
> νμΌ μλ³μ 0 ~ 2μλ μλμΌλ‘ λΆμ¬λλ κ²μ΄ μλ€.  
	fd = 0 : νμΌ μλ ₯ (ν€λ³΄λ)  
	fd = 1 : νμΌ μΆλ ₯ (λͺ¨λν°)   
	fd = 2 : νμΌ μ€λ₯ (λͺ¨λν°)   

## π **νμΌ μμΆλ ₯** π
* open(), read(), close()
### π§ **open ν¨μ**
* ν€λνμΌ: <fcntl.h>  
```c
// νμ
int open(const char* pathname, int flags[, mode_t mode]); 
// μ¬μ©λ²
open("filename", μ κ·ΌκΆν);  
// ex
fd = open("a.txt", O_RDONLY);
```
* μ κ·ΌκΆν  
<img width="622" src="https://user-images.githubusercontent.com/77817094/190886820-87c7a6db-4483-4ec0-8425-dfda6040ce61.png">  

returnκ° = μ±κ³΅μ μμ μ μ(fd), μ€ν¨λ -1

### π§ **read ν¨μ**  
* ν€λνμΌ: <unistd.h>  
```c
// νμ
ssize_t read(intΒ fd, void*Β buf, size_tΒ nbytes);  
//μ¬μ©λ²
read(νμΌμλ³μ, μ μ₯ν  μ₯μ, μ½μ ν¬κΈ°);  
// ex
reres = read(fd, baguni, BUFFER_SIZE);
```
returnκ° = μ±κ³΅μ μ½μ λ°μ΄νΈ μ, μ€ν¨λ -1

### π§ **closeΒ ν¨μ** 
* ν€λνμΌ: <fcntl.h>   
``` c
// νμ
int close(int fd);
// μ¬μ©λ²
close(λ«μΌλ €λ νμΌμλ³μ)
// ex
close(fd);
```
returnκ° = μ±κ³΅μ 0, μ€ν¨λ -1

## π **malloc, free** π
* λκΈλ§ ν¬μΈνΈ  
> μκΈ°κ° κ°λ¦¬ν€λ κ³³μ κ°μ΄ freeκ° λμ΄μ λμ²­μ΄κ°π€ͺ λμ΄λ²λ¦° ν¬μΈν°

### π§ **mallocν¨μ**
* ν€λνμΌ: <stdlib.h>  

μ΄ ν¨μλ μ§μ λ ν¬κΈ°μ κ³΅κ°μ νλ³΄νκ³  void ν ν¬μΈν°λ₯Ό λλ €μ€λ€.  
```c
void* malloc( size_t size );
```

### π§ **freeν¨μ**
* ν€λνμΌ: <stdlib.h>  

λμ μΌλ‘ ν λΉν λ©λͺ¨λ¦¬ μμ­μ ν΄μ νλ ννλ‘ λ°νν΄μΌ νλ€. κ·Έλ μ§ μμΌλ©΄ λ€λ₯Έ νλ‘κ·Έλ¨κ³Ό μμ€νμ μ μμ μΌλ‘ μ΄μνλλ° νμν λ©λͺ¨λ¦¬κ° μμ€λ  μ μλ€. λ¨κΈ°κ°λ§ μ€ννλ μμ© νλ‘κ·Έλ¨μ μλμ λ©λͺ¨λ¦¬ λμλΌλ©΄ λ¬Έμ κ° μμ§λ§, μ₯κΈ°κ° μ€ννλ μλ² λ±μ νλ‘κ·Έλ¨ λ©λͺ¨λ¦¬ λμκ° μλ κ²½μ° μΉλͺμ μ΄λ€. νμ§λ§ μμ€νμ΄ μλμΌλ‘ κ²½κ³  ν΄μ£Όμ§ μκΈ°λλ¬Έμ ν λΉν λ©λͺ¨λ¦¬λ₯Ό free() ν¨μλ₯Ό μ¬μ©νμ¬ λͺμμ μΌλ‘ ν΄μ ν΄μΌ ν¨.
```c
void free( void * memblock );
```


μ€ν λ°μ΄ν° μ½λ ν

## π **logic** π
λ§μ½ txt = 123\n456789\nabcd\nefg\0 μ΄λΌκ³  νλ€λ©΄ 
```plaintxt
123  
456789  
abcd  
efg\0  

βπ» 
backup : '\0'  
baguni : 123  
	\n45  
backup : 123\n45 -> λ°κ΅¬λ νΈκΈ°μ returnκ°  
result : 123\n   -> λλκΈ°μμ ν¬μΈν° μ΄μ©ν΄μ λ°κΏ -> gnlμ returnκ°  
backup : 45	   -> λλκΈ°μ returnκ°  
βπ»  
backup : 45
baguni : 678  
	9\na  
backup : 456789\na  
return : 456789\n  
backup : a  
π€π»   
backup : a
baguni : bcd  
	\nef  
backup : abcd\nef  
result : abcd\n  
backup : ef  
ππ» 
backup : ef
baguni : g\0    
backup : efg\0  
result : efg\0  
backup : '\0'
```

## π **bonus part** π  
* μ¬λ¬κ°μ fdκ° λ€μ΄μμ λ, μ²λ¦¬νκΈ°  

μ°κ²°λ¦¬μ€νΈλ‘ νλ λ°©λ² λ°°μ΄λ‘ νλ λ°©λ²μ΄ μλλ° λ°°μ΄μ μ νν¨μΌλ‘ <u>open_maxκ°</u>μ ν€λνμΌμ μ μνμλ€.  

### π§ **logic**
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

### π§ **OPEN_MAX** π§
* μ΄μ©ν  μ μλ μ€λ λ κ°―μ  

ulimitμ openfile μλ³΄λ€ λ§μ μμ μμΌν΅μ μ νλ©΄ μ₯μ  λ°μ.
```bash
# νλλ¦¬λ―ΈνΈ νμΈ
$ ulimit -Hn
# μννΈλ¦¬λ―ΈνΈ νμΈ
$ ulimit -Sn
# μ λ°μ μΈ μ¬μ΄μ¦λ€ νμΈ κ°λ₯
$ ulimit -a -H
$ ulimit -a -S
# open files κ°―μ λ³κ²½κ°λ₯
$ ulimit -n μ«μ
```
ulimit λͺλ Ήμ΄λ₯Ό μ΄μ©νμ¬ νμΈκ°λ₯  

