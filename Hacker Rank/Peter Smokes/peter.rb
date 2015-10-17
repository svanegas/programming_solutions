# Santiago Vanegas Gil
while line = gets
  n = line.split[0].to_i
  k = line.split[1].to_i
  ans = n
  while n >= k
    ans += n / k
    n = n / k + n % k
  end
  puts ans
end
