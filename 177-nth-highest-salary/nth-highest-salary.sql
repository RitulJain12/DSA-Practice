CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      
      Select salary 
      from (
            Select salary ,DENSE_RANK() OVER (Order by salary DESC) As rnk
            from Employee
      ) t
      Where rnk=N LIMIT 1

  );
END