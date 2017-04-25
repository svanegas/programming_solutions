def build_letters
    sizes = [3, 3, 3, 3, 3, 4, 3, 4]
    letters = Array.new(10) { Array.new }
    cur_letter = 'a'
    cur_number = 2
    sizes.each do |size|
        size.times do
            letters[cur_number].push(cur_letter)
            cur_letter = cur_letter.next
        end
        cur_number = cur_number.next
    end
    letters
end

def solve(letters, numbers, index, cur_combination)
    response = []
    return response.push(cur_combination) if index == numbers.count
    letters[numbers[index]].each do |letter|
        next_combination = cur_combination + letter
        response.concat(solve(letters, numbers, index + 1, next_combination))
    end
    response
end

def pressingButtons(buttons)
    numbers = buttons.split("").map(&:to_i)
    numbers.empty? ? [] : solve(build_letters, numbers, 0, "")
end
