Assignment name  : mini_paint  
Expected files   : *.c *.h  
Allowed functions: fopen, fread, fscanf, fclose, write, malloc, calloc, realloc, free, memset, powf, sqrtf  
--------------------------------------------------------------------------------------  

Write a program that will read an "operation file" and print the result in the terminal  

Your program must take one argument, it will be the path to the "operation file"
If 0 or more than 1 argument is given to your program write "Error: argument" followed by a \n in STDOUT

$> ./mini_paint | cat -e
Error: argument$
$> ./mini_paint do not fear mathematics | cat -e
Error: argument$
$> 

If any problem occurs while you open and/or read the "operation file" write "Error: Operation file corrupted" followed by a \n in STDOUT

The "operation file" will contains lines with one operation per line  
If a line is incorrect an error occurs.  
If an error has occured your program must return 1  
If no error has occured it must return 0  
The last line can be with or without a \n  
The lines must be read in order and therefore operations must be executed in the same order  
There must be at least one space between each variable in a line  

WIDTH HEIGHT BACKGROUND_CHAR  
This line is always the first line of the file and it defines the zone where to draw. Your program should not display anything outside the draw zone. It must be there only once.  
- WIDTH: must be a int with 0 < WIDTH <= 300, the horizontal number of characters to use for the draw zone  
- HEIGHT: must be a int with 0 < HEIGHT <= 300, the vertical number of characters to use for the draw zone   
- BACKGROUND_CHAR: any empty space will be filled with BACKGROUND_CHAR  

c X Y RADIUS CHAR  
This operation will draw a empty circle, where only the border of the circle is drawn  
- c: the character c  
- X: a float, the horizontal position of the center of the circle  
- Y: a float, the vertical position of the center of the circle  
- RADIUS: a positive float but not 0, the radius of the circle  
- CHAR: the char use to draw the circle  
 
C X Y RADIUS  CHAR  
This operation will draw a filled circle  
- C: the character C  
- X: a float, the horizontal position of the center of the circle  
- Y: a float, the vertical position of the center of the circle  
- RADIUS: a positive float but not 0, the radius of the circle  
- CHAR: the char use to draw the circle  


The draw zone is divided in rectangles that can contain one character each (because we are in a terminal...), we will call them pixel
To make everything easier, we will use only the top left corner of the pixel to know if that pixel is in a circle or not
If the distance between the top left corner of a pixel and the center of a circle is lower or equal to the radius of the circle, the pixel is part of the circle  
but also:  
	A pixel with a top left corner with a distance bigger or equal than 1 from the border of a circle is not part of an empty circle   
	A pixel with a top left corner with a distance lower than 1 from the border of a circle is part of an empty circle.  

You should look at the image while reading the next few lines. It represents a terminal. We've set a draw zone of WIDTH 5 and HEIGHT 3.  
We've wrote different character to help you understand the following explanations.  
- If you want to draw the operation: C 1.5 1.5 1 0 @ (the pink circle)  
-- it means that the characters 'b', 'c', 'B', 'C' in the image will be replaced by '@'  

You should find our_mini_paint to help you test yours with some operation_file.example  

Hint:  
If you've got 2 points are defined as (Xa,Ya) and (Xb,Yb)  
You can get the distance between the two points with this formula: srqt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb))  