# Write your MySQL query statement below
select e.name
from employee e
join employee ee on e.id = ee.managerId
group by e.id,e.name
having count(*)>=5;