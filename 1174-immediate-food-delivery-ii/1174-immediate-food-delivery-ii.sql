# Write your MySQL query statement below
SELECT Round(SUM(if (order_date = customer_pref_delivery_date , 1 , 0))*100/ COUNT(DISTINCT customer_id),2) as immediate_percentage
FROM delivery
WHERE (customer_id , order_date ) in (
    SELECT customer_id , min(order_date) as first_order
    from delivery
    group by customer_id
)
