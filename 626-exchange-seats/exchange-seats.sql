SELECT id,
CASE
   WHEN id%2=1 
   THEN LEAD(student,1,student) OVER (order by id)
   ELSE LAG(student) OVER (ORDER BY id)
 END AS student
 from Seat;
