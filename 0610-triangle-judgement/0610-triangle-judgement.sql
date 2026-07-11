# Write your MySQL query statement below
# a+ b > c
# b + c >a 
# a+c >b
select * , if (x+y > z and y+z>x and x+z>y, 'Yes' , 'No')  as triangle
from triangle 

