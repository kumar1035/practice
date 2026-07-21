# Write your MySQL query statement below
WITH CTE AS (
select salary, d.name AS Department ,e.name AS Employee , DENSE_RANK() over (partition by departmentid order by salary desc) as department_rank  from Employee  e 
inner join department d on d.id = e.departmentid
)
SELECT Department,Employee,salary FROM CTE WHERE department_rank<=3 