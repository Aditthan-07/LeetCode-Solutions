-- 185. Department Top Three Salaries
-- Difficulty: Hard
SELECT d.name AS Department, t.name AS Employee, t.salary AS Salary
FROM (
    SELECT name, salary, departmentId,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS `rank`
    FROM Employee
) t
JOIN Department d ON t.departmentId = d.id
WHERE t.rank <= 3;
