# Write your MySQL query statement below
SELECT Round(Count(DISTINCT player_id)/(SELECT COUNT(DISTINCT player_id ) from activity),2) as fraction
from activity
where (player_id , Date_sub(event_date , INTERVAL 1 DAY) )IN (
select player_id , min(event_date) as first_login
from Activity
group by player_id
)
