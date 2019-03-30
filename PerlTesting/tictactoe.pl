#!/usr/bin/perl
use strict;
use warnings;

# Create the game board

my @board = qw/_ _ _ _ _ _ _ _ _/;

print "
 _____
|$board[0]|$board[1]|$board[2]|
|$board[3]|$board[4]|$board[5]|
|$board[6]|$board[7]|$board[8]|
";

# Create a variable to store who the winner is
my $winner = "Cat";

# A subroutine to clear the screen
sub cls()
{
	system $^O eq 'MSWin32' ? 'cls' : 'clear';
}

# Print directions for the user

print "Please type one of the numbers for each of your moves.\n";
print " 1 2 3
 4 5 6
 7 8 9.\n";

# Use a for loop, and loop through 9 moves for the game

for (my $i = 0; $i < 9; $i++)
{
		
	
 #create a player variable, and using % 2, assign it as X or O
 
 my $player = "";
 
 if ($i % 2)
	 {
	 	$player = "O";
	 }
	 
 	else 
 	{
 		$player = "X";
 	}

	# Using a while loop, get the player's move and make sure it is valid
	my $input = 0;
	my $error = "";

	while ($input < 1 || $input > 9)
	{
		print  $error;
		print "Enter your play.\n";
		$input = <STDIN>;
		chomp $input;
		$error = "Invalid move.\n";
	}
	
	$input = $input -1;
	if ($board[$input] ne 'X' and $board[$input] ne 'O')
	{
		$board[$input] = $player;
	} 
	else 
	{
		$i--;
		print "Play is already selected.";
	}
		
		
	# If this is move 5+, check for a winner
	if ($i > 4)
	{
		
	}
			
	 if ($board[0] ne "_" and $board[1] eq $board[2] and $board[0] eq $board[2])
	{
		print "$player Wins";
	}
	
	elsif ($board[3] ne "_" and $board[4] eq $board[5] and $board[3] eq $board[5])
	{
		print "$player Wins";
	}
		
	elsif ($board[6] ne "_" and $board[7] eq $board[8] and $board[6] eq $board[8])
	{
		print "$player Wins";
	}
	
	elsif ($board[0] ne "_" and $board[3] eq $board[6] and $board[0] eq $board[6])
	{
		print "$player Wins";
	}
	
	elsif ($board[1] ne "_" and $board[4] eq $board[7] and $board[1] eq $board[7])
	{
		print "$player Wins";
	}
	
	elsif ($board[2] ne "_" and $board[5] eq $board[8] and $board[2] eq $board[8])
	{
		print "$player Wins";
	}
	
	elsif ($board[0] ne "_" and $board[4] eq $board[8] and $board[0] eq $board[8])
	{
		print "$player Wins";
	}
	
	elsif ($board[6] ne "_" and $board[4] eq $board[2] and $board[6] eq $board[2])
	{
		print "$player Wins";
	}
	
	cls();
	print "
 _____
|$board[0]|$board[1]|$board[2]|
|$board[3]|$board[4]|$board[5]|
|$board[6]|$board[7]|$board[8]|
";
}