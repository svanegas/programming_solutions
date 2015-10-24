# Implementación de solución para 'Code Camp for Girls'
# Enunciado: https://www.hackerrank.com/contests/womenscup/challenges/coding-camp-for-girls
# Algoritmo (Diego Montoya): https://gist.github.com/dmonto3/4fc0301ba7f7fdb14f5b
n, m = gets.split.map(&:to_i)
ranges = []  # Se almacenarán los rangos leídos acá.
graph = []   # Lista de adyacencia, una conexión u -> v representa que u es un círculo interno de v.
inverse = [] # Lista de adyacencia, una conexión u -> v representa que u es un círculo externo de v.
m.times do   # Se leen los rangos.
  ranges.push(gets.split.map(&:to_i))
  graph.push([])   # Se inicializa la lista vacía en el índice actual.
  inverse.push([]) # Se inicializa la lista vacía en el índice actual.
end
ranges.each_with_index do |u, i|  # O(m ^ 2)
  ranges.each_with_index do |v, j|
    if u[0] > v[0] && u[1] < v[1] # Inserto una conexión de u a v en las respectivas listas de
                                  # adyacencia.
      graph[i].push(j)            # u (índice i) es círculo interno de v (índice j).
      inverse[j].push(i)          # v (índice j) es círculo externo de u (índice i).
    end
  end
end
marks = Array.new(n, 0) # Inicializar el arreglo de marcas con puros 0's. (Círculos más externos van
                        # a ser representados con 0)
graph.each_with_index do |g, i|
  if g.empty?  # Si el rango actual no es interno de nadie (es externo).
    queue = [] # Voy a poner todos los rangos internos a mí en una cola que guarda parejas, donde
               # el primer elemento es el índice del rango que voy a revisar, y el segundo elemento
               # es el número con el que tengo que marcar ese rango.
    inverse[i].each { |inner| queue.push([inner, 1]) } # Acordémonos que 'inverse' tiene todos los
                                                       # círculos internos de un determinado índice.
    until queue.empty?        # BFS <3.
      item = queue.shift      # Siguiente de la cola.
      cur = ranges[item[0]]   # Rango actual lo tomo de la lista de rangos con el índice que saqué
                              # de la cola.
      mark = item[1]          # La marca que tengo que ponerle está en el segundo elemento de la
                              # parjea.
      marks.fill(mark, cur[0]-1..cur[1]-1) # Relleno con la marca, todos los elementos del rango.
      inverse[item[0]].each { |inner| queue.push([inner, mark + 1]) } # Para cada uno de los
                                                                      # siguientes círculos internos
                                                                      # a mí (mis vecinos), los meto
                                                                      # a la cola. Les digo que se
                                                                      # tienen que marcar con +1 a
                                                                      # mí.
    end
  end
end
ans = []        # Vamos a guardar todos los strongs pairs acá.
for i in 1..n-1 # Recorremos todas las marcas.
  ans.push([i, i + 1]) if (marks[i] - marks[i - 1]).abs == 1 # Si la diferencia entre el elemento
                                                             # anterior y yo es 1, somos strong
                                                             # pair.
end
puts ans.count                              # Cuántas parejas hay.
ans.each { |strong| puts strong.join(' ') } # Imprimimos cada pareja.
