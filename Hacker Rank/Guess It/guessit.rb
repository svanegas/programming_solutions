# Santiago Vanegas Gil
gets.to_i.times do
  sum = 0
  gets.strip.split("").each do |char|
   sum += char.to_i if char != "_"
   sum %= 9
  end
  puts "#{9 - sum}" unless sum == 0
  puts "0 or 9" if sum == 0
end
