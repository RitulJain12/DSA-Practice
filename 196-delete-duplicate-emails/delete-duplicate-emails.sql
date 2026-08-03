DELETE p1 from Person AS p1
INNER JOIN Person AS p2
ON p1.email = p2.email
Where p1.id > p2.id;