# Write your MySQL query statement below
select stock_name, sum(if(operation="Buy", -price, price)) as capital_gain_loss
from Stocks
group by stock_name;