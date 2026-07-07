# Write your MySQL query statement below
Select contest_id , round((count(distinct user_id )/
(
    select Count(*) from Users
) *100),2 ) as percentage
from register 
group by contest_id 
order by percentage desc, contest_id