-- 570. Managers with at Least 5 Direct Reports
-- Difficulty: Medium
SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(id) >= 5
);
