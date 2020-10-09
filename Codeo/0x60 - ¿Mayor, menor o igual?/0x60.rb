a, b = gets.chomp.split.map(&:to_i)
if a < b
  puts "<"
elsif a > b
  puts ">"
else
  puts "="
end
