# Write your MySQL query statement below
-- count , distinct 
-- row id1 check for the num =1
-- row id2 = id1+1 check for the num = 1
-- row id3= id2+1 chek for the num =1 
-- return 1 
-- id.1

select  distinct log1.num as ConsecutiveNums
from logs log1,logs log2,logs log3
where  log1.id = log2.id +1
AND log2.id = log3.id+1 
AND log1.num = log2.num AND log2.num = log3.num ;





