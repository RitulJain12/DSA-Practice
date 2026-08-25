SELECT DISTINCT num AS ConsecutiveNums  
FROM (
   select *,
    LEAD(num,1) OVER(ORDER BY id) AS next1,
    LEAD(num,2) OVER(ORDER BY id) AS next2
 FROM
LOGS

) AS temp
Where
num = next1 AND next1 = next2;