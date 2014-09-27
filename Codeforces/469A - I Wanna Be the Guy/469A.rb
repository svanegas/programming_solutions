n = gets.chomp.to_i
p = gets.chomp.split(" ").map(&:to_i)
q = gets.chomp.split(" ").map(&:to_i)
p.delete_at(0)
q.delete_at(0)
res = p | q
puts res.size == n ? "I become the guy." : "Oh, my keyboard!"
