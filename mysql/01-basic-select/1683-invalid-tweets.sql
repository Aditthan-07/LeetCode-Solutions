-- 1683. Invalid Tweets
-- Difficulty: Easy
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
