# Santiago Vanegas Gil
t = gets.to_i
t.times do
  n = gets.to_i
  ans = 0
  n.times do
    x, y = gets.strip.split.map { |coord| coord.to_i }
    dist = x * x + y * y
    (20..200).step(20) do |i|
      if dist <= i * i
        ans += (11 - i / 20)
        break
      end
    end
  end
  puts "#{ans}"
end
