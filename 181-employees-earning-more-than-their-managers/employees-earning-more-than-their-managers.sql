SELECT e.name AS Employee FROM
Employee AS e
INNER JOIN Employee As e2
ON e.managerId = e2.Id
Where e.salary > e2.salary ;