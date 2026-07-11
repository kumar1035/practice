# Write your MySQL query statement below
select E1.employee_id , E1.name , count(E2.employee_id) as reports_count, Round(AVG(E2.age)) AS average_age
from employees E1 inner join employees E2
on E1.employee_id = E2.reports_to
group by E1.employee_id , E1.name

order by employee_id