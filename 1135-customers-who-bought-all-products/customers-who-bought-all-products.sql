SELECT customer_id
from Customer
group by customer_id
Having Count(distinct product_key) = (select count(*) from Product);
