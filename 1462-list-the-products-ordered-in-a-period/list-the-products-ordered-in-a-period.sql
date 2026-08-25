select product_name ,unit 
from Products AS P
 LEFT JOIN 
 (
 SELECT product_id, SUM(unit) AS unit
FROM Orders
WHERE YEAR(order_date) = 2020 
  AND MONTH(order_date) = 2
GROUP BY product_id
HAVING SUM(unit) >= 100
) AS t on p.product_id=t.product_id
WHERE unit >=100;