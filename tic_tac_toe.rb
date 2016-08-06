class TicTacToe2
  def initialize(player1,player2,board)
    @player1 = player1
    @player2 = player2
    @board = board
    @winChecker = WinChecker.new(board)
  end
  def game
    # @board.display_board
    @result = "running"
    @turn = 0
    start
  end
  def start
    print "World Tic-Tac-Toe championship\nAnd the final match is between\n#{@player1.name.upcase} i.e. X and #{@player2.name.upcase} i.e O \n"
    while @turn < (@board.size * @board.size) && @result == "running"
      pos = input
      @turn.even? ? @board.mark_my_postion('X',pos[0],pos[1]) : @board.mark_my_postion('O',pos[0],pos[1])
      @turn += 1
      @result = @winChecker.check_for_win  #check_for_win       #(pos)
      if @result == 'X'
        print "And the winner of the match is #{@player1.name}\n"
      elsif @result == 'O'
         print "And the winner of the match is #{@player2.name}\n"
       end
    end
    print "\nMatch Draw\n" if @result == "running"
  end

  def input
    @board.display_board
    if @turn.even?
      p "#{@player1.name}'s turn : [X] : Input format ColumnRow. eg: a1,b3,c2 "
    else
      p "#{@player2.name}'s turn : [O]: Input format ColumnRow. eg: a1,b3,c2 "
    end
    begin
      position = gets.chomp
      c,r = position.upcase.split('')
      if (position.length == 2 && c.ord.between?(65,(65 + @board.size)) && r.to_i.between?(1,@board.size))
      else
        raise "\nWrong input format. Try again"
      end
    rescue => msg
      print "#{msg}\n"
      retry
    end
    col = (c.ord - 65)
    row = (r.to_i - 1)
    return [row,col]
  end
end#class end

class WinChecker
  def initialize(board)
    @board = board
  end
  def check_for_win
    x = horizontal
    return x if x
    x = vertical
    return x if x
    x = diagonal
    return x if x
    "running"
  end
  def horizontal
    @board.board.each_with_index do |row,idx|
      val = row[0]
      return row[0] if (row.all? { |e| e == val } && row[0] != '-' )
    end
    nil
  end
  def vertical
    @board.board.transpose.each_with_index do |row,idx|
      val = row[0]
      return row[0] if (row.all? { |e| e == val } && row[0] != '-' )
    end
    nil
  end
  def diagonal
    dia = Array.new(@board.size,"")
    #0,0 : 1,1 : ..
    dia = (0...@board.size).collect {|i| @board.board[i][i]}
    return dia[0] if (dia.all? { |e| e == dia[0] } && dia[0] != '-' )
    #0,n : 1,n-1 ..
    dia = (0...@board.size).collect {|i| @board.board.reverse[i][i]}
    return dia[0] if (dia.all? { |e| e == dia[0] } && dia[0] != '-' )
    nil
  end
end #class end

class Board
  attr_accessor :board
  attr_reader :size
  def initialize(size)
    @board = Array.new(size){Array.new(size,default = '-')}
    @size = size
  end

  def display_board
    row_number = 0
    puts "Current status of board is : "
    @size.times.inject(65){|total,x| print  "\t",total.chr;total+=1} # 4 spaces
    puts ""
    @board.each do |row|
      print "#{row_number += 1}\t"
      row.each {|elem| print elem,"\t"}
      puts ''
    end
  end

  def mark_my_postion(mark,row,col)
    if @board[row][col] == '-'
      @board[row][col] = mark
      # @turn += 1
    else
      print "\nThis position is marked by your enemy. Try another 'Winning' strategy.\n"
    end
  end

end #class end


class Player
  attr_reader :name
  attr_writer :moves
  def initialize(name)
    @name = name
    @moves = 0
  end
end#class end

if __FILE__ == $0
  player1 = Player.new("Bhushan")
  player2 = Player.new("Roshan")
  size = 5
  board = Board.new(size)
  game = TicTacToe2.new(player1,player2,board)
  game.game
end
