SELECT c1.name AS Department ,
c2.name AS Employee,
c2.salary AS Salary
FROM  Employee AS c2
INNER JOIN
Department AS c1
ON c2.departmentId = c1.id
INNER JOIN
(
    SELECT departmentId ,MAX(salary) AS mxsl 
    from Employee
    group by departmentId 
) t
ON c2.salary = t.mxsl AND c2.departmentId = t.departmentID ;