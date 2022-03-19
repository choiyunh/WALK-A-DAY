select c.first_name 이름, c.last_name 성, SUM(r.price * (datediff(re.date_out,re.date_in) +1)) 누적숙박비
from customers
left join reservations re
on c.customer_id = re.customer_id
left join room r
on re.room_id = r.room_id
where r.room_no is not null
group by c.first_name, c.last_name
order by c.first_name, c.last_name;
