# Write your MySQL query statement below
SELECT product_name , s.year , s.price 
FROM  sales as s
LEFT JOIN product as p
ON p.product_id = s.product_id;