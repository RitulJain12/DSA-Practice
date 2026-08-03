SELECT email AS Email
From Person 
Group BY 
email 
Having COUNT(email)>1;
