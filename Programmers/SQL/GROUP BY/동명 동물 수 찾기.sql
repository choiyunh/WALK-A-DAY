SELECT NAME, COUNT(NAME) as COUNT
FROM ANIMAL_INS
WHERE NAME is NOT NULL
GROUP BY NAME
HAVING COUNT(NAME) >= 2
ORDER BY NAME;