#! /usr/bin/ruby

class TicTacToe
  def initialize(player1,player2)
    @board =[['_','_','_'],['_','_','_'],['_','_','_']]
    @player1 = player1
    @player2 = player2
  end

  def mark_my_postion(mark,row,col)
    if @board[row][col] == '_'
      @board[row][col] = mark
      @turn += 1
    else
      print "\nThis position is marked by your enemy. Try another 'Winning' strategy.\n"
      input
    end
  end

  def game
    # @match = "running"
    @result = "running"
    @turn = 0
    start
  end

  def start
    print "World Tic-Tac-Toe championship\n And the final match is between\n#{@player1.name.upcase} i.e. X and #{@player2.name.upcase} i.e O \n"
    while @turn < 9 && @result == "running"
      # print "@turn #{@turn}\n"
      pos = input
      @turn.even? ? mark_my_postion('X',pos[0],pos[1]) : mark_my_postion('O',pos[0],pos[1])
      # display_board
      @result = check_for_win #(pos)
      print "And the winner is #{@result.upcase}\n"
    end
    print "\nMatch Draw\n" if @result == "runiing"
  end

  def input
    display_board
    if @turn.even?
      p "#{@player1.name}'s turn : [X] : Input format ColumnRow. eg: a1,b3,c2 "
    else
      p "#{@player2.name}'s turn : [O]: Input format ColumnRow. eg: a1,b3,c2 "
    end
    begin
      position = gets.chomp
      c,r = position.upcase.split('')
      if (position.length == 2) && (c == "A" || c == "B" || c =="C") && (r == "1" || r == "2" || r == "3")
      else
        raise "\nWrong input format. Try again"
      end
    rescue => msg
      print "#{msg}\n"
      retry
    end

    col =
      case c
      when "A" then 0
      when "B" then 1
      when "C" then 2
      end
    row =
      case r
      when "1" then 0
      when "2" then 1
      when "3" then 2
      end

      return [row,col]
  end

  def display_board
    row_number = 0
    puts "Current status of board is : "
    print "    A    B    C\n"
    @board.each do |row|
      print "#{row_number += 1} "
      p row
    end
  end

  def check_for_win #(pos)
    #horizontal first row
    if    (((@board[0][0] != '_') && (@board[0][0]==@board[0][1]&&@board[0][2]==@board[0][0])) && @board[0][0] == 'X')
      return @player1.name
    elsif (((@board[0][0] != '_') && (@board[0][0]==@board[0][1]&&@board[0][2]==@board[0][0])) && @board[0][0] == 'O')
      return @player2.name
    #vertical first column
    elsif (((@board[0][0] != '_') && (@board[0][0]==@board[1][0]&&@board[2][0]==@board[0][0])) && @board[0][0] == 'X')
      return @player1.name
    elsif (((@board[0][0] != '_') && (@board[0][0]==@board[1][0]&&@board[2][0]==@board[0][0])) && @board[0][0] == 'O')
      return @player2.name
    #diagonal from top left to bottom right
    elsif (((@board[0][0] != '_') && (@board[0][0]==@board[1][1]&&@board[2][2]==@board[0][0])) && @board[0][0] == 'X')
      return @player1.name
    elsif (((@board[0][0] != '_') && (@board[0][0]==@board[1][1]&&@board[2][2]==@board[0][0])) && @board[0][0] == 'O')
      return @player2.name
    #horizontal second row
    elsif (((@board[1][0] != '_') && (@board[1][0]==@board[1][1]&&@board[1][2]==@board[1][0])) && @board[1][0] == 'X')
      return @player1.name
    elsif (((@board[1][0] != '_') && (@board[1][0]==@board[1][1]&&@board[1][2]==@board[1][0])) && @board[1][0] == 'O')
      return @player2.name
    #horizontal third row
    elsif (((@board[2][0] != '_') && (@board[2][0]==@board[2][1]&&@board[2][2]==@board[2][0])) && @board[2][0] == 'X')
      return @player1.name
    elsif (((@board[2][0] != '_') && (@board[2][0]==@board[2][1]&&@board[2][2]==@board[2][0])) && @board[2][0] == 'O')
      return @player2.name
    #vertical second column
    elsif (((@board[0][1] != '_') && (@board[0][1]==@board[1][1]&&@board[0][1]==@board[2][1])) && @board[0][1] == 'X')
      return @player1.name
    elsif (((@board[0][1] != '_') && (@board[0][1]==@board[1][1]&&@board[0][1]==@board[2][1])) && @board[0][1] == 'O')
      return @player2.name
    #vertical third column
    elsif (((@board[0][2] != '_') && (@board[0][2]==@board[1][2]&&@board[2][2]==@board[0][2])) && @board[0][2] == 'X')
      return @player1.name
    elsif (((@board[0][2] != '_') && (@board[0][2]==@board[1][2]&&@board[2][2]==@board[0][2])) && @board[0][2] == 'O')
      return @player2.name
    #diagonal top right to bottom left
    elsif (((@board[0][2] != '_') && (@board[0][2]==@board[1][1]&&@board[0][2]==@board[2][0])) && @board[0][2] == 'X')
      return @player1.name
    elsif (((@board[0][2] != '_') && (@board[0][2]==@board[1][1]&&@board[0][2]==@board[2][0])) && @board[0][2] == 'O')
      return @player2.name
    end

    return "running"
  end
end
class Player
  attr_reader :name
  attr_writer :moves
  def initialize(name)
    @name = name
    @moves = 0
  end
end

if __FILE__ == $0
  player1 = Player.new("Bhushan")
  player2 = Player.new("Roshan")
  game = TicTacToe.new(player1,player2)
  game.game
end
