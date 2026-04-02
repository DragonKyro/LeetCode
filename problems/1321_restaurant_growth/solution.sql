SELECT visited_on,
  (
    SELECT SUM(amount)
    FROM Customer c2
    WHERE c2.visited_on BETWEEN DATE_SUB(c1.visited_on, INTERVAL 6 DAY) AND c1.visited_on
  ) AS amount,
  ROUND(
    (
      SELECT SUM(amount)
      FROM Customer c2
      WHERE c2.visited_on BETWEEN DATE_SUB(c1.visited_on, INTERVAL 6 DAY) AND c1.visited_on
    ) / 7, 2
  ) AS average_amount
FROM (
  SELECT DISTINCT visited_on
  FROM Customer
) c1
WHERE visited_on >= (
  SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
  FROM Customer
)
ORDER BY visited_on;
