#!/usr/bin/env lua

--0/1背包问题，动态规划解决

print("输入背包最大载重和物品数量:")
--m背包最大载重,n物品数量
local m,n = io.read("*number","*number") 

--[[
c:保存某个条件下取得的最大值
w:每个物品的重量
v:每个物品的价值
--]]
local c,w,v = {},{},{}
--初始化二维数组
for i=0,n do
  c[i] = {}
  for j=0,m do
    c[i][j] = 0
  end
end

for i=1,n do
  w[i],v[i] = io.read("*number","*number")
end

--动态规划得到最终结果
function knapsack(m,n)
  for i=1,n do
    for j=1,m do
      if w[i] <= j then 
        if v[i] + c[i-1][j-w[i]] > c[i-1][j] then
          c[i][j] = v[i] + c[i-1][j-w[i]]
        else
          c[i][j] = c[i-1][j]
        end
      else
        c[i][j] = c[i-1][j]
      end
    end
  end
  return c[n][m]
end

print("可载重物品的最大价值为:"..knapsack(m,n))