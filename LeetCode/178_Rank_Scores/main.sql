# Write your MySQL query statement below
SELECT SCORE, DENSE_RANK() OVER (ORDER BY SCORE DESC) 'RANK' FROM SCORES;