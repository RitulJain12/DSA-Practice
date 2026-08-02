SELECT  id,movie,description,rating
FROM Cinema
WHERE id % 2 = 1 AND
description !='boring'
ORDER By rating DESC; 
