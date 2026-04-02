SELECT id, num AS `friend_requests_ii: who has the most friends`
FROM (
  SELECT id, COUNT(*) AS num
  FROM (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
  ) t
  GROUP BY id
) t2
ORDER BY num DESC
LIMIT 1;
