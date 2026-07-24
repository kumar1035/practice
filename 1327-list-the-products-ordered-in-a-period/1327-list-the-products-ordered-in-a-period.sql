# Write your MySQL query statement below
select p.product_name as product_name,sum(o.unit) as unit from Orders o
left join Products p
on o.product_id=p.product_id
where substring(o.order_date,6,2)=02
and year(o.order_date)=2020 
group by p.product_name
having unit>=100;