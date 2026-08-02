SELECT c.name AS Customers
FROM Customers AS c
LEFT JOIN Orders AS O
ON c.id = O.customerId
Where O.id IS NULL;