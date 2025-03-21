SELECT * FROM Cinema
WHERE MOD(ID,2) = 1 
AND description != 'boring'
ORDER BY rating DESC
