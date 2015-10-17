# Santiago Vanegas Gil
require 'set'

t = gets.strip.to_i
t.times do
  recording = gets.strip.split
  sounds = Set.new
  goes = gets.strip
  while goes != "what does the fox say?"
    sounds.add(goes.split[2])
    goes = gets.strip
  end
  recording.delete_if { |rec| sounds.include?(rec) }
  puts "#{recording.join(' ')}"
end
