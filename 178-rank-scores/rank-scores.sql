SELECT score , rnk AS `rank` 
FROM (
   Select score , DENSE_RANK() OVER (ORder by score desc) as rnk
    from Scores
) t;