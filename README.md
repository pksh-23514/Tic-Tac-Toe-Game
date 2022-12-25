# Tic-Tac-Toe-Game

## Introduction:
Tic-tac-toe Project is a noughts and crosses (or Xs and Os) paper-and-pencil game for single or double players. Two players representing "X" and "O" respectively will take turns marking the spaces in a 3 × 3 grid. The player who succeeds in placing Three of their marks in a Diagonal, Horizontal or Vertical fashion is the Winner.
## Minimax Algorithm in Game Theory:
Minimax is a kind of Back-Tracking algorithm that is used in decision making and game theory to find the optimal move for a player, assuming that your opponent also plays optimally. It is widely used in two player turn-based games such as Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.<br>
In Minimax the two Players are called Maximizer and Minimizer. The Maximizer tries to get the highest score possible while the Minimizer tries to do the opposite and get the lowest score possible. Every Board state has a value associated with it. In a given State, if the Maximizer has upper hand then, the score of the board will tend to be some Positive value. If the Minimizer has the upper hand in that board state then it will tend to be some Negative value. The values of the board are calculated by some heuristics which are unique for every type of game.
## Requirements:
The Game can be played in 2 Modes:<br>
1. **Single Player** - In this Mode, the Player shall play the Game with the Computer. The moves taken by the Computer are calculated optimally using the Minimax algorithm.
2. **Double Player** - In this Mode, 2 Players shall play the Game with each other. Each of them will be asked to play their chance and based on the Moves played, they will win, lose or draw.
## Steps to Play the Game:
1. The Game can be played by 2 Players : either one User and Computer or two Users.
2. Each Player can take Turns to Play the Game.
3. Player can enter the Cell position on the Grid to make a Move.
4. One Player gets "X" and other Player "O".
5. On each Move, the Game status is checked.
6. If a Player Wins, the Game Ends and the Winner status is displayed.
7. The Game can also end in a Draw.
8. After the Game Ends, a New Game shall Start and the process shall continue till the User chooses the option to Exit.

![image](https://user-images.githubusercontent.com/108017134/209459667-01a93ea6-c6c5-4a68-af8e-dafd64d06790.png)
